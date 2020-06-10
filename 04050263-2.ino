#include <LWiFi.h>
#include <WiFiClient.h>
#include <Ultrasonic.h>
#include "MCS.h"
#define TRIGGER_PIN 12
#define ECHO_PIN 13
Ultrasonic ultrasonic(12,13);

#define _SSID "AA202_2G"
#define _KEY  "iteaa202"

// Assign device id / key of your test device
MCSDevice mcs("DfSlQ4fj", "PyhOXDXh0a2mbpOS");

MCSDisplayFloat  ECHO("ECHO");

void setup() {
  Serial.begin(9600);
  Serial.println(F("test!"));

  
  while(WL_CONNECTED != WiFi.status())
  {
    Serial.print("WiFi.begin(");
    Serial.print(_SSID);
    Serial.print(",");
    Serial.print(_KEY);
    Serial.println(")...");
    WiFi.begin(_SSID, _KEY);
  }
  Serial.println("WiFi connected !!");

  // setup MCS connection
 
  mcs.addChannel(ECHO);
  
  while(!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");

  // read LED value from MCS server
  
}

void loop() {
  // call process() to allow background processing, add timeout to avoid high cpu usage
  Serial.print("process(");
  Serial.print(millis());
  Serial.println(")");
  mcs.process(100);
  float cmMsec, inMsec;

cmMsec = ultrasonic.read(CM); // 計算距離，單位: 公分


Serial.print("CM: "); 
Serial.print(cmMsec);
delay(1000);

 if(!ECHO.set(cmMsec))
    {
      Serial.print("Failed to update remote");
      Serial.println(ECHO.value());
    }
      
    


  while(!mcs.connected())
  {
    Serial.println("re-connect to MCS...");
    mcs.connect();
    if(mcs.connected())
      Serial.println("MCS connected !!");
  }
}
