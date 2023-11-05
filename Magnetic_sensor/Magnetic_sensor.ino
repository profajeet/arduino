const int hall_Sensor=D1;
int inputVal = 0;

void setup() 
{                
  pinMode(D0, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:  
  pinMode(hall_Sensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(hall_Sensor)==HIGH)      //Check the sensor output
  {
    digitalWrite(D0, HIGH);   // set the LED on
  }
  else
  {
    digitalWrite(D0, LOW);    // set the LED off
  }
inputVal = digitalRead(hall_Sensor);
Serial.println(inputVal);
delay(1000);              // wait for a second
}
