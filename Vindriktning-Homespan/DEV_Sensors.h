//////////////////////////////////
//   DEVICE-SPECIFIC SERVICES   //
//////////////////////////////////


extern float pm1_0;
extern float pm2_5;
extern float pm10;

struct DEV_AirQualitySensor : Service::AirQualitySensor {

  SpanCharacteristic *airQuality; 
  SpanCharacteristic *pm2_5_HK; 
  SpanCharacteristic *pm10_HK; 
  SpanCharacteristic *SensorActive;

  DEV_AirQualitySensor() : Service::AirQualitySensor(){       // constructor() method
    
    airQuality = new Characteristic::AirQuality(0);
    pm2_5_HK = new Characteristic::PM25Density(0.0);
    pm10_HK = new Characteristic::PM10Density(0.0);
    SensorActive = new Characteristic::StatusActive(0);
  
  }

  void loop() {

    if (pm2_5 != pm2_5_HK->getVal()) {
      LOG1("\nHK update\n");
      if ((pm2_5 <= 0.0) || (pm2_5 > 1000.0)){
        SensorActive->setVal(0);
        airQuality->setVal(0);
        pm2_5_HK->setVal(0.0);
      } else {
        pm2_5_HK->setVal(pm2_5);
        SensorActive->setVal(1);
        if ((pm2_5 > 0.0) && (pm2_5 <= 12.0)) {
          airQuality->setVal(1);
        }
        if ((pm2_5 > 12.0) && (pm2_5 <= 35.4)) {
          airQuality->setVal(2);
        }
        if ((pm2_5 > 35.4) && (pm2_5 <= 55.4)) {
          airQuality->setVal(3);
        }
        if ((pm2_5 > 55.4) && (pm2_5 <= 100.0)) {
          airQuality->setVal(4);
        }
        if (pm2_5 > 100) {
          airQuality->setVal(5);
        }
      }
    }
    if (pm10 != pm10_HK->getVal()) {
      if ((pm10 <= 0.0) || (pm10 > 1000.0)){
        pm10_HK->setVal(0.0);
      } else {
        pm10_HK->setVal(pm10);
      }
    }

  }

};