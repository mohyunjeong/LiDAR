#include <Wire.h>

void setup() {
  Serial.begin(9600);

  // I2C 통신 초기화 (0을 보냄)
  Wire.begin();

  for (byte i = 1; i < 120; i ++) {
    Wire.beginTransmission(i);

    // I2C 통신이 연결 중이라면

    if (Wire.endTransmission() == 0) {
      Serial.print("Address : ");
      Serial.print("0x");
      Serial.println(i, HEX);

      delay(10);
    }
  }
}

void loop() {
}
