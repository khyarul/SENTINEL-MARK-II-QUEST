void standby() {
  //  uint8_t bin[14];
  //  uint16_t bitSensor = readSensor();
  //  for (int8_t i = 0; i <= 13; i++) {
  //    bin[i] = bitRead(bitSensor, i);
  //    sprintf(buff, "%1d", bin[i]);
  //    lcd.drawString(14 - i, 2, buff);
  //  }
  readSensorAdc();
  uint16_t highBar[14], showBar[14];
  for (int8_t i = 0; i <= 13; i++) {
    if (arraySensor[i] > ee.sensorRef[i]) {
      highBar[i] = constrain(arraySensor[i], ee.sensorRef[i], 4095);
      showBar[i] = map(highBar[i], ee.sensorRef[i], 4095, 0, 7);
      lcd.drawTile(14 - i, 3, 1, bar[showBar[i]]);
    }
    else {
      lcd.drawString(14 - i, 3, " ");
    }
  }
  //switchSensor(7);
  //  sprintf(buff, "EE:%05d byte", sizeof(ee));
  //  lcd.drawString(0, 0, buff);
  delayMicroseconds(20);
  uint16_t Vbat[50];
  uint16_t sumVbat;
  for (int8_t i = 0; i < 50; i++) {
    Vbat[i] = analogRead(batt);
    sumVbat += Vbat[i];
  }

  float Vbat_f = ((float(sumVbat / 50.0) * 3.3 / 4095.0) / (2.2 * 12.6 / 12.2)) * 12.6;
  dtostrf(Vbat_f, 4, 1, buff);
  Vbat_f = Vbat_f * 10.0;
  uint8_t Vbat_i = (int) Vbat_f;
  lcd.drawString(11, 0, buff);
  lcd.drawString(15, 0, "v");
  uint8_t Bar = map(Vbat_i, 111, 124, 0, 5);
  if (Vbat_i < 112) {
    led_OFF;
    lcd.drawString(9, 0, "!");
    if (Vbat_i < 111) Bar = 0;
  }
  else if (Vbat_i <= 115) {
    lcd.drawString(9, 0, "!");
  }
  
  lcd.drawTile(10, 0, 1, bat[Bar]);

  lcd.drawString(0, 0, "P:");
  lcd.drawString(0, 5, "CP:");
  lcd.drawString(9, 5, "STOP:");
  lcd.draw1x2String(6, 6, "V:");

  if (!DOWN) {
    while (!DOWN) {}
    if (++idx > 4) idx = 0;
  }
  if (!UP) {
    while (!UP) {}
    if (--idx < 0) idx = 4;
  }
  switch (idx) {
    case 0:
      sprintf(buff, "%1d", ee.PLAN);
      choose(1); lcd.drawString(2, 0, buff);
      choose(0); line_select();
      sprintf(buff, "%1d", ee.CPI);
      choose(0); lcd.drawString(3, 5, buff);
      sprintf(buff, "%02d", ee.STOP[ee.PLAN]);
      choose(0); lcd.drawString(14, 5, buff);
      sprintf(buff, "%03d", ee.V);
      choose(0); lcd.draw1x2String(8, 6, buff);
      if (!PLUS) {
        while (!PLUS) {}
        if (++ee.PLAN > (MAXPLAN - 1)) ee.PLAN = 0;
      }
      if (!MIN) {
        while (!MIN) {}
        if (--ee.PLAN < 0) ee.PLAN = MAXPLAN - 1;
      }
      break;
    case 1:
      sprintf(buff, "%1d", ee.PLAN);
      choose(0); lcd.drawString(2, 0, buff);
      choose(1); line_select();
      sprintf(buff, "%1d", ee.CPI);
      choose(0); lcd.drawString(3, 5, buff);
      sprintf(buff, "%02d", ee.STOP[ee.PLAN]);
      choose(0); lcd.drawString(14, 5, buff);
      sprintf(buff, "%03d", ee.V);
      choose(0); lcd.draw1x2String(8, 6, buff);
      if (!PLUS) {
        while (!PLUS) {}
        if (++ee.LINE > 1) ee.LINE = 0;
      }
      if (!MIN) {
        while (!MIN) {}
        if (--ee.LINE < 0) ee.LINE = 1;
      }
      break;
    case 2:
      sprintf(buff, "%1d", ee.PLAN);
      choose(0); lcd.drawString(2, 0, buff);
      choose(0); line_select();
      sprintf(buff, "%1d", ee.CPI);
      choose(1); lcd.drawString(3, 5, buff);
      sprintf(buff, "%02d", ee.STOP[ee.PLAN]);
      choose(0); lcd.drawString(14, 5, buff);
      sprintf(buff, "%03d", ee.V);
      choose(0); lcd.draw1x2String(8, 6, buff);
      if (!PLUS) {
        while (!PLUS) {}
        if (++ee.CPI > 9) ee.CPI = 9;
      }
      if (!MIN) {
        while (!MIN) {}
        if (--ee.CPI < 0) ee.CPI = 0;
      }
      break;
    case 3:
      sprintf(buff, "%1d", ee.PLAN);
      choose(0); lcd.drawString(2, 0, buff);
      choose(0); line_select();
      sprintf(buff, "%1d", ee.CPI);
      choose(0); lcd.drawString(3, 5, buff);
      sprintf(buff, "%02d", ee.STOP[ee.PLAN]);
      choose(1); lcd.drawString(14, 5, buff);
      sprintf(buff, "%03d", ee.V);
      choose(0); lcd.draw1x2String(8, 6, buff);
      if (!PLUS) {
        while (!PLUS) {}
        if (++ee.STOP[ee.PLAN] > 99) ee.STOP[ee.PLAN] = 0;
      }
      if (!MIN) {
        while (!MIN) {}
        if (--ee.STOP[ee.PLAN] < 0) ee.STOP[ee.PLAN] = 99;
      }
      break;
    case 4:
      sprintf(buff, "%1d", ee.PLAN);
      choose(0); lcd.drawString(2, 0, buff);
      choose(0); line_select();
      sprintf(buff, "%1d", ee.CPI);
      choose(0); lcd.drawString(3, 5, buff);
      sprintf(buff, "%02d", ee.STOP[ee.PLAN]);
      choose(0); lcd.drawString(14, 5, buff);
      sprintf(buff, "%03d", ee.V);
      choose(1); lcd.draw1x2String(8, 6, buff);
      if (!PLUS) {
        if (++ee.V > 100) ee.V = 100;
        delay(100);
      }
      if (!MIN) {
        if (--ee.V < 10) ee.V = 10;
        delay(100);
      }
      break;
  }

  choose(1); lcd.drawString(0, 7, "Menu"); lcd.drawString(13, 7, "Go!"); choose(0);
  for (int8_t i = 0; i <= 15; i++) {
    lcd.drawTile(i, 1, 1, zzzzz);
  }
}
//=======================================================================================
void line_select() {
  lcd.setCursor(4, 0);
  switch (ee.LINE) {
    case BLK: lcd.print("BLK"); break;
    case WHT: lcd.print("WHT"); break;
  }
}
//=======================================================================================
void menu() {
  int8_t index = 0;
  led_OFF;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 3) index = 0;
    }
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 3;
    }
    if (!BACK) {
      break;
    }
    switch (index) {
      case 0:
        sprintf(buff, "PATH PLANNING:%2d", ee.PLAN);
        choose(1); lcd.draw1x2String(0, 1, buff);
        choose(0); lcd.drawString(0, 3, " SET CHECKPOINT ");
        choose(0); lcd.drawString(0, 4, "CALIBRATE SENSOR");
        choose(0); lcd.drawString(0, 5, "ADVANCED SETTING");
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.PLAN > (MAXPLAN - 1)) ee.PLAN = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.PLAN < 0) ee.PLAN = MAXPLAN - 1;
        }
        if (!OK) {
          planning_1();
          index = 0;
        }
        break;
      case 1:
        sprintf(buff, "PATH PLANNING:%2d", ee.PLAN);
        choose(0); lcd.draw1x2String(0, 1, buff);
        choose(1); lcd.drawString(0, 3, " SET CHECKPOINT ");
        choose(0); lcd.drawString(0, 4, "CALIBRATE SENSOR");
        choose(0); lcd.drawString(0, 5, "ADVANCED SETTING");
        if (!OK) {
          checkpoint();
          index = 1;
        }
        break;
      case 2:
        sprintf(buff, "PATH PLANNING:%2d", ee.PLAN);
        choose(0); lcd.draw1x2String(0, 1, buff);
        choose(0); lcd.drawString(0, 3, " SET CHECKPOINT ");
        choose(1); lcd.drawString(0, 4, "CALIBRATE SENSOR");
        choose(0); lcd.drawString(0, 5, "ADVANCED SETTING");
        if (!OK) {
          calibration();
          index = 2;
        }
        break;
      case 3:
        sprintf(buff, "PATH PLANNING:%2d", ee.PLAN);
        choose(0); lcd.draw1x2String(0, 1, buff);
        choose(0); lcd.drawString(0, 3, " SET CHECKPOINT ");
        choose(0); lcd.drawString(0, 4, "CALIBRATE SENSOR");
        choose(1); lcd.drawString(0, 5, "ADVANCED SETTING");
        if (!OK) {
          advanced();
          index = 3;
        }
        break;
    }
    choose(1); lcd.drawString(0, 7, "Enter"); /*lcd.drawString (9, 7, " ");*/ lcd.drawString(12, 7, "Exit"); lcd.drawTile(10, 7, 1, zzzz); lcd.drawTile(11, 7, 1, savedata);
  }
  lcd.clear();
  eeWrite();
  while (!BACK) {
    delay(50);
  }
}
//=======================================================================================
void planning_1() {
  int8_t index = 0;
  uint16_t enc_last = 0;
  rPos = 0;
  lPos = 0;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 6) index = 0;
    }
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 6;
    }
    if (!BACK) {
      break;
    }

    if (index == 0) {
      uint16_t s = 0;
      if (!OK) {
        while (1) {
          if (OK) {
            planning_2();
            switch (ee.COUNTERMODE[ee.PLAN][ee.I]) {
              case ENCODERR: enc_last = RPOS; break;
              case ENCODERL: enc_last = LPOS; break;
            }
            break;
          }
          else {
            s++;
          }
          if (s >= 1000) {
            submenu();
            break;
          }
          delay(1);
        }
      }
    }
    else {
      if (!OK) {
        planning_2();
        switch (ee.COUNTERMODE[ee.PLAN][ee.I]) {
          case ENCODERR: enc_last = RPOS; break;
          case ENCODERL: enc_last = LPOS; break;
        }
      }
    }
    choose(0);
    lcd.drawString(0, 3, "  Action: ");
    lcd.drawString(0, 4, "Mode:");
    lcd.drawString(0, 6, "L:");
    lcd.drawString(10, 6, "R:");
    lcd.drawString(7, 7, ":");

    if (ee.I == 0) ee.SENSOR[ee.PLAN][0] = DIRECT;

    switch (index) {
      case 0:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(1); lcd.draw1x2String(0, 0, buff);
        choose(0); action_menu();
        choose(0); sensor_menu();
        sprintf(buff, "%04d", ee.LSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(2, 6, buff);
        sprintf(buff, "%04d", ee.RSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(12, 6, buff);
        choose(0); counter_menu();
        sprintf(buff, "%05d", ee.COUNTER[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(8, 7, buff);

        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.I > 99) ee.I = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.I < 0) ee.I = 99;
        }
        break;
      case 1:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        choose(1); action_menu();
        choose(0); sensor_menu();
        sprintf(buff, "%04d", ee.LSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(2, 6, buff);
        sprintf(buff, "%04d", ee.RSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(12, 6, buff);
        choose(0); counter_menu();
        sprintf(buff, "%05d", ee.COUNTER[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(8, 7, buff);

        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.ACTION[ee.PLAN][ee.I] > 8) {
            ee.ACTION[ee.PLAN][ee.I] = 0;
          }
          action_list();
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.ACTION[ee.PLAN][ee.I] < 0) {
            ee.ACTION[ee.PLAN][ee.I] = 8;
          }
          action_list();
        }
        break;
      case 2:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        choose(0); action_menu();
        choose(1); sensor_menu();
        sprintf(buff, "%04d", ee.LSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(2, 6, buff);
        sprintf(buff, "%04d", ee.RSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(12, 6, buff);
        choose(0); counter_menu();
        sprintf(buff, "%05d", ee.COUNTER[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(8, 7, buff);

        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.SENSOR[ee.PLAN][ee.I] > 26) ee.SENSOR[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.SENSOR[ee.PLAN][ee.I] < 0) ee.SENSOR[ee.PLAN][ee.I] = 26;
        }
        break;
      case 3:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        choose(0); action_menu();
        choose(0); sensor_menu();
        sprintf(buff, "%04d", ee.LSPEED[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(2, 6, buff);
        sprintf(buff, "%04d", ee.RSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(12, 6, buff);
        choose(0); counter_menu();
        sprintf(buff, "%05d", ee.COUNTER[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(8, 7, buff);

        if (!PLUS) {
          if (++ee.LSPEED[ee.PLAN][ee.I] > 100) ee.LSPEED[ee.PLAN][ee.I] = -100;
          delay(50);
        }
        if (!MIN) {
          if (--ee.LSPEED[ee.PLAN][ee.I] < -100) ee.LSPEED[ee.PLAN][ee.I] = 100;
          delay(50);
        }
        break;
      case 4:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        choose(0); action_menu();
        choose(0); sensor_menu();
        sprintf(buff, "%04d", ee.LSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(2, 6, buff);
        sprintf(buff, "%04d", ee.RSPEED[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(12, 6, buff);
        choose(0); counter_menu();
        sprintf(buff, "%05d", ee.COUNTER[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(8, 7, buff);

        if (!PLUS) {
          if (++ee.RSPEED[ee.PLAN][ee.I] > 100) ee.RSPEED[ee.PLAN][ee.I] = -100;
          delay(50);
        }
        if (!MIN) {
          if (--ee.RSPEED[ee.PLAN][ee.I] < -100) ee.RSPEED[ee.PLAN][ee.I] = 100;
          delay(50);
        }
        break;
      case 5:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        choose(0); action_menu();
        choose(0); sensor_menu();
        sprintf(buff, "%04d", ee.LSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(2, 6, buff);
        sprintf(buff, "%04d", ee.RSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(12, 6, buff);
        choose(1); counter_menu();
        sprintf(buff, "%05d", ee.COUNTER[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(8, 7, buff);

        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.COUNTERMODE[ee.PLAN][ee.I] > 2) ee.COUNTERMODE[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.COUNTERMODE[ee.PLAN][ee.I] < 0) ee.COUNTERMODE[ee.PLAN][ee.I] = 2;
        }
        break;
      case 6:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        choose(0); action_menu();
        choose(0); sensor_menu();
        sprintf(buff, "%04d", ee.LSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(2, 6, buff);
        sprintf(buff, "%04d", ee.RSPEED[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(12, 6, buff);
        choose(0); counter_menu();
        sprintf(buff, "%05d", ee.COUNTER[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(8, 7, buff);

        uint16_t enc_move = 0;
        switch (ee.COUNTERMODE[ee.PLAN][ee.I]) {
          case ENCODERR: enc_move = RPOS - enc_last; ee.COUNTER[ee.PLAN][ee.I] += enc_move; break;
          case ENCODERL: enc_move = LPOS - enc_last; ee.COUNTER[ee.PLAN][ee.I] += enc_move; break;
        }
        if (!PLUS) {
          ee.COUNTER[ee.PLAN][ee.I] = ee.COUNTER[ee.PLAN][ee.I] + 2;
          delay(50);
        }
        if (!MIN) {
          ee.COUNTER[ee.PLAN][ee.I] = ee.COUNTER[ee.PLAN][ee.I] - 2;
          delay(50);
        }
        if (ee.COUNTER[ee.PLAN][ee.I] < 0) {
          ee.COUNTER[ee.PLAN][ee.I] = 0;
        }
        break;
    }
    switch (ee.COUNTERMODE[ee.PLAN][ee.I]) {
      case ENCODERR: enc_last = RPOS; break;
      case ENCODERL: enc_last = LPOS; break;
    }
    for (int8_t i = 0; i <= 15; i++) {
      lcd.drawTile(i, 2, 1, zzzzz);
    }
  }
  lcd.clear();
  choose(0);
  while (!BACK) {
    delay(50);
  }
}
//=======================================================================================
void planning_2() {
  int8_t index = 0;
  uint16_t enc_last = 0;
  rPos = 0;
  lPos = 0;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 11) index = 0;
    }
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 11;
    }
    if (index == 0) {
      uint16_t s = 0;
      if (!OK) {
        while (1) {
          if (OK) {
            break;
          }
          else {
            s++;
          }
          if (s >= 1000) {
            submenu();
            break;
          }
          delay(1);
        }
      }
    }
    if (!BACK) {
      break;
    }
    choose(0);
    lcd.drawString(0, 3, "Va:"); lcd.drawString(10, 3, ":");
    lcd.drawString(0, 4, "Vb:"); lcd.drawString(10, 4, ":");
    lcd.drawString(0, 5, "PID:");
    lcd.drawString(8, 5, "["); lcd.drawString(12, 5, "]");
    lcd.drawString(5, 7, " to:"); lcd.drawString(12, 7, "-");
    uint16_t enc_move = 0;
    switch (index) {
      case 0:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(1); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.I > 99) ee.I = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.I < 0) ee.I = 99;
        }
        break;
      case 1:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          if (++ee.VA[ee.PLAN][ee.I] > 100) ee.VA[ee.PLAN][ee.I] = 100;
          delay(50);
        }
        if (!MIN) {
          if (--ee.VA[ee.PLAN][ee.I] < 0) ee.VA[ee.PLAN][ee.I] = 0;
          delay(50);
        }
        break;
      case 2:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(1); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.COUNTERAMODE[ee.PLAN][ee.I] > 2) ee.COUNTERAMODE[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.COUNTERAMODE[ee.PLAN][ee.I] < 0) ee.COUNTERAMODE[ee.PLAN][ee.I] = 2;
        }
        break;
      case 3:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        switch (ee.COUNTERAMODE[ee.PLAN][ee.I]) {
          case ENCODERR: enc_move = RPOS - enc_last; ee.COUNTA[ee.PLAN][ee.I] += enc_move; break;
          case ENCODERL: enc_move = LPOS - enc_last; ee.COUNTA[ee.PLAN][ee.I] += enc_move; break;
        }
        if (!PLUS) {
          ee.COUNTA[ee.PLAN][ee.I]++;
          delay(50);
        }
        if (!MIN) {
          if (--ee.COUNTA[ee.PLAN][ee.I] < 0) ee.COUNTA[ee.PLAN][ee.I] = 0;
          delay(50);
        }
        if ( ee.COUNTA[ee.PLAN][ee.I] < 0) {
          ee.COUNTA[ee.PLAN][ee.I] = 0;
        }
        break;
      case 4:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          if (++ee.VB[ee.PLAN][ee.I] > 100) ee.VB[ee.PLAN][ee.I] = 100;
          delay(50);
        }
        if (!MIN) {
          if (--ee.VB[ee.PLAN][ee.I] < 0) ee.VB[ee.PLAN][ee.I] = 0;
          delay(50);
        }
        break;
      case 5:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(1); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.COUNTERBMODE[ee.PLAN][ee.I] > 2) ee.COUNTERBMODE[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.COUNTERBMODE[ee.PLAN][ee.I] < 0) ee.COUNTERBMODE[ee.PLAN][ee.I] = 2;
        }
        break;
      case 6:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        switch (ee.COUNTERBMODE[ee.PLAN][ee.I]) {
          case ENCODERR: enc_move = RPOS - enc_last; ee.COUNTB[ee.PLAN][ee.I] += enc_move; break;
          case ENCODERL: enc_move = LPOS - enc_last; ee.COUNTB[ee.PLAN][ee.I] += enc_move; break;
        }
        if (!PLUS) {
          ee.COUNTB[ee.PLAN][ee.I]++;
          delay(50);
        }
        if (!MIN) {
          if (--ee.COUNTB[ee.PLAN][ee.I] < 0) ee.COUNTB[ee.PLAN][ee.I] = 0;
          delay(50);
        }
        if (ee.COUNTB[ee.PLAN][ee.I] < 0) {
          ee.COUNTB[ee.PLAN][ee.I] = 0;
        }
        break;
      case 7:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(1); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.pid[ee.PLAN][ee.I] > 2) ee.pid[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.pid[ee.PLAN][ee.I] < 0) ee.pid[ee.PLAN][ee.I] = 2;
        }
        break;
      case 8:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(1); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.FOLLOWMODE[ee.PLAN][ee.I] > 2) ee.FOLLOWMODE[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.FOLLOWMODE[ee.PLAN][ee.I] < 0) ee.FOLLOWMODE[ee.PLAN][ee.I] = 2;
        }
        break;
      case 9:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(1); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.JUMP[ee.PLAN][ee.I] > 1) ee.JUMP[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.JUMP[ee.PLAN][ee.I] < 0) ee.JUMP[ee.PLAN][ee.I] = 1;
        }
        break;
      case 10:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.jumpP[ee.PLAN][ee.I] > MAXPLAN - 1) ee.jumpP[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.jumpP[ee.PLAN][ee.I] < 0) ee.jumpP[ee.PLAN][ee.I] = MAXPLAN - 1;
        }
        break;
      case 11:
        sprintf(buff, " PLAN:%02d - I:%02d  ", ee.PLAN, ee.I);
        choose(0); lcd.draw1x2String(0, 0, buff);
        sprintf(buff, "%3d", ee.VA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 3, buff);
        choose(0); counterA_menu();
        sprintf(buff, "%5d", ee.COUNTA[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 3, buff);
        sprintf(buff, "%3d", ee.VB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(3, 4, buff);
        choose(0); counterB_menu();
        sprintf(buff, "%5d", ee.COUNTB[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(11, 4, buff);
        sprintf(buff, "%1d", ee.pid[ee.PLAN][ee.I] + 1);
        choose(0); lcd.drawString(4, 5, buff);
        choose(0); follow_menu();
        choose(0); jump_menu();
        sprintf(buff, "P%02d", ee.jumpP[ee.PLAN][ee.I]);
        choose(0); lcd.drawString(9, 7, buff);
        sprintf(buff, "i%02d", ee.jumpI[ee.PLAN][ee.I]);
        choose(1); lcd.drawString(13, 7, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.jumpI[ee.PLAN][ee.I] > 99) ee.jumpI[ee.PLAN][ee.I] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.jumpI[ee.PLAN][ee.I] < 0) ee.jumpI[ee.PLAN][ee.I] = 99;
        }
        break;
    }
    switch (ee.COUNTERAMODE[ee.PLAN][ee.I]) {
      case ENCODERR: enc_last = RPOS; break;
      case ENCODERL: enc_last = LPOS; break;
    }
    switch (ee.COUNTERBMODE[ee.PLAN][ee.I]) {
      case ENCODERR: enc_last = RPOS; break;
      case ENCODERL: enc_last = LPOS; break;
    }
    for (int8_t i = 0; i <= 15; i++) {
      lcd.drawTile(i, 2, 1, zzzzz);
    }
  }
  lcd.clear();
  choose(0);
  while (!BACK) {
    delay(50);
  }
}
//=======================================================================================
void counterA_menu() {
  lcd.setCursor(8, 3);
  switch (ee.COUNTERAMODE[ee.PLAN][ee.I]) {
    case TIMER:
      lcd.print(F("Ta"));
      break;
    case ENCODERR:
      lcd.print(F("Ra"));
      break;
    case ENCODERL:
      lcd.print(F("La"));
      break;
  }
}

