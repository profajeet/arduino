void setup() {
  pinMode(D0,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(D0));

}
