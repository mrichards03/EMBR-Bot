int num = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    num = Serial.read();
    if(num == 1){
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
    }
    if(num == 0){
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
    }
  }
}
