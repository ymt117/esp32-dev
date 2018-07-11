HardwareSerial gps(0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start");
  gps.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(gps.available()){
    Serial.write(gps.read());
  }
}