void counterB_menu() {
  lcd.setCursor(8, 4);
  switch (ee.COUNTERBMODE[ee.PLAN][ee.I]) {
    case TIMER:
      lcd.print(F("Tb"));
      break;
    case ENCODERR:
      lcd.print(F("Rb"));
      break;
    case ENCODERL:
      lcd.print(F("Lb"));
      break;
  }
}

void follow_menu() {
  switch (ee.FOLLOWMODE[ee.PLAN][ee.I]) {
    case FLC: lcd.drawString(9, 5, "FLC");
      break;
    case FLR: lcd.drawString(9, 5, "FLR");
      break;
    case FLL: lcd.drawString(9, 5, "FLL");
      break;
  }
}

void jump_menu() {
  lcd.drawString(1, 7, "Jump");
  switch (ee.JUMP[ee.PLAN][ee.I]) {
    case off:
      lcd.drawTile(0, 7, 1, uncheck);
      break;
    case on:
      lcd.drawTile(0, 7, 1, checked);
      break;
  }
}

void action_menu() {
  switch (ee.ACTION[ee.PLAN][ee.I]) {
    case BLK: lcd.drawString(10, 3, "BLK"); choose(0); lcd.drawString(13, 3, " "); break;
    case WHT: lcd.drawString(10, 3, "WHT"); choose(0); lcd.drawString(13, 3, " "); break;
    case RGT: lcd.drawString(10, 3, "RGT"); choose(0); lcd.drawString(13, 3, " "); break;
    case LFT: lcd.drawString(10, 3, "LFT"); choose(0); lcd.drawString(13, 3, " "); break;
    case FWD: lcd.drawString(10, 3, "FWD"); choose(0); lcd.drawString(13, 3, " "); break;
    case BWD: lcd.drawString(10, 3, "BWD"); choose(0); lcd.drawString(13, 3, " "); break;
    case PICK: lcd.drawString(10, 3, "PICK"); break;
    case DROP: lcd.drawString(10, 3, "DROP"); break;
    case BLOW: lcd.drawString(10, 3, "BLOW"); break;
  }
}

