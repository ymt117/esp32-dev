// 参考：http://deviceplus.jp/hobby/entry060/

#include <TinyGPS++.h>
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
HardwareSerial ss(0);

void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud);

  Serial.println(F("GPS test start!"));
}

void loop() {
  while(ss.available() > 0){
    char c = ss.read();
    gps.encode(c);
    if(gps.location.isUpdated()){
      Serial.print("Lat=\t");   Serial.print(gps.location.lat(), 6);
      Serial.print("Lng=\t");   Serial.print(gps.location.lng(), 6);
      Serial.print("Alt=\t");   Serial.println(gps.altitude.meters());
    }
  }

}
