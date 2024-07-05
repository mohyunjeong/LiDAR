#include <Wire.h>

 const byte address = 0x3F;

 void setup() {
    Serial.begin(9600);
    Serial.println("I2C test !!");

    Wire.begin(address);      // 해당 주소를 사용하여 I2C 버스에 연결
    Wire.onReceive(receiveEvent);  // 요청을 처리할 이벤트를 등록

    pinMode(7, OUTPUT);
 }

 void loop() { 
    delay(500);
 }

 void receiveEvent(int howMany) {
    while(Wire.available() ) {   // 데이터가 있으면
      char c = Wire.read();      // 데이터를 읽음
      Serial.println(c);         // 읽은 값 시리얼 모니터에 출력
      if (c == '1') {
        digitalWrite(7, HIGH);
      } else if (c == '0') {
        digitalWrite(7, LOW);
      }
    }
 }