void action_list() {
  //  if (ee.I == 0) {
  //    if (ee.LINE == BLK) {
  //      ee.ACTION[ee.PLAN][0] = BLK;
  //    }
  //    else if (ee.LINE == WHT) {
  //      ee.ACTION[ee.PLAN][0] = WHT;
  //    }
  //  }
  switch (ee.ACTION[ee.PLAN][ee.I]) {
    case BLK: ee.LSPEED[ee.PLAN][ee.I] = 0; ee.RSPEED[ee.PLAN][ee.I] = 0; ee.COUNTER[ee.PLAN][ee.I] = 0; break;
    case WHT: ee.LSPEED[ee.PLAN][ee.I] = 0; ee.RSPEED[ee.PLAN][ee.I] = 0; ee.COUNTER[ee.PLAN][ee.I] = 0; break;
    case RGT: ee.LSPEED[ee.PLAN][ee.I] = 80; ee.RSPEED[ee.PLAN][ee.I] = -40; ee.COUNTER[ee.PLAN][ee.I] = 100; break;
    case LFT: ee.LSPEED[ee.PLAN][ee.I] = -40; ee.RSPEED[ee.PLAN][ee.I] = 80; ee.COUNTER[ee.PLAN][ee.I] = 100; break;
    case FWD: ee.LSPEED[ee.PLAN][ee.I] = 70; ee.RSPEED[ee.PLAN][ee.I] = 70; ee.COUNTER[ee.PLAN][ee.I] = 100; break;
    case BWD: ee.LSPEED[ee.PLAN][ee.I] = -70; ee.RSPEED[ee.PLAN][ee.I] = -70; ee.COUNTER[ee.PLAN][ee.I] = 100; break;
    case PICK: ee.LSPEED[ee.PLAN][ee.I] = 0; ee.RSPEED[ee.PLAN][ee.I] = 0; ee.COUNTER[ee.PLAN][ee.I] = 100; break;
    case DROP: ee.LSPEED[ee.PLAN][ee.I] = 0; ee.RSPEED[ee.PLAN][ee.I] = 0; ee.COUNTER[ee.PLAN][ee.I] = 100; break;
    case BLOW: ee.LSPEED[ee.PLAN][ee.I] = 0; ee.RSPEED[ee.PLAN][ee.I] = 0; ee.COUNTER[ee.PLAN][ee.I] = 100; break;
  }
}

