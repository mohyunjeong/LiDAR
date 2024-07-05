#include <Wire.h>

const byte address = 0x3F; // 통신에서 사용할 주소

void setup() {
  Serial.begin(9600);
  Serial.println("I2C test !!");

  Wire.begin(address);
  Wire.onReceive(receiveEvent);
}

void loop() {
  delay(500);
}

void receiveEvent(int howMany) {
  while(Wire.available()) {
    char c = Wire.read();
    Serial.println(c);
  }
}
