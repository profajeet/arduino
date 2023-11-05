#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include<SimpleTimer.h>
#include<Adafruit_SSD1306.h>
#include<Wire.h>
#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 oled(OLED_RESET);
const char wname[] = "Ajeet_Sharma";
const char pass[]= "sharma123";
const char token[]="7TFmf0MpXCaZD5jlUcyThqCmEJBvfWbV";
const int sensorPin=D3;
const int ledPin = D7;
const int ldrPin = A0;
void abcd()
{
   int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 400) {

digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);
oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.setCursor(20,20);
  oled.print("Darkness!! Light on ");
  oled.display();
  delay(10);
   oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.setCursor(20,20);
  oled.print("Obstacle,Beep!! & Light ");
  oled.display();
  delay(10);
   oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.setCursor(20,20);
  oled.print("G ass. switching");
  oled.display();
  delay(10);
   oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setTextSize(1);
  oled.setCursor(20,20);
  oled.print("Blynk app Switching ");
  oled.display();
  delay(10);
}
  int value=digitalRead(sensorPin);
  if(value==0)
  {
    Blynk.notify("Warning!!! Someone ahead!!!");
    Blynk.email("sagarpandey2709117@gmail.com","Warning!!!","Warning!!! Someone ahead!!!");
    
  }
}

void setup()
{
  
oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.clearDisplay();
SimpleTimer timer;

  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
  Blynk.begin(token,wname,pass);
  timer.setInterval(1000L,abcd);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
   
}
void loop()
{
  Blynk.run();
  timer.run();
 
}
