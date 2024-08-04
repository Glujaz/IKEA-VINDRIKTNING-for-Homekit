void SerialRecieve(){
  //Serial.println("reading for data");
   if (Serial2.available() >= 32) {
    Serial2.readBytes(buffer, 32);
    if (buffer[0] == 0x16 && buffer[1] == 0x11 && buffer[2] == 0x0B) {
      uint16_t pm1_0_raw = (buffer[4] << 8) | buffer[5];
      uint16_t pm2_5_raw = (buffer[5] << 8) | buffer[6];
      uint16_t pm10_raw = (buffer[8] << 8) | buffer[9];

      pm1_0 = static_cast<float>(pm1_0_raw);
      pm2_5 = static_cast<float>(pm2_5_raw);
      pm10 = static_cast<float>(pm10_raw);
      
      LOG1("\n- - -\n");
      LOG1("Valid data frame");
      LOG1("\n- - -\n");


      //previousMillis = currentMillis;  // Update the last action time

      
    } else {
      LOG1("\n- - -\n");
      LOG1("Invalid data frame");
      LOG1("\n- - -\n");

    }
  }

}

void sensorOfflineTest(const char *buf) {
  int n=atoi(buf+1);
  Serial.print("Setting PM Value for offline check to : ");
  Serial.println(n);
  if (n <=0.0) {pm2_5 = 0.0;pm10 = 0.0;}
  if ((n <=12.0) && (n >0.0)) {pm2_5 = n;pm10 = 1.2;}
  if ((n <=35.4) && (n >12.0)) {pm2_5 = n;pm10 = 2.2;}
  if ((n <=55.4) && (n >35.4)) {pm2_5 = n;pm10 = 3.2;}
  if ((n <=100.4) && (n >55.4)) {pm2_5 = n;pm10 = 4.2;}
  if ((n <=1000) && (n >100.4)) {pm2_5 = n;pm10 = 5.2;}
  if (n >1000) {pm2_5 = 1000;pm10 = 6.2;}
  Serial.print("Changed pm2_5 to ");
  Serial.print(pm2_5);
  Serial.print(" and pm10 to ");
  Serial.println(pm10);
  Serial.println("- - -");
}

void printSensorData(const char* command) {

  Serial.println("Current Values of the sensor are :");
  Serial.print("PM1.0: ");
  Serial.print(pm1_0);
  Serial.print(" µg/m³, PM2.5: ");
  Serial.print(pm2_5);
  Serial.print(" µg/m³, PM10: ");
  Serial.print(pm10);
  Serial.println(" µg/m³");
  Serial.println("- - -");


}