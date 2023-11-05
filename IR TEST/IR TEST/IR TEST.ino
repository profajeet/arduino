const int ir = D1;
const int LED = D2;
void setup() 
{
  pinMode(ir,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
    
  int value = digitalRead(ir);
  Serial.println(value);
  if(value==1)
  {
    digitalWrite(LED, HIGH);
  }else
  digitalWrite(LED, LOW);

}
