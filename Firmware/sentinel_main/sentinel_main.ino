/*
  UP    : PB15
  DOWN  : PB14
  +     : PC15
  -     : PC14
  Enter : PB13
  Back  : PC13

  SDA   : PB11
  SCL   : PB10
  Tx1   : PA9
  Rx1   : PA10

  LED   : PB1
  Batt  : PB0
  LED_sensor  : PA0
  S1    : PA1
  S2    : PA2
  S3    : PA3
  AIN1  : PA4
  AIN2  : PA5

  DIRL  : PB5
  PWML  : PB6
  PWMR  : PB7
  DIRR  : PB8

  ENC1_R: PB4
  ENC2_R: PB3
  ENC1_L: PA15
  ENC2_L: PA14

  SERVO1: PA6
  SERVO2: PA7
  Ext   : PA8
*/

#include <Wire.h>
#include <U8x8lib.h>
#include <extEEPROM.h>
#include <Servo.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C lcd(U8X8_PIN_NONE);
extEEPROM EE(kbits_256, 1, 64);
Servo servoL, servoR;

#define MAXPLAN 4

struct extEE {
  int8_t ACTION[MAXPLAN][100];
  int8_t SENSOR[MAXPLAN][100];
  int8_t RSPEED[MAXPLAN][100];
  int8_t LSPEED[MAXPLAN][100];
  int8_t COUNTERMODE[MAXPLAN][100];
  int16_t COUNTER[MAXPLAN][100];
  int8_t VA[MAXPLAN][100];
  int16_t COUNTA[MAXPLAN][100];
  int8_t COUNTERAMODE[MAXPLAN][100];
  int8_t VB[MAXPLAN][100];
  int16_t COUNTB[MAXPLAN][100];
  int8_t COUNTERBMODE[MAXPLAN][100];
  int8_t pid[MAXPLAN][100];
  int8_t FOLLOWMODE[MAXPLAN][100];
  int8_t JUMP[MAXPLAN][100];
  int8_t jumpP[MAXPLAN][100];
  int8_t jumpI[MAXPLAN][100];
  int8_t PLAN;
  int8_t I;
  int8_t STOP[MAXPLAN];
  int8_t CP[10];
  int8_t CPI;
  int8_t Va[10];
  uint8_t Ta[10];
  uint16_t sensorRef[14];
  uint8_t V;
  int8_t PID;
  uint8_t kp[3], kd[3];
  int8_t Vmin, Vmax;
  uint8_t Ts;
  int8_t LINE;
  int8_t sensitivity;
  uint8_t SV1[2], SV2[2];
  int16_t Dly;
} ee;

void eeRead() {
  byte *p = (byte*)(void*)&ee;
  EE.read(0, p, sizeof(ee));
}

void eeWrite() {
  byte *p = (byte*)(void*)&ee;
  EE.write(0, p, sizeof(ee));
}

//Button
#define OK digitalRead(PB13)
#define UP digitalRead(PB15)
#define DOWN digitalRead(PB14)
#define BACK digitalRead(PC13)
#define PLUS digitalRead(PC15)
#define MIN digitalRead(PC14)

//Motor Driver
//HardwareTimer timer(1);
#define pwmL PB6
#define pwmR PB7
#define dirL PB5
#define dirR PB8
//int16_t speedL = 0, speedR = 0;
int16_t error = 0, lastError = 0;
uint32_t lastTime = 0;

//Servo
//#define servoR 5
//#define servoL 4

//Motor Encoder
int8_t last_en1L, last_en1R;
volatile int32_t rPos;
volatile int32_t lPos;
#define RPOS rPos/5
#define LPOS lPos/5

//Sensor
#define led_ON digitalWrite(led, 1)
#define led_OFF digitalWrite(led, 0)
#define led PA0
#define sensorL PA5
#define sensorR PA4
#define A PA1
#define B PA2
#define C PA3
//uint8_t pinSensor[3] = {PA5, PA4, PB0};
uint16_t arraySensor[14], adcSensor[3];
int8_t sensor_logic = 0;
uint16_t bitSensor = 0;
uint16_t sensor1 = 0, sensor2 = 0;

//Battery Indicator
#define batt PB0

