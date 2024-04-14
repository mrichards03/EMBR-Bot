bool toggle;
#define RXD2 16
#define TXD2 17
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(57600, SERIAL_8N1, RXD2, TXD2);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!toggle){
    Serial2.write(1);
    Serial.println(1);
    toggle = true;
  }
  delay(250);
  if(toggle){
    Serial2.write(0);
    Serial.println(0);
    toggle = false;
  }
  delay(250);
}
