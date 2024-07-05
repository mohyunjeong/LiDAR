#include <Wire.h>

const byte address = 0x3F; // 통신에서 사용할 주소

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  int val = analogRead(39);

  Wire.beginTransmission(address);

  Serial.println(val);

  Wire.println(val);
  Wire.endTransmission();

  delay(1000);
}
