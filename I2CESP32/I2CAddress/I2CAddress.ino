#include <Wire.h>

const byte address = 0x3F; // 통신에서 사용할 주소

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    Wire.beginTransmission(address); // 통신 주소를 설정한다

    Serial.println(c); // 데이터를 슬레이브 장치로 전송한다

    Wire.write(c); // 데이터 전송을 종료한다
    Wire.endTransmission();
  }
}
