int sensorPin=A0;   //taking sensor on analog
int threshold=300;  //minimum value define
int led=D0;         //led define
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