//Navigation Mode
#define BLK 0
#define WHT 1
#define RGT 2
#define LFT 3
#define FWD 4
#define BWD 5
#define PICK 6
#define DROP 7
#define BLOW 8

#define NONE 0
#define DIRECT 1
#define EQ 2
#define OR 3
#define XOR 4

#define TIMER 0
#define ENCODERR 1
#define ENCODERL 2

#define FLC 0
#define FLR 1
#define FLL 2

#define off 0
#define on 1
int8_t line;
//=================

uint8_t bar[8][8] PROGMEM = {{0, 128, 128, 128, 128, 128, 128, 0}, {0, 192, 192, 192, 192, 192, 192, 0},
  {0, 224, 224, 224, 224, 224, 224, 0}, {0, 240, 240, 240, 240, 240, 240, 0},
  {0, 248, 248, 248, 248, 248, 248, 0}, {0, 252, 252, 252, 252, 252, 252, 0},
  {0, 254, 254, 254, 254, 254, 254, 0}, {0, 255, 255, 255, 255, 255, 255, 0}
};
uint8_t bat[6][8] PROGMEM = {{254, 130, 131, 131, 131, 131, 130, 254}, {254, 194, 195, 195, 195, 195, 194, 254},
  {254, 226, 227, 227, 227, 227, 226, 254}, {254, 242, 243, 243, 243, 243, 242, 254},
  {254, 250, 251, 251, 251, 251, 250, 254}, {254, 254, 255, 255, 255, 255, 254, 254}
};
uint8_t checked[8] PROGMEM = {255, 129, 189, 189, 189, 189, 129, 255};
uint8_t uncheck[8] PROGMEM = {255, 129, 129, 129, 129, 129, 129, 255};
uint8_t savedata[8] PROGMEM = {31, 123, 115, 96, 96, 115, 123, 31};
uint8_t zzzz[8] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 255};
uint8_t zzzzz[8] PROGMEM = {6, 6, 6, 6, 6, 6, 6, 6};
char buff[16];
int8_t idx = 4;

void setup() {
  analogReadResolution(12);
  initEncoder();

  initMotor();
  setMotor(0, 0);

  initButton();

  pinMode(led, OUTPUT);
  led_ON;

  initSensor();
  switchSensor(0);

  Wire.setSDA(PB11);
  Wire.setSCL(PB10);
  lcd.begin();
  lcd.setPowerSave(0);
  lcd.setFlipMode(1);
  lcd.setFont(u8x8_font_chroma48medium8_r);

  rPos = 0;
  lPos = 0;
  EE.begin(EE.twiClock400kHz);
  eeRead();
  if (!OK) {
    if (!BACK) {
      for (int8_t i = 0; i < MAXPLAN; i++) {
        for (int8_t j = 0; j < 100; j++) {
          ee.ACTION[i][j] = 0;
          ee.SENSOR[i][j] = 0;
          ee.RSPEED[i][j] = 0;
          ee.LSPEED[i][j] = 0;
          ee.COUNTERMODE[i][j] = TIMER;
          ee.COUNTER[i][j] = 0;
          ee.VA[i][j] = 50;
          ee.COUNTA[i][j] = 0;
          ee.COUNTERAMODE[i][j] = TIMER;
          ee.VB[i][j] = 50;
          ee.COUNTB[i][j] = 0;
          ee.COUNTERBMODE[i][j] = TIMER;
          ee.pid[i][j] = 2;
          ee.FOLLOWMODE[i][j] = FLC;
          ee.JUMP[i][j] = off;
          ee.jumpP[i][j] = 0;
          ee.jumpI[i][j] = 0;
          ee.STOP[i] = 99;
        }
      }
      for (int8_t i = 0; i < 10; i++) {
        ee.CP[i] = 0;
        ee.Va[i] = 0;
        ee.Ta[i] = 0;
      }
      ee.kp[0] = 10;   //14, 19, 27
      ee.kd[0] = 20;  //130, 140, 155
      ee.kp[1] = 13;
      ee.kd[1] = 25;
      ee.kp[2] = 20;
      ee.kd[2] = 50;
      ee.PID = 2;
      ee.V = 40;
      ee.Vmin = -70, ee.Vmax = 100;
      ee.Ts = 5;
      ee.PLAN = 0;
      ee.I = 0;
      ee.CPI = 0;
      ee.LINE = BLK;
      ee.sensitivity = 0;
      ee.SV1[0] = 90;
      ee.SV2[0] = 90;
      ee.SV1[1] = 90;
      ee.SV2[1] = 90;
      ee.Dly = 500;
      lcd.draw1x2String(0, 2, " FORMATTING...  ");
      eeWrite();
      eeRead();
      lcd.clear();
    }
  }
  servoR.attach(PA6);
  servoL.attach(PA7);
  servoR.write(ee.SV1[0]);
  servoL.write(ee.SV2[0]);
  lcd.clear();
}

