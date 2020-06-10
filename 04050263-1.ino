#include <Ultrasonic.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 13
Ultrasonic ultrasonic(12,13);
void setup() {
Serial.begin(9600);
}
void loop(){
float cmMsec, inMsec;

cmMsec = ultrasonic.read(CM); // 計算距離，單位: 公分


Serial.print("CM: "); 
Serial.print(cmMsec);

delay(1000);
}
