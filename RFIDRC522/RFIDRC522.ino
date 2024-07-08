#include <SPI.h>
#include <MFRC522.h>

// 리셋 핀 번호
#define RST_PIN 9

// I2C SDA 핀 번호
#define SS_PIN 10

// 모듈 설정
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();

  // RFID 모듈 초기화
  mfrc522.PCD_Init();

  // 연결 테스트 : 연결 되었다면 true를 반환
  bool result = mfrc522.PCD_PerformSelfTest();

  if (result)
    Serial.println("Connect !!");
  else
    Serial.println("Not Commect !!");
}

void loop() {
  // 새로운 카드인 경우에만 실행
  if (!mfrc522.PICC_IsNewCardPresent())
    return;
  // 태그 값을 읽었다면 실행
  if (!mfrc522.PICC_ReadCardSerial())
    return;

  // byte letter;
  String content = "";

  // 태그 값을 출력
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    // Serial.print(mfrc522.uid.uidByte[i], HEX);

    // 태그 값을 문자열에 저장 (2byte 데이터를 병합)
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  // Serial.println();

  // 동글란 : 83BFCA13, 카드 : 831984E2
  Serial.print(content);

  // ID를 대문자로 변화
  content.toUpperCase();

  if (content == "831984E2")
    Serial.println("Open !!");
  else
    Serial.println("Not Open !!");
}
