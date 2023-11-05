// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>
Servo name_servo;
boolean flag= false;

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int IR = 6;
const int BUZZ= 9;
const int RED= 8;
const int GREEN= 7;
const int SW= 13;
void setup() 
{
  Serial.begin(9600);
  pinMode(IR,INPUT);
  pinMode(BUZZ,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(SW,INPUT);
    name_servo.attach (10);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  // Clears the LCD screen
  lcd.clear();
}

void loop() 
{
boolean  detection= digitalRead(IR);

  // Print a message to the LCD.
  lcd.print(" DOOR    ");
  if(digitalRead(SW)==1){
    flag=false;
    }
  if(detection==0){
    flag=true;
    }
   
if(flag== true){
  
  Serial.println(detection);
  lcd.setCursor(0, 1); // Print a message to the LCD.
  lcd.print ("OPEN, person Detected");
  name_servo.write(180);
  digitalWrite(RED,HIGH);
  digitalWrite(GREEN,LOW);
  tone(BUZZ,1000);
  delay(1000);
  }
 else if(flag==false){
  
  Serial.println(detection);
  lcd.setCursor(0, 1); // Print a message to the LCD.
  lcd.print ("CLOSED");
  name_servo.write(0);
  noTone(BUZZ);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,HIGH);
  lcd.print ("          ");
  delay(1000);
  }
  
}
