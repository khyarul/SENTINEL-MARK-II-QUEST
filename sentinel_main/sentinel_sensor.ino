void led_DIM() {
  while (1) {
    for (uint8_t j = 0; j < 255; j++) {
      analogWrite(PB1, j);
      analogWrite(led, j);
      if (!BACK) {
        break;
      }
      delay(1);
    }
    for (uint8_t j = 255; j > 0; j--) {
      analogWrite(PB1, j);
      analogWrite(led, j);
      if (!BACK) {
        break;
      }
      delay(1);
    }
    if (!BACK) {
      pinMode(PB1, OUTPUT);
      digitalWrite(PB1, 0);
      pinMode(led, OUTPUT);
      led_ON;
      lcd.clear();
      while (!BACK) {
        delay(50);
      }
      break;
    }
  }
}

uint16_t readSensor() {
  for (int8_t i = 0; i <= 6; i++) {
    switchSensor(i);
    delayMicroseconds(20);
    arraySensor[i] = analogRead(sensorR);//adcSensor[0];
    if (arraySensor[i] > ee.sensorRef[i]) {
      bitSet(bitSensor, i);//bitSensor = bitSensor | (0b00000000000001 << i);
    }
    else {
      bitClear(bitSensor, i);
    }
    arraySensor[13 - i] = analogRead(sensorL);//adcSensor[1];
    if (arraySensor[13 - i] > ee.sensorRef[13 - i]) {
      bitSet(bitSensor, 13 - i); //bitSensor = bitSensor | (0b00000000000001 << (13 - i));
    }
    else {
      bitClear(bitSensor, 13 - i);
    }
  }
  //  else if (line == WHT) {
  //    for (int8_t i = 0; i <= 6; i++) {
  //      switchSensor(i);
  //      delayMicroseconds(20);
  //      arraySensor[i] = analogRead(sensorR);//adcSensor[0];
  //      if (arraySensor[i] > ee.sensorRef[i]) {
  //        bitClear(bitSensor, i);
  //      }
  //      else {
  //        bitSet(bitSensor, i);//bitSensor = bitSensor | (0b00000000000001 << i);
  //      }
  //      arraySensor[13 - i] = analogRead(sensorL);//adcSensor[1];
  //      if (arraySensor[13 - i] > ee.sensorRef[13 - i]) {
  //        bitClear(bitSensor, 13 - i);
  //      }
  //      else {
  //        bitSet(bitSensor, 13 - i); //bitSensor = bitSensor | (0b00000000000001 << (13 - i));
  //      }
  //    }
  //  }
  if (line == WHT) {
    bitSensor = ~bitSensor;
  }
  return bitSensor;
}

void switchSensor(uint8_t muxSensor) {
  digitalWrite(PA1, (muxSensor & 1));
  digitalWrite(PA2, (muxSensor & 2));
  digitalWrite(PA3, (muxSensor & 4));
}

void calibration() {
  led_ON;
  uint8_t i;
  int16_t lRef[14], hRef[14];
  for (int8_t i = 0; i <= 13; i++) {
    lRef[i] = 4095;
    hRef[i] = 0;
  }
  lcd.clear();
  choose(0); lcd.drawString(0, 3, " Calibrating... "); lcd.drawString(0, 4, "Sensitivity:"); lcd.drawString(15, 4, "%");
  choose(1); lcd.drawString(0, 7, "Save"); lcd.drawString(10, 7, "Cancel");
  delay(200);
  while (1) {
    for (int8_t i = 0; i <= 6; i++) {
      switchSensor(i);
      delayMicroseconds(20);
      arraySensor[i] = analogRead(sensorR);//adcSensor[0];
      if (arraySensor[i] > hRef[i]) {
        hRef[i] = arraySensor[i];
      }
      if (arraySensor[i] < lRef[i]) {
        lRef[i] = arraySensor[i];
      }
      arraySensor[13 - i] = analogRead(sensorL);//adcSensor[1];
      if (arraySensor[13 - i] > hRef[13 - i]) {
        hRef[13 - i] = arraySensor[13 - i];
      }
      if (arraySensor[13 - i] < lRef[13 - i]) {
        lRef[13 - i] = arraySensor[13 - i];
      }
    }
    if (!PLUS) {
      if (++ee.sensitivity > 50) ee.sensitivity = 50;
      delay(100);
    }
    if (!MIN) {
      if (--ee.sensitivity < -50) ee.sensitivity = -50;
      delay(100);
    }
    sprintf(buff, "%3d", ee.sensitivity);
    lcd.drawString(12, 4, buff);
    if (!BACK) {
      led_OFF;
      lcd.clear();
      choose(0);
      lcd.draw1x2String(0, 3, "    CANCELED    ");
      goto cancel;
    }
    if (!OK) {
      led_OFF;
      break;
    }
  }
  for (int8_t i = 0; i <= 13; i++) {
    ee.sensorRef[i] = (hRef[i] - lRef[i]) / 2 + lRef[i];
    ee.sensorRef[i] = ee.sensorRef[i] - (ee.sensorRef[i] * ee.sensitivity / 100);
  }
  lcd.clear();
  choose(0);
  lcd.draw1x2String(0, 3, "      DONE      ");
cancel:
  switch (7);
  delay(500);
  lcd.clear();
}

void readSensorAdc() {
  for (int8_t i = 0; i <= 6; i++) {
    switchSensor(i);
    delayMicroseconds(20);
    arraySensor[i] = analogRead(sensorR);//adcSensor[0];
    arraySensor[13 - i] = analogRead(sensorL);//adcSensor[1];
  }
}

void initSensor() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
}