void loop() {
  if (!OK) {
    switch (7);
    menu();
    choose(0);
    led_ON;
    idx = 4;
  }

  if (!BACK) {
    led_OFF;
    lcd.clear();
    while (!BACK) {
      delay(100);
    }
    led_ON;
    lastError = 0;
    lastTime = 0;
    line = ee.LINE;
    int8_t plan = ee.PLAN;
    int8_t x = ee.CP[ee.CPI];
    int8_t berhenti = off;
    uint32_t count_now, stop_time;
    uint32_t start_time = millis();
    if (ee.Ta[ee.CPI] > 0) {
      count_now = millis();
      while (millis() - count_now < (ee.Ta[ee.CPI] * 50)) {
        flc(ee.Va[ee.CPI], ee.PID);
      }
    }
    int8_t get_index = 0;
    uint16_t sensor_1 = 0, sensor_2 = 0;
    while (1) {
      get_index = 0;
      sensor_1 = 0, sensor_2 = 0;
      sensor_list(plan, x);
      switch (sensor_logic) {
        case NONE:
          flc(ee.V, ee.PID);
          get_index = 0;
          break;
        case DIRECT:
          if (ee.I == 0) {
            flc(ee.V, ee.PID);
          }
          get_index = 1;
          break;
        case EQ:
          flc(ee.V, ee.PID);
          bitSensor = readSensor();
          if (bitSensor == sensor1) {
            get_index = 1;
          }
          //          else {
          //            flc(ee.V, ee.PID);
          //          }
          break;
        case OR:
          flc(ee.V, ee.PID);
          bitSensor = readSensor();
          sensor_1 = bitSensor & sensor1;
          if (sensor_1 > 0) {
            get_index = 1;
          }
          //          else {
          //            flc(ee.V, ee.PID);
          //          }
          break;
        case XOR:
          flc(ee.V, ee.PID);
          bitSensor = readSensor();
          sensor_1 = bitSensor & sensor1;
          sensor_2 = bitSensor & sensor2;
          if (sensor_1 > 0 && sensor_2 > 0) {
            get_index = 1;
          }
          //          else {
          //            flc(ee.V, ee.PID);
          //          }
          break;
      }

      if (get_index == 1) {
        setMotor(0, 0);
        led_OFF;
        int16_t VL = map(ee.LSPEED[plan][x], -100, 100, -255, 255);
        int16_t VR = map(ee.RSPEED[plan][x], -100, 100, -255, 255);
        setMotor(VL, VR);
        switch (ee.ACTION[plan][x]) {
          case PICK: servoL.write(ee.SV2[0]); delay(ee.Dly); servoR.write(ee.SV1[0]); break;
          case DROP: servoR.write(ee.SV1[1]); delay(ee.Dly); servoL.write(ee.SV2[1]); break;
        }
        switch (ee.COUNTERMODE[plan][x]) {
          case TIMER:
            count_now = millis();
            while (millis() - count_now < ee.COUNTER[plan][x]) {}
            break;
          case ENCODERR:
            rPos = 0;
            lPos = 0;
            while (RPOS < ee.COUNTER[plan][x]) {}
            break;
          case ENCODERL:
            rPos = 0;
            lPos = 0;
            while (LPOS < ee.COUNTER[plan][x]) {}
            break;
        }
        setMotor(0, 0);
        lastError = 0;
        //        switch (ee.ACTION[plan][x]) {
        //          case BLK: line = BLK; break;
        //          case WHT: line = WHT; break;
        //        }
        line = ee.ACTION[plan][x];

        if (ee.COUNTA[plan][x] > 0) {
          led_ON;
          //bitSensor = 0;
          bitSensor = readSensor();
          //          switch (line) {
          //            case BLK: bitSensor = bitSensor; break;
          //            case WHT: bitSensor = ~bitSensor; break;
          //          }
          if (bitSensor == 0b00000000000000) {
            while (1) {
              setMotor(VL / 8, VR / 8);
              bitSensor = readSensor();
              //              switch (line) {
              //                case BLK: bitSensor = bitSensor; break;
              //                case WHT: bitSensor = ~bitSensor; break;
              //              }
              if (bitSensor != 0b00000000000000) {
                break;
              }
            }
          }

          switch (ee.COUNTERAMODE[plan][x]) {
            case TIMER:
              count_now = millis();
              if (ee.FOLLOWMODE[plan][x] == FLR) {
                while (millis() - count_now < (ee.COUNTA[plan][x] * 50)) {
                  flr(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              else if (ee.FOLLOWMODE[plan][x] == FLL) {
                while (millis() - count_now < (ee.COUNTA[plan][x] * 50)) {
                  fll(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              else {
                while (millis() - count_now < (ee.COUNTA[plan][x] * 50)) {
                  flc(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              break;
            case ENCODERR:
              rPos = 0;
              lPos = 0;
              if (ee.FOLLOWMODE[plan][x] == FLR) {
                while (RPOS < ee.COUNTA[plan][x]) {
                  flr(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              else if (ee.FOLLOWMODE[plan][x] == FLL) {
                while (RPOS < ee.COUNTA[plan][x]) {
                  fll(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              else {
                while (RPOS < ee.COUNTA[plan][x]) {
                  flc(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              break;
            case ENCODERL:
              rPos = 0;
              lPos = 0;
              if (ee.FOLLOWMODE[plan][x] == FLR) {
                while (LPOS < ee.COUNTA[plan][x]) {
                  flr(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              else if (ee.FOLLOWMODE[plan][x] == FLL) {
                while (LPOS < ee.COUNTA[plan][x]) {
                  fll(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              else {
                while (LPOS < ee.COUNTA[plan][x]) {
                  flc(ee.VA[plan][x], ee.pid[plan][x]);
                  if (!BACK) break;
                }
              }
              break;
          }

          if (ee.COUNTB[plan][x] > 0) {
            switch (ee.COUNTERAMODE[plan][x]) {
              case TIMER:
                count_now = millis();
                if (ee.FOLLOWMODE[plan][x] == FLR) {
                  while (millis() - count_now < (ee.COUNTB[plan][x] * 50)) {
                    flr(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                else if (ee.FOLLOWMODE[plan][x] == FLL) {
                  while (millis() - count_now < (ee.COUNTB[plan][x] * 50)) {
                    fll(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                else {
                  while (millis() - count_now < (ee.COUNTB[plan][x] * 50)) {
                    flc(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                break;
              case ENCODERR:
                rPos = 0;
                lPos = 0;
                if (ee.FOLLOWMODE[plan][x] == FLR) {
                  while (RPOS < ee.COUNTB[plan][x]) {
                    flr(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                else if (ee.FOLLOWMODE[plan][x] == FLL) {
                  while (RPOS < ee.COUNTB[plan][x]) {
                    fll(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                else {
                  while (RPOS < ee.COUNTB[plan][x]) {
                    flc(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                break;
              case ENCODERL:
                rPos = 0;
                lPos = 0;
                if (ee.FOLLOWMODE[plan][x] == FLR) {
                  while (LPOS < ee.COUNTB[plan][x]) {
                    flr(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                else if (ee.FOLLOWMODE[plan][x] == FLL) {
                  while (LPOS < ee.COUNTB[plan][x]) {
                    fll(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                else {
                  while (LPOS < ee.COUNTB[plan][x]) {
                    flc(ee.VB[plan][x], ee.pid[plan][x]);
                    if (!BACK) break;
                  }
                }
                break;
            }
          }
        }

        if (ee.JUMP[plan][x] == on) {           //pindah plan & index
          int8_t PNOW = plan;
          int8_t INOW = x;
          plan = ee.jumpP[PNOW][INOW];
          x = ee.jumpI[PNOW][INOW];
        }
        else if (ee.STOP[plan] == x || x == 99 || !BACK) {          //berhenti
          setMotor(0, 0);
          led_OFF;
          break;
        }
        else if (ee.JUMP[plan][x] == off) {     //plan sekarang & index selanjutnya
          x++;
        }
      }
      //      else {
      //        flc(ee.V, ee.PID);
      //      }
      if (!BACK) break;
    }
    setMotor(0, 0);
    led_OFF;
    stop_time = millis();
    uint32_t lap = (stop_time - start_time) / 10;
    float lap_f = float(lap) / 100.0;
    choose(1); lcd.drawString(12, 7, "Home"); choose(0);
    lcd.drawString(0, 3, "Time: ");
    lcd.setCursor(6, 3); lcd.print(lap_f);
    lcd.drawString(12, 3, " sec");
    eeWrite();
    led_DIM();
    //uint32_t prigroup = SCB_BASE->AIRCR & SCB_AIRCR_PRIGROUP;
    //SCB_BASE->AIRCR = SCB_AIRCR_VECTKEY | prigroup;
    //nvic_sys_reset();
  }
  standby();
}

void choose(uint8_t inverse) {
  lcd.setInverseFont(inverse);
}

void flc(uint16_t SPEED, int8_t pd) {
  led_ON;
  bitSensor = readSensor();

  uint32_t NOW = millis();
  uint32_t interval = NOW - lastTime;
  if (interval >= ee.Ts) {
    int8_t errorSensor[14] = { -26, -22, -18, -14, -10, -5, -1, 1, 5, 10, 14, 18, 22, 26};
    int8_t onSensor[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int8_t sumOnSensor = 0;
    for (int8_t i = 0; i < 14; i++) {
      onSensor[i] = bitRead(bitSensor, i);
      sumOnSensor += onSensor[i];
      errorSensor[i] = errorSensor[i] * onSensor[i];
      error += errorSensor[i];
    }
    error = error / sumOnSensor;

    int16_t rateError = error - lastError;
    lastError = error;

    int16_t moveVal = int((error * ee.kp[pd]) + (rateError * ee.kd[pd]));
    SPEED = map(SPEED, 0, 100, 0, 255);
    int16_t moveLeft = SPEED - moveVal;
    int16_t moveRight = SPEED + moveVal;

    int16_t VMAX = map(ee.Vmax, -100, 100, -255, 255);
    int16_t VMIN = map(ee.Vmin, -100, 100, -255, 255);

    moveLeft = constrain(moveLeft, VMIN, VMAX);
    moveRight = constrain(moveRight, VMIN, VMAX);
    setMotor(moveLeft, moveRight);
    lastTime = NOW;
  }
}

void flr(uint16_t SPEED, int8_t pd) {
  led_ON;
  bitSensor = readSensor();
  uint32_t NOW = millis();
  uint32_t interval = NOW - lastTime;
  if (interval >= ee.Ts) {
    int8_t errorSensor[14] = { -46, -42, -38, -34, -30, -26, -22, -18, -14, -10, -5, -1, 1, 5};
    int8_t onSensor[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int8_t sumOnSensor = 0;
    for (int8_t i = 0; i < 14; i++) {
      onSensor[i] = bitRead(bitSensor, i);
      sumOnSensor += onSensor[i];
      errorSensor[i] = errorSensor[i] * onSensor[i];
      error += errorSensor[i];
    }
    error = error / sumOnSensor;

    int16_t rateError = error - lastError;
    lastError = error;

    int16_t moveVal = int((error * ee.kp[pd]) + (rateError * ee.kd[pd]));
    SPEED = map(SPEED, 0, 100, 0, 255);
    int16_t moveLeft = SPEED - moveVal;
    int16_t moveRight = SPEED + moveVal;

    int16_t VMAX = map(ee.Vmax, -100, 100, -255, 255);
    int16_t VMIN = map(ee.Vmin, -100, 100, -255, 255);

    moveLeft = constrain(moveLeft, VMIN, VMAX);
    moveRight = constrain(moveRight, VMIN, VMAX);
    setMotor(moveLeft, moveRight);
    lastTime = NOW;
  }
}

void fll(uint16_t SPEED, int8_t pd) {
  led_ON;
  bitSensor = readSensor();

  uint32_t NOW = millis();
  uint32_t interval = NOW - lastTime;
  if (interval >= ee.Ts) {
    int8_t errorSensor[14] = { -5, -1, 1, 5, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46};
    int8_t onSensor[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int8_t sumOnSensor = 0;
    for (int8_t i = 0; i < 14; i++) {
      onSensor[i] = bitRead(bitSensor, i);
      sumOnSensor += onSensor[i];
      errorSensor[i] = errorSensor[i] * onSensor[i];
      error += errorSensor[i];
    }
    error = error / sumOnSensor;
    int16_t rateError = error - lastError;
    lastError = error;

    int16_t moveVal = int((error * ee.kp[pd]) + (rateError * ee.kd[pd]));
    SPEED = map(SPEED, 0, 100, 0, 255);
    int16_t moveLeft = SPEED - moveVal;
    int16_t moveRight = SPEED + moveVal;

    int16_t VMAX = map(ee.Vmax, -100, 100, -255, 255);
    int16_t VMIN = map(ee.Vmin, -100, 100, -255, 255);

    moveLeft = constrain(moveLeft, VMIN, VMAX);
    moveRight = constrain(moveRight, VMIN, VMAX);
    setMotor(moveLeft, moveRight);
    lastTime = NOW;
  }
}

void sensor_list(int8_t plan, int8_t x) {
  switch (ee.SENSOR[plan][x]) {
    case 0: sensor_logic = NONE; break;

    case 1: sensor_logic = DIRECT; break;

    case 2: sensor1 = 0b00000000000000; sensor_logic = EQ; break;
    case 3: sensor1 = 0b11111111111111; sensor_logic = EQ; break;

    case 4: sensor1 = 0b00000000000001; sensor_logic = OR; break;
    case 5: sensor1 = 0b00000000000011; sensor_logic = OR; break;
    case 6: sensor1 = 0b00000000000111; sensor_logic = OR; break;
    case 7: sensor1 = 0b00000000001111; sensor_logic = OR; break;
    case 8: sensor1 = 0b10000000000000; sensor_logic = OR; break;
    case 9: sensor1 = 0b11000000000000; sensor_logic = OR; break;
    case 10: sensor1 = 0b11100000000000; sensor_logic = OR; break;
    case 11: sensor1 = 0b11110000000000; sensor_logic = OR; break;
    case 12: sensor1 = 0b11111111111111; sensor_logic = OR; break;

    case 13: sensor1 = 0b00000111100000; sensor2 = 0b00000000000001; sensor_logic = XOR; break;
    case 14: sensor1 = 0b00000111100000; sensor2 = 0b00000000000011; sensor_logic = XOR; break;
    case 15: sensor1 = 0b00000111100000; sensor2 = 0b00000000000111; sensor_logic = XOR; break;
    case 16: sensor1 = 0b00000111100000; sensor2 = 0b00000000001111; sensor_logic = XOR; break;
    case 17: sensor1 = 0b00000111100000; sensor2 = 0b10000000000000; sensor_logic = XOR; break;
    case 18: sensor1 = 0b00000111100000; sensor2 = 0b11000000000000; sensor_logic = XOR; break;
    case 19: sensor1 = 0b00000111100000; sensor2 = 0b11100000000000; sensor_logic = XOR; break;
    case 20: sensor1 = 0b00000111100000; sensor2 = 0b11110000000000; sensor_logic = XOR; break;
    case 21: sensor1 = 0b10000000000000; sensor2 = 0b00000000000001; sensor_logic = XOR; break;
    case 22: sensor1 = 0b11000000000000; sensor2 = 0b00000000000011; sensor_logic = XOR; break;
    case 23: sensor1 = 0b11100000000000; sensor2 = 0b00000000000111; sensor_logic = XOR; break;
    case 24: sensor1 = 0b11110000000000; sensor2 = 0b00000000001111; sensor_logic = XOR; break;
    case 25: sensor1 = 0b11111000000000; sensor2 = 0b00000000011111; sensor_logic = XOR; break;
    case 26: sensor1 = 0b11111100000000; sensor2 = 0b00000000111111; sensor_logic = XOR; break;
  }
}
