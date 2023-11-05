/* const int 1 = D0;
const int 2 = D1;
const int 3 = D2;
const int 4 = D3;
const int 5 = D4;
const int buzzer = D5;
*/
const String D="D";
void setup()
{
 /* pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
   pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
 pinMode(l5,OUTPUT);
  pinMode(buzzer, OUTPUT); */
  for(int pin=1;pin<=6;pin++){
    const int thispin=D+pin;
    pinMode(thispin,OUTPUT);
    }
 
}
void loop()
{
 /* digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);
     digitalWrite(l3,LOW);
    digitalWrite(l4,HIGH);
    digitalWrite(l5,LOW);
  delay(50); //millisecond
  digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
     digitalWrite(l3,HIGH);
    digitalWrite(l4,LOW);
    digitalWrite(l5,HIGH);
  delay(50);
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(200);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(200);        // ...for 1sec
  */
  for(int pin=1;pin<=6;pin++){
    const int thispin=D+pin;
    digitalWrite(thispin,HIGH);
    delay(1000);
    }
}
