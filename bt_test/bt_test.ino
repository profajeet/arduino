int led = 5;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if(Serial.available()){
    digitalWrite(led, HIGH);
    delay(5000);
    }
   else{
    digitalWrite(led,LOW);
    }
  // put your main code here, to run repeatedly:

}
