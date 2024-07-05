void setup() {
  Serial.begin(9600);

  pinMode(8, INPUT);
}

void loop() {
  int val1 = analogRead(A0);
  int val2 = digitalRead(8);

  // 읽은 값들을 프로세싱으로 전송
  // 문자열로 만들어서 보내는 방식 "val1 : val2"
  // 시작 비트 -> 값1, 값2 -> 종료 비트
  // 255를 시작 비트로 사용

  Serial.write(255);

  // 데이터 전송
  // 가변저항 값 전송 (0~253)
  // map(변수, 원 시작값, 원 종료값, 목표 시작값, 목표 종료값)

  Serial.write(map(val1, 0, 1024, 0, 253));

  // 버튼 값 전송

  Serial.write(val2);

  // 254를 종료 비트로 사용

  Serial.write(254);
}
