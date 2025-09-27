// 핀 설정
const int trigPin = 5;  // Trig 핀 (GPIO 5, D1)
const int echoPin = 4;  // Echo 핀 (GPIO 4, D2)
const int ledPin = 2;   
// LED 핀 (GPIO 2, D4) 
// 설정된 거리 (센서가 물체를 감지할 거리, cm 단위)
const int distanceThreshold = 15;  // 10cm 이내에 물체가 들어오면 LED 켜짐 
void setup() { 
// 핀 모드 설정 
pinMode(trigPin, OUTPUT);   
pinMode(echoPin, INPUT); 
pinMode(ledPin, OUTPUT); 
// 시리얼 통신 시작 
Serial.begin(115200); 
} 
void loop() { 
// 초음파 센서로 거리 측정 
long duration, distance; 
// Trig 핀을 10us 동안 HIGH로 설정하여 초음파 발사 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW); 
// Echo 핀으로부터 반사된 초음파를 받는 시간 측정 
duration = pulseIn(echoPin, HIGH); 
// 시간(duration)을 이용해 거리 계산 (cm 단위) 
distance = (duration / 2) / 29.1; 
// 시리얼 모니터에 거리 출력 
Serial.print("Distance: "); 
Serial.print(distance); 
Serial.println(" cm"); 
// 거리 판단하여 LED 제어 
if (distance <= distanceThreshold) { 
digitalWrite(ledPin, HIGH);  // LED 켬 
  } 
else { 
digitalWrite(ledPin, LOW);   
// LED 끔 
  } 
delay(500);  // 0.5초 대기 
}