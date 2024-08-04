#include "HomeSpan.h"
#include <HardwareSerial.h>
#include "DEV_Sensors.h"

uint8_t buffer[32];
float pm1_0 = 0.0;
float pm2_5 = 0.0;
float pm10 = 0.0;
//unsigned long previousMillis = 0;
//unsigned long currentMillis = millis();  // Get the current time



void setup() {

  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);  // start UART on Serial2 at 9600 8N1. RX is pin 16, and is used for reading sensor. Pin 17 unused.
  Serial.println("initiating");
  Serial.println("- - -");

  homeSpan.begin(Category::Sensors,"VINDRIKTNING");
  //homeSpan.setSerialInputDisable(true);
  //homeSpan.enableOTA();
  Span& enableAutoStartAP();

    new SpanAccessory(); 
      new Service::AccessoryInformation();
        new Characteristic::Identify(); 
        new Characteristic::Name("Air Quality Sensor");
        new Characteristic::Manufacturer("IKEA");  
        new Characteristic::Model("VINDRIKTNING");
        new Characteristic::FirmwareRevision("0.1");
  
      new DEV_AirQualitySensor();                                                          // Create an Air Quality Sensor (see DEV_Sensors.h for definition)
    
  new SpanUserCommand('t',"<num> - set PM2.5 Sensor in homekit with <num>",sensorOfflineTest);
  new SpanUserCommand('p',"Print Sensor Values",printSensorData);



}

void loop() {

  homeSpan.poll();
  SerialRecieve();
  //currentMillis = millis();  // Get the current time
  //if (currentMillis - previousMillis >= 28000) {SerialRecieve();}

}