void sensor_menu() {
  sprintf(buff, "%02d", ee.SENSOR[ee.PLAN][ee.I]);
  lcd.drawString(5, 4, buff);
  lcd.setCursor(7, 4);
  switch (ee.SENSOR[ee.PLAN][ee.I]) {
    case 0: lcd.print(F(" -  NONE ")); choose(0); lcd.drawString(1, 5, "--------------"); break;

    case 1: lcd.print(F(" - DIRECT")); choose(0); lcd.drawString(1, 5, "xxxxxxxxxxxxxx"); break;

    case 2: lcd.print(F(" -   EQ  ")); choose(0); lcd.drawString(1, 5, "00000000000000"); break;
    case 3: lcd.print(F(" -   EQ  ")); choose(0); lcd.drawString(1, 5, "11111111111111"); break;

    case 4: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "00000000000001"); break;
    case 5: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "00000000000011"); break;
    case 6: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "00000000000111"); break;
    case 7: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "00000000001111"); break;
    case 8: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "10000000000000"); break;
    case 9: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "11000000000000"); break;
    case 10: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "11100000000000"); break;
    case 11: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "11110000000000"); break;
    case 12: lcd.print(F(" -   OR  ")); choose(0); lcd.drawString(1, 5, "11111111111111"); break;

    case 13: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "00000111100001"); break;
    case 14: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "00000111100011"); break;
    case 15: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "00000111100111"); break;
    case 16: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "00000111101111"); break;
    case 17: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "10000111100000"); break;
    case 18: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11000111100000"); break;
    case 19: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11100111100000"); break;
    case 20: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11110111100000"); break;
    case 21: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "10000000000001"); break;
    case 22: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11000000000011"); break;
    case 23: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11100000000111"); break;
    case 24: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11110000001111"); break;
    case 25: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11111000011111"); break;
    case 26: lcd.print(F(" -   XOR ")); choose(0); lcd.drawString(1, 5, "11111100111111"); break;
  }
}

void counter_menu() {
  lcd.setCursor(2, 7);
  switch (ee.COUNTERMODE[ee.PLAN][ee.I]) {
    case TIMER:
      lcd.print(F("DELAY"));
      break;
    case ENCODERR:
      lcd.print(F("ENC-R"));
      break;
    case ENCODERL:
      lcd.print(F("ENC-L"));
      break;
  }
}

