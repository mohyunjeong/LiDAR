import processing.serial .*;

Serial port;

// 시작, 다음

int start, next;

// 수신된 값 저장

int data1, data2;

// 각도 값

float rot = 0.0;

// 이미지 객체

PImage img;

void setup() {
  
  // 사용 가능한 시리얼 포트 검색
  // Serial.list() : 사용 가능한 포트 리스트
  
  for (int i = 0; i < Serial.list().length; i++) {
    println("[" + i + "]" + Serial.list()[i]);
  }
  
  // 시리얼 포트 할당
  
  port = new Serial(this, Serial.list()[1], 9600);
  
  // 창 크기 설정
  // P3D : 3차원 화면
  
  size(512, 512, P3D);
  
  // 이미지 로드
  
  img = loadImage("wind.png");
  
}

void draw() {
  
  background(255);
  
  // 수신된 값을 읽어온다
  
  while (port.available() > 0) {
    // 시작/종료 비트 읽음
    
    int data = port.read();
    
    // 시작 비트라면
    
    if (data == 255)
      start = 1;
      
    // 종료 비트라면
    
    else if (data == 254)
      start = 0;
      
    // 시작 비트인 경우에 값 읽기
    
    if (start == 1) {
      
      // 첫 번째 값이라면 : 가변저항 값
      // 값 범위가 0 ~ 253이므로 화면 크기 512 x 512에 맞추기 위해서 2를 곱한다
      
      if (next == 1) data1 = data * 2;
      
      // 두 번째 값이라면 : 버튼 값
      
      else if (next == 2) data2 = data;
      
      next++;
    } else {
      next = 0;
    }
    
    // 읽은 값을 이용해서 이미지를 제어
    // 3D 화면에서 이미지 제어 시작
    
    pushMatrix();
    
    image(img, 256 - img.width / 2, 256 - img.height / 2);
    
    // 3D 화면에서 이미지 제어 종료
    
    popMatrix();
  }
  
}
