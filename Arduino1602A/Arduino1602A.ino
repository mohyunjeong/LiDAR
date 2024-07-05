#include <Wire.h>
// #include <LiquidCrystal_I2C.h>

const byte address = 0x3F;
// LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // lcd.init();
  // lcd.backlight();

  Serial.begin(9600);
  Serial.println("I2C test !!");

  Wire.begin(address);
  Wire.onReceive(receiveEvent);
}

void loop() {
  delay(500);
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read();

    Serial.print(c);

    // lcd.setCursor(0, 1);
    // lcd.print(c);
  }
}
