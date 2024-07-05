void setup() {
  Serial.begin(9600);

  pinMode(9, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int val = Serial.read();

    analogWrite(9, val);

    // if (val > 128) {
    //   digitalWrite(9, HIGH);
    // } else {
    //   digitalWrite(9, LOW);
    // }
  }
}
