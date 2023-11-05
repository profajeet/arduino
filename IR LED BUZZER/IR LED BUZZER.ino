const int ir = D1;
const int LED = D2;
const int buzzer = D3;
void setup() 
{
  pinMode(ir,INPUT);
  pinMode(LED,OUTPUT);
    pinMode(buzzer, OUTPUT);
 Serial.begin(9600);
}
void loop()
{
    
  int value = digitalRead(ir);
  Serial.println(value);
  if(value==1)
  {
    digitalWrite(LED, LOW);
  }else
  digitalWrite(LED, HIGH);
  tone(buzzer, 1000); 
  delay(5000);       
  noTone(buzzer);    
  delay(5000);  


}
er