void submenu() {
  int8_t ISUB = ee.I;
  int8_t index = 0;
  lcd.clear();
  lcd.drawString(0, 3, "   Release OK   ");
  lcd.drawString(0, 4, "to enter SUBMENU");
  while (!OK) {
    delay(50);
  }
  lcd.clear();
  while (1) {
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 2) index = 0;
    }
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 2;
    }
    if (!BACK) {
      break;
    }
    sprintf(buff, "Copy i%02d to ", ee.I);
    choose(0); lcd.draw1x2String(0, 0, buff);
    switch (index) {
      case 0:
        sprintf(buff, "i%02d", ISUB);
        choose(1); lcd.draw1x2String(12, 0, buff);
        choose(0); lcd.draw1x2String(0, 2, "     Insert     ");
        choose(0); lcd.draw1x2String(0, 4, "     Delete     ");
        if (!PLUS) {
          if (++ISUB > 99) ISUB = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ISUB < 0) ISUB = 99;
          delay(50);
        }
        if (!OK) {
          lcd.clear();
          while (!OK) {
            delay(50);
          }
          ee.ACTION[ee.PLAN][ISUB] = ee.ACTION[ee.PLAN][ee.I];
          ee.SENSOR[ee.PLAN][ISUB] = ee.SENSOR[ee.PLAN][ee.I];
          ee.RSPEED[ee.PLAN][ISUB] = ee.RSPEED[ee.PLAN][ee.I];
          ee.LSPEED[ee.PLAN][ISUB] = ee.LSPEED[ee.PLAN][ee.I];
          ee.COUNTERMODE[ee.PLAN][ISUB] = ee.COUNTERMODE[ee.PLAN][ee.I];
          ee.COUNTER[ee.PLAN][ISUB] = ee.COUNTER[ee.PLAN][ee.I];
          ee.VA[ee.PLAN][ISUB] = ee.VA[ee.PLAN][ee.I];
          ee.COUNTA[ee.PLAN][ISUB] = ee.COUNTA[ee.PLAN][ee.I];
          ee.COUNTERAMODE[ee.PLAN][ISUB] = ee.COUNTERAMODE[ee.PLAN][ee.I];
          ee.VB[ee.PLAN][ISUB] = ee.VB[ee.PLAN][ee.I];
          ee.COUNTB[ee.PLAN][ISUB] = ee.COUNTB[ee.PLAN][ee.I];
          ee.COUNTERBMODE[ee.PLAN][ISUB] = ee.COUNTERBMODE[ee.PLAN][ee.I];
          ee.pid[ee.PLAN][ISUB] = ee.pid[ee.PLAN][ee.I];
          ee.FOLLOWMODE[ee.PLAN][ISUB] = ee.FOLLOWMODE[ee.PLAN][ee.I];
          ee.JUMP[ee.PLAN][ISUB] = ee.JUMP[ee.PLAN][ee.I];
          ee.jumpP[ee.PLAN][ISUB] = ee.jumpP[ee.PLAN][ee.I];
          ee.jumpI[ee.PLAN][ISUB] = ee.jumpI[ee.PLAN][ee.I];
          lcd.draw1x2String(0, 2, "    Success!    ");
          sprintf(buff, " Copied to i%02d  ", ISUB);
          lcd.draw1x2String(0, 4, buff);
          delay(1000);
          lcd.clear();
        }
        break;
      case 1:
        sprintf(buff, "i%02d", ISUB);
        choose(0); lcd.draw1x2String(12, 0, buff);
        choose(1); lcd.draw1x2String(0, 2, "     Insert     ");
        choose(0); lcd.draw1x2String(0, 4, "     Delete     ");
        if (!OK) {
          lcd.clear();
          while (!OK) {
            delay(50);
          }
          for (int8_t i = 99; i > ee.I; i--) {
            ee.ACTION[ee.PLAN][i] = ee.ACTION[ee.PLAN][i - 1];
            ee.SENSOR[ee.PLAN][i] = ee.SENSOR[ee.PLAN][i - 1];
            ee.RSPEED[ee.PLAN][i] = ee.RSPEED[ee.PLAN][i - 1];
            ee.LSPEED[ee.PLAN][i] = ee.LSPEED[ee.PLAN][i - 1];
            ee.COUNTERMODE[ee.PLAN][i] = ee.COUNTERMODE[ee.PLAN][i - 1];
            ee.COUNTER[ee.PLAN][i] = ee.COUNTER[ee.PLAN][i - 1];
            ee.VA[ee.PLAN][i] = ee.VA[ee.PLAN][i - 1];
            ee.COUNTA[ee.PLAN][i] = ee.COUNTA[ee.PLAN][i - 1];
            ee.COUNTERAMODE[ee.PLAN][i] = ee.COUNTERAMODE[ee.PLAN][i - 1];
            ee.VB[ee.PLAN][i] = ee.VB[ee.PLAN][i - 1];
            ee.COUNTB[ee.PLAN][i] = ee.COUNTB[ee.PLAN][i - 1];
            ee.COUNTERBMODE[ee.PLAN][i] = ee.COUNTERBMODE[ee.PLAN][i - 1];
            ee.pid[ee.PLAN][i] = ee.pid[ee.PLAN][i - 1];
            ee.FOLLOWMODE[ee.PLAN][i] = ee.FOLLOWMODE[ee.PLAN][i - 1];
            ee.JUMP[ee.PLAN][i] = ee.JUMP[ee.PLAN][i - 1];
            ee.jumpP[ee.PLAN][i] = ee.jumpP[ee.PLAN][i - 1];
            ee.jumpI[ee.PLAN][i] = ee.jumpI[ee.PLAN][i - 1];
          }
          ee.ACTION[ee.PLAN][ee.I] = 0;
          ee.SENSOR[ee.PLAN][ee.I] = 0;
          ee.RSPEED[ee.PLAN][ee.I] = 0;
          ee.LSPEED[ee.PLAN][ee.I] = 0;
          ee.COUNTERMODE[ee.PLAN][ee.I] = TIMER;
          ee.COUNTER[ee.PLAN][ee.I] = 0;
          ee.VA[ee.PLAN][ee.I] = 50;
          ee.COUNTA[ee.PLAN][ee.I] = 0;
          ee.COUNTERAMODE[ee.PLAN][ee.I] = TIMER;
          ee.VB[ee.PLAN][ee.I] = 50;
          ee.COUNTB[ee.PLAN][ee.I] = 0;
          ee.COUNTERBMODE[ee.PLAN][ee.I] = TIMER;
          ee.pid[ee.PLAN][ee.I] = 2;
          ee.FOLLOWMODE[ee.PLAN][ee.I] = FLC;
          ee.JUMP[ee.PLAN][ee.I] = off;
          ee.jumpP[ee.PLAN][ee.I] = 0;
          ee.jumpI[ee.PLAN][ee.I] = 0;

          lcd.draw1x2String(0, 2, "    Success!    ");
          sprintf(buff, "  i%02d Inserted  ", ee.I);
          lcd.draw1x2String(0, 4, buff);
          delay(1000);
          lcd.clear();
        }
        break;
      case 2:
        sprintf(buff, "i%02d", ISUB);
        choose(0); lcd.draw1x2String(12, 0, buff);
        choose(0); lcd.draw1x2String(0, 2, "     Insert     ");
        choose(1); lcd.draw1x2String(0, 4, "     Delete     "); choose(0);
        if (!OK) {
          lcd.clear();
          while (!OK) {
            delay(50);
          }
          for (int8_t i = ee.I; i < 99; i++) {
            ee.ACTION[ee.PLAN][i] = ee.ACTION[ee.PLAN][i + 1];
            ee.SENSOR[ee.PLAN][i] = ee.SENSOR[ee.PLAN][i + 1];
            ee.RSPEED[ee.PLAN][i] = ee.RSPEED[ee.PLAN][i + 1];
            ee.LSPEED[ee.PLAN][i] = ee.LSPEED[ee.PLAN][i + 1];
            ee.COUNTERMODE[ee.PLAN][i] = ee.COUNTERMODE[ee.PLAN][i + 1];
            ee.COUNTER[ee.PLAN][i] = ee.COUNTER[ee.PLAN][i + 1];
            ee.VA[ee.PLAN][i] = ee.VA[ee.PLAN][i + 1];
            ee.COUNTA[ee.PLAN][i] = ee.COUNTA[ee.PLAN][i + 1];
            ee.COUNTERAMODE[ee.PLAN][i] = ee.COUNTERAMODE[ee.PLAN][i + 1];
            ee.VB[ee.PLAN][i] = ee.VB[ee.PLAN][i + 1];
            ee.COUNTB[ee.PLAN][i] = ee.COUNTB[ee.PLAN][i + 1];
            ee.COUNTERBMODE[ee.PLAN][i] = ee.COUNTERBMODE[ee.PLAN][i + 1];
            ee.pid[ee.PLAN][i] = ee.pid[ee.PLAN][i + 1];
            ee.FOLLOWMODE[ee.PLAN][i] = ee.FOLLOWMODE[ee.PLAN][i + 1];
            ee.JUMP[ee.PLAN][i] = ee.JUMP[ee.PLAN][i + 1];
            ee.jumpP[ee.PLAN][i] = ee.jumpP[ee.PLAN][i + 1];
            ee.jumpI[ee.PLAN][i] = ee.jumpI[ee.PLAN][i + 1];
          }
          ee.ACTION[ee.PLAN][99] = 0;
          ee.SENSOR[ee.PLAN][99] = 0;
          ee.RSPEED[ee.PLAN][99] = 0;
          ee.LSPEED[ee.PLAN][99] = 0;
          ee.COUNTERMODE[ee.PLAN][99] = TIMER;
          ee.COUNTER[ee.PLAN][99] = 0;
          ee.VA[ee.PLAN][99] = 50;
          ee.COUNTA[ee.PLAN][99] = 0;
          ee.COUNTERAMODE[ee.PLAN][99] = TIMER;
          ee.VB[ee.PLAN][99] = 50;
          ee.COUNTB[ee.PLAN][99] = 0;
          ee.COUNTERBMODE[ee.PLAN][99] = TIMER;
          ee.pid[ee.PLAN][99] = 2;
          ee.FOLLOWMODE[ee.PLAN][99] = FLC;
          ee.JUMP[ee.PLAN][99] = off;
          ee.jumpP[ee.PLAN][99] = 0;
          ee.jumpI[ee.PLAN][99] = 0;

          lcd.draw1x2String(0, 2, "    Success!    ");
          sprintf(buff, "   i%02d Erased   ", ee.I);
          lcd.draw1x2String(0, 4, buff);
          delay(1000);
          lcd.clear();
        }
        break;
    }
    choose(1); lcd.drawString(0, 7, "OK"); lcd.drawString(10, 7, "Cancel");
  }
  lcd.clear();
  while (!BACK) {
    delay(50);
  }
}
//=======================================================================================
void checkpoint() {
  int8_t index = 0;
  int8_t i = 1;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 3;
    }
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 3) index = 0;
    }
    lcd.draw1x2String(0, 1, "CP:"); lcd.draw1x2String(7, 1, "I:");
    lcd.draw1x2String(0, 3, "Va:"); lcd.draw1x2String(7, 3, "Ta:");
    switch (index) {
      case 0:
        choose(1); sprintf(buff, "%1d", i); lcd.draw1x2String(3, 1, buff);
        choose(0); sprintf(buff, "%02d", ee.CP[i]); lcd.draw1x2String(9, 1, buff);
        choose(0); sprintf(buff, "%03d", ee.Va[i]); lcd.draw1x2String(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.Ta[i]); lcd.draw1x2String(10, 3, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++i > 9) i = 1;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--i < 1) i = 9;
        }
        break;
      case 1:
        choose(0); sprintf(buff, "%1d", i); lcd.draw1x2String(3, 1, buff);
        choose(1); sprintf(buff, "%02d", ee.CP[i]); lcd.draw1x2String(9, 1, buff);
        choose(0); sprintf(buff, "%03d", ee.Va[i]); lcd.draw1x2String(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.Ta[i]); lcd.draw1x2String(10, 3, buff);
        if (!PLUS) {
          if (++ee.CP[i] > 99) ee.CP[i] = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.CP[i] < 0) ee.CP[i] = 99;
          delay(50);
        }
        break;
      case 2:
        choose(0); sprintf(buff, "%1d", i); lcd.draw1x2String(3, 1, buff);
        choose(0); sprintf(buff, "%02d", ee.CP[i]); lcd.draw1x2String(9, 1, buff);
        choose(1); sprintf(buff, "%03d", ee.Va[i]); lcd.draw1x2String(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.Ta[i]); lcd.draw1x2String(10, 3, buff);
        if (!PLUS) {
          if (++ee.Va[i] > 100) ee.Va[i] = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.Va[i] < 0) ee.Va[i] = 100;
          delay(50);
        }
        break;
      case 3:
        choose(0); sprintf(buff, "%1d", i); lcd.draw1x2String(3, 1, buff);
        choose(0); sprintf(buff, "%02d", ee.CP[i]); lcd.draw1x2String(9, 1, buff);
        choose(0); sprintf(buff, "%03d", ee.Va[i]); lcd.draw1x2String(3, 3, buff);
        choose(1); sprintf(buff, "%03d", ee.Ta[i]); lcd.draw1x2String(10, 3, buff);
        if (!PLUS) {
          if (++ee.Ta[i] > 255) ee.Ta[i] = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.Ta[i] < 0) ee.Ta[i] = 255;
          delay(50);
        }
        break;
    }
    choose(1); lcd.drawString(12, 7, "Back"); choose(0);
    if (!BACK) break;
  }
  lcd.clear();
  while (!BACK) {
    delay(50);
  }
}

