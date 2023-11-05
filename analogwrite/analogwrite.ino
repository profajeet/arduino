int ledPin = D0;      // LED connected to digital pin 9

int analogPin = A0;   // potentiometer connected to analog pin 3

int val = 0;         // variable to store the read value



void setup()

{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);   // sets the pin as output

}



void loop()

{

  val = analogRead(analogPin);   // read the input pin
 int data = map(val,0,1024,0,255);
  analogWrite(ledPin, data);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  Serial.println(data);
}
