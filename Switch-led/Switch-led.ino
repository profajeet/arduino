#define ledPin 6 // choose the pin for the LED 
#define switchPin 5 // choose the input pin (for a pushbutton)
 
int val = 0; // variable for reading the pin status

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(switchPin, INPUT); // declare pushbutton as input
}

void loop()
{
  val = digitalRead(switchPin); // read input value
  Serial.println(val);
  delay(500);
  if (val == HIGH)
  { // check if the input is HIGH (button released)
    digitalWrite(ledPin, HIGH); // turn LED ON
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF } }
  }
}
