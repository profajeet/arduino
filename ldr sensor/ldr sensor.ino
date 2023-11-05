int sensorPin=A0;
int threshold=300;
int led=D0;
void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
}
void loop()
{
  int value=analogRead(sensorPin);
  Serial.println(value);
  delay(500);
  if(value<=threshold)
  {
    digitalWrite(led,HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
