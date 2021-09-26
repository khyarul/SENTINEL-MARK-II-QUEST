//encoder 22 PPR

void initEncoder() {
  pinMode(PA14, INPUT_PULLDOWN);
  pinMode(PA15, INPUT_PULLDOWN);
  pinMode(PB3, INPUT_PULLDOWN);
  pinMode(PB4, INPUT_PULLDOWN);
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
  int8_t en1L = digitalRead(PA14);
  int8_t en2L = digitalRead(PA15);
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
  int8_t en1R = digitalRead(PB3);
  int8_t en2R = digitalRead(PB4);
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