void advanced() {
  int8_t index = 0;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 3;
    }
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 3) index = 0;
    }
    if (!BACK) {
      break;
    }
    choose(1);
    lcd.drawString(0, 7, "Enter"); lcd.drawString(12, 7, "Back");
    switch (index) {
      case 0:
        choose(1); lcd.drawString(0, 1, "   Copy Plan    ");
        choose(0); lcd.drawString(0, 2, "   Clear Plan   ");
        choose(0); lcd.drawString(0, 3, "    Set PID     ");
        choose(0); lcd.drawString(0, 4, "    Gripper     ");
        if (!OK) {
          copyPlan();
          index = 0;
        }
        break;
      case 1:
        choose(0); lcd.drawString(0, 1, "   Copy Plan    ");
        choose(1); lcd.drawString(0, 2, "   Clear Plan   ");
        choose(0); lcd.drawString(0, 3, "    Set PID     ");
        choose(0); lcd.drawString(0, 4, "    Gripper     ");
        if (!OK) {
          clearPlan();
          index = 1;
        }
        break;
      case 2:
        choose(0); lcd.drawString(0, 1, "   Copy Plan    ");
        choose(0); lcd.drawString(0, 2, "   Clear Plan   ");
        choose(1); lcd.drawString(0, 3, "    Set PID     ");
        choose(0); lcd.drawString(0, 4, "    Gripper     ");
        if (!OK) {
          setPid();
          index = 2;
        }
        break;
      case 3:
        choose(0); lcd.drawString(0, 1, "   Copy Plan    ");
        choose(0); lcd.drawString(0, 2, "   Clear Plan   ");
        choose(0); lcd.drawString(0, 3, "    Set PID     ");
        choose(1); lcd.drawString(0, 4, "    Gripper     ");
        if (!OK) {
          setGripper();
          index = 3;
        }
        break;
    }
  }
  lcd.clear();
  while (!BACK) {
    delay(50);
  }
}

void copyPlan() {
  int8_t index = 0;
  int8_t ISUB[2] = {0, 99};
  int8_t PSUB[2] = {ee.PLAN, ee.PLAN};
  int8_t invers_mode = 0;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 4;
    }
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 4) index = 0;
    }
    lcd.draw1x2String(0, 0, "Copy P:");
    lcd.draw1x2String(9, 0, "to P:");
    lcd.draw1x2String(2, 2, "I:");
    lcd.draw1x2String(7, 2, "- I:");
    switch (index) {
      case 0:
        choose(1); sprintf(buff, "%1d", PSUB[0]); lcd.draw1x2String(7, 0, buff);
        choose(0); sprintf(buff, "%1d", PSUB[1]); lcd.draw1x2String(14, 0, buff);
        choose(0); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 2, buff);
        choose(0); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 2, buff);
        choose(0); invers_menu(invers_mode);
        if (!PLUS) {
          while (!PLUS) {}
          if (++PSUB[0] > MAXPLAN - 1) PSUB[0] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--PSUB[0] < 0) PSUB[0] = MAXPLAN - 1;
        }
        break;
      case 1:
        choose(0); sprintf(buff, "%1d", PSUB[0]); lcd.draw1x2String(7, 0, buff);
        choose(1); sprintf(buff, "%1d", PSUB[1]); lcd.draw1x2String(14, 0, buff);
        choose(0); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 2, buff);
        choose(0); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 2, buff);
        choose(0); invers_menu(invers_mode);
        if (!PLUS) {
          while (!PLUS) {}
          if (++PSUB[1] > MAXPLAN - 1) PSUB[1] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--PSUB[1] < 0) PSUB[1] = MAXPLAN - 1;
        }
        break;
      case 2:
        choose(0); sprintf(buff, "%1d", PSUB[0]); lcd.draw1x2String(7, 0, buff);
        choose(0); sprintf(buff, "%1d", PSUB[1]); lcd.draw1x2String(14, 0, buff);
        choose(1); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 2, buff);
        choose(0); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 2, buff);
        choose(0); invers_menu(invers_mode);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ISUB[0] > 99) ISUB[0] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ISUB[0] < 0) ISUB[0] = 99;
        }
        break;
      case 3:
        choose(0); sprintf(buff, "%1d", PSUB[0]); lcd.draw1x2String(7, 0, buff);
        choose(0); sprintf(buff, "%1d", PSUB[1]); lcd.draw1x2String(14, 0, buff);
        choose(0); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 2, buff);
        choose(1); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 2, buff);
        choose(0); invers_menu(invers_mode);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ISUB[1] > 99) ISUB[1] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ISUB[1] < 0) ISUB[1] = 99;
        }
        break;
      case 4:
        choose(0); sprintf(buff, "%1d", PSUB[0]); lcd.draw1x2String(7, 0, buff);
        choose(0); sprintf(buff, "%1d", PSUB[1]); lcd.draw1x2String(14, 0, buff);
        choose(0); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 2, buff);
        choose(0); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 2, buff);
        choose(1); invers_menu(invers_mode);
        if (!PLUS) {
          while (!PLUS) {}
          if (++invers_mode > 1) invers_mode = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--invers_mode < 0) invers_mode = 1;
        }
        break;
    }
    choose(1); lcd.drawString(0, 7, "OK"); lcd.drawString(12, 7, "Back"); choose(0);

    if (!OK) {
      lcd.clear();
      while (!OK) {
        delay(50);
      }
      for (int8_t i = ISUB[0]; i <= ISUB[1]; i++) {
        if (invers_mode == on) {
          if (ee.ACTION[PSUB[0]][i] == RGT) {       //invert action
            ee.ACTION[PSUB[1]][i] = LFT;
          }
          else if (ee.ACTION[PSUB[0]][i] == LFT) {
            ee.ACTION[PSUB[1]][i] = RGT;
          }
          else {
            ee.ACTION[PSUB[1]][i] = ee.ACTION[PSUB[0]][i];
          }
          if ((ee.SENSOR[PSUB[0]][i] >= 4 && ee.SENSOR[PSUB[0]][i] <= 7) || (ee.SENSOR[PSUB[0]][i] >= 13 && ee.SENSOR[PSUB[0]][i] <= 16)) {       //invert sensor mode
            ee.SENSOR[PSUB[1]][i] = ee.SENSOR[PSUB[0]][i] + 4;
          }
          else if ((ee.SENSOR[PSUB[0]][i] >= 8 && ee.SENSOR[PSUB[0]][i] <= 11) || (ee.SENSOR[PSUB[0]][i] >= 17 && ee.SENSOR[PSUB[0]][i] <= 20)) {
            ee.SENSOR[PSUB[1]][i] = ee.SENSOR[PSUB[0]][i] - 4;
          }
          else {
            ee.SENSOR[PSUB[1]][i] = ee.SENSOR[PSUB[0]][i];
          }
          ee.RSPEED[PSUB[1]][i] = ee.LSPEED[PSUB[0]][i];    //invert speed
          ee.LSPEED[PSUB[1]][i] = ee.RSPEED[PSUB[0]][i];
          if (ee.COUNTERMODE[PSUB[0]][i] == ENCODERR) {               //invert action counter mode
            ee.COUNTERMODE[PSUB[1]][i] = ENCODERL;
          }
          else if (ee.COUNTERMODE[PSUB[0]][i] == ENCODERL) {
            ee.COUNTERMODE[PSUB[1]][i] = ENCODERR;
          }
          else {
            ee.COUNTERMODE[PSUB[1]][i] = ee.COUNTERMODE[PSUB[0]][i];
          }
          if (ee.COUNTERAMODE[PSUB[0]][i] == ENCODERR) {               //invert counter A mode
            ee.COUNTERAMODE[PSUB[1]][i] = ENCODERL;
          }
          else if (ee.COUNTERAMODE[PSUB[0]][i] == ENCODERL) {
            ee.COUNTERAMODE[PSUB[1]][i] = ENCODERR;
          }
          else {
            ee.COUNTERAMODE[PSUB[1]][i] = ee.COUNTERAMODE[PSUB[0]][i];
          }
          if (ee.COUNTERBMODE[PSUB[0]][i] == ENCODERR) {               //invert counter B mode
            ee.COUNTERBMODE[PSUB[1]][i] = ENCODERL;
          }
          else if (ee.COUNTERBMODE[PSUB[0]][i] == ENCODERL) {
            ee.COUNTERBMODE[PSUB[1]][i] = ENCODERR;
          }
          else {
            ee.COUNTERBMODE[PSUB[1]][i] = ee.COUNTERBMODE[PSUB[0]][i];
          }
          if (ee.FOLLOWMODE[PSUB[0]][i] == FLR) {
            ee.FOLLOWMODE[PSUB[1]][i] = FLL;
          }
          else if (ee.FOLLOWMODE[PSUB[0]][i] == FLL) {
            ee.FOLLOWMODE[PSUB[1]][i] = FLR;
          }
          else {
            ee.FOLLOWMODE[PSUB[1]][i] = ee.FOLLOWMODE[PSUB[0]][i];
          }
        }
        else {
          ee.ACTION[PSUB[1]][i] = ee.ACTION[PSUB[0]][i];
          ee.SENSOR[PSUB[1]][i] = ee.SENSOR[PSUB[0]][i];
          ee.RSPEED[PSUB[1]][i] = ee.RSPEED[PSUB[0]][i];
          ee.LSPEED[PSUB[1]][i] = ee.LSPEED[PSUB[0]][i];
          ee.COUNTERMODE[PSUB[1]][i] = ee.COUNTERMODE[PSUB[0]][i];
          ee.COUNTERAMODE[PSUB[1]][i] = ee.COUNTERAMODE[PSUB[0]][i];
          ee.COUNTERBMODE[PSUB[1]][i] = ee.COUNTERBMODE[PSUB[0]][i];
          ee.FOLLOWMODE[PSUB[1]][i] = ee.FOLLOWMODE[PSUB[0]][i];
        }
        ee.COUNTER[PSUB[1]][i] = ee.COUNTER[PSUB[0]][i];
        ee.VA[PSUB[1]][i] = ee.VA[PSUB[0]][i];
        ee.COUNTA[PSUB[1]][i] = ee.COUNTA[PSUB[0]][i];
        ee.VB[PSUB[1]][i] = ee.VB[PSUB[0]][i];
        ee.COUNTB[PSUB[1]][i] = ee.COUNTB[PSUB[0]][i];
        ee.pid[PSUB[1]][i] = ee.pid[PSUB[0]][i];
        ee.JUMP[PSUB[1]][i] = ee.JUMP[PSUB[0]][i];
        ee.jumpP[PSUB[1]][i] = ee.jumpP[PSUB[0]][i];
        ee.jumpI[PSUB[1]][i] = ee.jumpI[PSUB[0]][i];
      }
      lcd.draw1x2String(0, 2, "    Success!    ");
      sprintf(buff, " Copied to P:%1d  ", PSUB[1]);
      lcd.draw1x2String(0, 4, buff);
      delay(1000);
      lcd.clear();
    }
    if (!BACK) break;
  }
  lcd.clear();
  while (!BACK) {
    delay(50);
  }
}

