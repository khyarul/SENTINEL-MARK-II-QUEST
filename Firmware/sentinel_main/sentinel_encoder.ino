//encoder 22 PPR

void initEncoder() {
  pinMode(PA14, INPUT_PULLDOWN); //line 14 PA14
  pinMode(PA15, INPUT_PULLDOWN); //line 15 PA15
  pinMode(PB3, INPUT_PULLDOWN); //line 15 PB15
  pinMode(PB4, INPUT_PULLDOWN); //line 14 PB14
  enc_ON();
}

void enc_ON() {
  attachInterrupt(PA14, enL, CHANGE);
  attachInterrupt(PA15, enL, CHANGE);
  attachInterrupt(PB3, enR, CHANGE);
  attachInterrupt(PB4, enR, CHANGE);
}

void enc_OFF() {
  detachInterrupt(PA14);
  detachInterrupt(PA15);
  detachInterrupt(PB3);
  detachInterrupt(PB4);
}

void enL() {
  int8_t en1L = digitalRead(PA14); //gpio_read_bit(GPIOA, 14) ? HIGH : LOW;
  int8_t en2L = digitalRead(PA15); //gpio_read_bit(GPIOA, 15) ? HIGH : LOW;
  if (en1L != last_en1L) {
    if (en2L != en1L) {
      lPos--;
    }
    else {
      lPos++;
    }
  }
  last_en1L = en1L;
}

void enR() {
  int8_t en1R = digitalRead(PB3);  //gpio_read_bit(GPIOB, 15) ? HIGH : LOW;
  int8_t en2R = digitalRead(PB4);  //gpio_read_bit(GPIOB, 14) ? HIGH : LOW;
  if (en1R != last_en1R) {
    if (en2R != en1R) {
      rPos--;
    }
    else {
      rPos++;
    }
  }
  last_en1R = en1R;
}
