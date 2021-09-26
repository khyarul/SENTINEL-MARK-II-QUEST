void setMotor(int16_t L, int16_t R) {
  if (L > 0) {
    digitalWrite(PB5, 0);
  }
  else {
    L = L + 255;
    digitalWrite(PB5, 1);
  }
  analogWrite(pwmL, L);
  if (R > 0) {
    digitalWrite(PB8, 0);
  }
  else {
    R = R + 255;
    digitalWrite(PB8, 1);
  }
  analogWrite(pwmR, R);
}

void initMotor() {
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
}