void clearPlan() {
  int8_t index = 0;
  int8_t ISUB[2] = {0, 99};
  int8_t PSUB = ee.PLAN;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 2;
    }
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 2) index = 0;
    }
    lcd.draw1x2String(3, 1, "Delete P:");
    lcd.draw1x2String(2, 3, "I:");
    lcd.draw1x2String(7, 3, "- I:");
    switch (index) {
      case 0:
        choose(1); sprintf(buff, "%1d", PSUB); lcd.draw1x2String(12, 1, buff);
        choose(0); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 3, buff);
        choose(0); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 3, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++PSUB > MAXPLAN - 1) PSUB = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--PSUB < 0) PSUB = MAXPLAN - 1;
        }
        break;
      case 1:
        choose(0); sprintf(buff, "%1d", PSUB); lcd.draw1x2String(12, 1, buff);
        choose(1); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 3, buff);
        choose(0); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 3, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ISUB[0] > 99) ISUB[0] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ISUB[0] < 0) ISUB[0] = 99;
        }
        break;
      case 2:
        choose(0); sprintf(buff, "%1d", PSUB); lcd.draw1x2String(12, 1, buff);
        choose(0); sprintf(buff, "%02d", ISUB[0]); lcd.draw1x2String(4, 3, buff);
        choose(1); sprintf(buff, "%02d", ISUB[1]); lcd.draw1x2String(11, 3, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ISUB[1] > 99) ISUB[1] = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ISUB[1] < 0) ISUB[1] = 99;
        }
        break;
    }
    choose(1); lcd.drawString(0, 7, "OK"); lcd.drawString(12, 7, "Back"); choose(0);
    if (!OK) {
      lcd.clear();
      while (!OK) {
        delay(50);
      }
      for (int8_t i = ISUB[0]; i <= ISUB[1]; i++) {
        ee.ACTION[PSUB][i] = 0;
        ee.SENSOR[PSUB][i] = 0;
        ee.RSPEED[PSUB][i] = 0;
        ee.LSPEED[PSUB][i] = 0;
        ee.COUNTERMODE[PSUB][i] = TIMER;
        ee.COUNTER[PSUB][i] = 0;
        ee.VA[PSUB][i] = 50;
        ee.COUNTA[PSUB][i] = 0;
        ee.COUNTERAMODE[PSUB][i] = TIMER;
        ee.VB[PSUB][i] = 50;
        ee.COUNTB[PSUB][i] = 0;
        ee.COUNTERBMODE[PSUB][i] = TIMER;
        ee.pid[PSUB][i] = 2;
        ee.FOLLOWMODE[PSUB][i] = FLC;
        ee.JUMP[PSUB][i] = off;
        ee.jumpP[PSUB][i] = 0;
        ee.jumpI[PSUB][i] = 0;
      }
      lcd.draw1x2String(0, 2, "    Success!    ");
      lcd.draw1x2String(0, 4, "     Erased     ");
      delay(1000);
      lcd.clear();
    }
    if (!BACK) break;
  }
  lcd.clear();
  while (!BACK) {
    delay(50);
  }
}

