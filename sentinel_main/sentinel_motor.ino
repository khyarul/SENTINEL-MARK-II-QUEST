void setMotor(int16_t L, int16_t R) {
  if (L > 0) {
    digitalWrite(PB5, 0); //gpio_write_bit(GPIOB, 8, LOW);
  }
  else {
    L = L + 255;
    digitalWrite(PB5, 1); //gpio_write_bit(GPIOB, 8, HIGH);
  }
  analogWrite(pwmL, L);
  if (R > 0) {
    digitalWrite(PB8, 0); //gpio_write_bit(GPIOA, 8, LOW);
  }
  else {
    R = R + 255;
    digitalWrite(PB8, 1); //gpio_write_bit(GPIOA, 8, HIGH);
  }
  analogWrite(pwmR, R);
}

void initMotor() {
  pinMode(dirL, OUTPUT);
  pinMode(dirR, OUTPUT);
}