void setPid() {
  int8_t index = 0;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 5;
    }
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 5) index = 0;
    }
    lcd.draw1x2String(0, 0, "PID Default:");
    lcd.drawString(0, 3, "Kp:"); lcd.drawString(8, 3, "Max:");
    lcd.drawString(0, 4, "Kd:"); lcd.drawString(8, 4, "Min:");
    lcd.drawString(0, 5, "Ts:");
    switch (index) {
      case 0:
        choose(1); sprintf(buff, "%1d", ee.PID + 1); lcd.draw1x2String(12, 0, buff);
        choose(0); sprintf(buff, "%03d", ee.kp[ee.PID]); lcd.drawString(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.kd[ee.PID]); lcd.drawString(3, 4, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmax); lcd.drawString(12, 3, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmin); lcd.drawString(12, 4, buff);
        choose(0); sprintf(buff, "%03d", ee.Ts); lcd.drawString(3, 5, buff);
        if (!PLUS) {
          while (!PLUS) {}
          if (++ee.PID > 2) ee.PID = 0;
        }
        if (!MIN) {
          while (!MIN) {}
          if (--ee.PID < 0) ee.PID = 2;
        }
        break;
      case 1:
        choose(0); sprintf(buff, "%1d", ee.PID + 1); lcd.draw1x2String(12, 0, buff);
        choose(1); sprintf(buff, "%03d", ee.kp[ee.PID]); lcd.drawString(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.kd[ee.PID]); lcd.drawString(3, 4, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmax); lcd.drawString(12, 3, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmin); lcd.drawString(12, 4, buff);
        choose(0); sprintf(buff, "%03d", ee.Ts); lcd.drawString(3, 5, buff);
        if (!PLUS) {
          if (++ee.kp[ee.PID] > 255) ee.kp[ee.PID] = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.kp[ee.PID] < 0) ee.kp[ee.PID] = 255;
          delay(50);
        }
        break;
      case 2:
        choose(0); sprintf(buff, "%1d", ee.PID + 1); lcd.draw1x2String(12, 0, buff);
        choose(0); sprintf(buff, "%03d", ee.kp[ee.PID]); lcd.drawString(3, 3, buff);
        choose(1); sprintf(buff, "%03d", ee.kd[ee.PID]); lcd.drawString(3, 4, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmax); lcd.drawString(12, 3, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmin); lcd.drawString(12, 4, buff);
        choose(0); sprintf(buff, "%03d", ee.Ts); lcd.drawString(3, 5, buff);
        if (!PLUS) {
          if (++ee.kd[ee.PID] > 255) ee.kd[ee.PID] = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.kd[ee.PID] < 0) ee.kd[ee.PID] = 255;
          delay(50);
        }
        break;
      case 3:
        choose(0); sprintf(buff, "%1d", ee.PID + 1); lcd.draw1x2String(12, 0, buff);
        choose(0); sprintf(buff, "%03d", ee.kp[ee.PID]); lcd.drawString(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.kd[ee.PID]); lcd.drawString(3, 4, buff);
        choose(1); sprintf(buff, "%04d", ee.Vmax); lcd.drawString(12, 3, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmin); lcd.drawString(12, 4, buff);
        choose(0); sprintf(buff, "%03d", ee.Ts); lcd.drawString(3, 5, buff);
        if (!PLUS) {
          if (++ee.Vmax > 100) ee.Vmax = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.Vmax < 0) ee.Vmax = 100;
          delay(50);
        }
        break;
      case 4:
        choose(0); sprintf(buff, "%1d", ee.PID + 1); lcd.draw1x2String(12, 0, buff);
        choose(0); sprintf(buff, "%03d", ee.kp[ee.PID]); lcd.drawString(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.kd[ee.PID]); lcd.drawString(3, 4, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmax); lcd.drawString(12, 3, buff);
        choose(1); sprintf(buff, "%04d", ee.Vmin); lcd.drawString(12, 4, buff);
        choose(0); sprintf(buff, "%03d", ee.Ts); lcd.drawString(3, 5, buff);
        if (!PLUS) {
          if (++ee.Vmin > 0) ee.Vmin = -100;
          delay(50);
        }
        if (!MIN) {
          if (--ee.Vmin < -100) ee.Vmin = 0;
          delay(50);
        }
        break;
      case 5:
        choose(0); sprintf(buff, "%1d", ee.PID + 1); lcd.draw1x2String(12, 0, buff);
        choose(0); sprintf(buff, "%03d", ee.kp[ee.PID]); lcd.drawString(3, 3, buff);
        choose(0); sprintf(buff, "%03d", ee.kd[ee.PID]); lcd.drawString(3, 4, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmax); lcd.drawString(12, 3, buff);
        choose(0); sprintf(buff, "%04d", ee.Vmin); lcd.drawString(12, 4, buff);
        choose(1); sprintf(buff, "%03d", ee.Ts); lcd.drawString(3, 5, buff);
        if (!PLUS) {
          if (++ee.Ts > 255) ee.Ts = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.Ts < 0) ee.Ts = 255;
          delay(50);
        }
        break;
    }
    choose(1); lcd.drawString(12, 7, "Back"); choose(0);
    if (!BACK) break;
  }
  lcd.clear();
  while (!BACK) {
    delay(50);
  }
}

void setGripper() {
  int8_t index = 0;
  lcd.clear();
  while (!OK) {
    delay(50);
  }
  while (1) {
    if (!UP) {
      while (!UP) {}
      if (--index < 0) index = 4;
    }
    if (!DOWN) {
      while (!DOWN) {}
      if (++index > 4) index = 0;
    }
    lcd.drawString(2, 0, "DROP"); lcd.drawString(10, 0, "PICK");
    lcd.drawString(0, 2, "SV1:"); lcd.drawString(9, 2, "SV1:");
    lcd.drawString(0, 3, "SV2:"); lcd.drawString(9, 3, "SV2:");
    lcd.drawString(4, 4, "Dly:");
    switch (index) {
      case 0:
        choose(1); sprintf(buff, "%3d", ee.SV1[0]); lcd.drawString(4, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[0]); lcd.drawString(4, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.SV1[1]); lcd.drawString(13, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[1]); lcd.drawString(13, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.Dly); lcd.drawString(8, 4, buff);
        servoR.write(ee.SV1[0]);
        servoL.write(ee.SV2[0]);
        if (!PLUS) {
          if (++ee.SV1[0] > 180) ee.SV1[0] = 180;
          delay(50);
        }
        if (!MIN) {
          if (--ee.SV1[0] < 0) ee.SV1[0] = 0;
          delay(50);
        }
        break;
      case 1:
        choose(0); sprintf(buff, "%3d", ee.SV1[0]); lcd.drawString(4, 2, buff);
        choose(1); sprintf(buff, "%3d", ee.SV2[0]); lcd.drawString(4, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.SV1[1]); lcd.drawString(13, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[1]); lcd.drawString(13, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.Dly); lcd.drawString(8, 4, buff);
        servoR.write(ee.SV1[0]);
        servoL.write(ee.SV2[0]);
        if (!PLUS) {
          if (++ee.SV2[0] > 180) ee.SV2[0] = 180;
          delay(50);
        }
        if (!MIN) {
          if (--ee.SV2[0] < 0) ee.SV2[0] = 0;
          delay(50);
        }
        break;
      case 2:
        choose(0); sprintf(buff, "%3d", ee.SV1[0]); lcd.drawString(4, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[0]); lcd.drawString(4, 3, buff);
        choose(1); sprintf(buff, "%3d", ee.SV1[1]); lcd.drawString(13, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[1]); lcd.drawString(13, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.Dly); lcd.drawString(8, 4, buff);
        servoR.write(ee.SV1[1]);
        servoL.write(ee.SV2[1]);
        if (!PLUS) {
          if (++ee.SV1[1] > 180) ee.SV1[1] = 180;
          delay(50);
        }
        if (!MIN) {
          if (--ee.SV1[1] < 0) ee.SV1[1] = 0;
          delay(50);
        }
        break;
      case 3:
        choose(0); sprintf(buff, "%3d", ee.SV1[0]); lcd.drawString(4, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[0]); lcd.drawString(4, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.SV1[1]); lcd.drawString(13, 2, buff);
        choose(1); sprintf(buff, "%3d", ee.SV2[1]); lcd.drawString(13, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.Dly); lcd.drawString(8, 4, buff);
        servoR.write(ee.SV1[1]);
        servoL.write(ee.SV2[1]);
        if (!PLUS) {
          if (++ee.SV2[1] > 180) ee.SV2[1] = 180;
          delay(50);
        }
        if (!MIN) {
          if (--ee.SV2[1] < 0) ee.SV2[1] = 0;
          delay(50);
        }
        break;
      case 4:
        choose(0); sprintf(buff, "%3d", ee.SV1[0]); lcd.drawString(4, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[0]); lcd.drawString(4, 3, buff);
        choose(0); sprintf(buff, "%3d", ee.SV1[1]); lcd.drawString(13, 2, buff);
        choose(0); sprintf(buff, "%3d", ee.SV2[1]); lcd.drawString(13, 3, buff);
        choose(1); sprintf(buff, "%3d", ee.Dly); lcd.drawString(8, 4, buff);
        if (!PLUS) {
          if (++ee.Dly > 999) ee.Dly = 0;
          delay(50);
        }
        if (!MIN) {
          if (--ee.Dly < 0) ee.Dly = 999;
          delay(50);
        }
        break;
    }
    choose(1); lcd.drawString(12, 7, "Back"); choose(0);
    if (!BACK) break;
  }
  lcd.clear();
  while (!BACK) {
    delay(50);
  }
}

void invers_menu(int8_t invers_mode) {
  switch (invers_mode) {
    case off: lcd.drawTile(4, 4, 1, uncheck); break;
    case on: lcd.drawTile(4, 4, 1, checked); break;
  }
  lcd.drawString(5, 4, "Invers");
}
