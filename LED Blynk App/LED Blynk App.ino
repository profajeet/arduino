#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
const char wname[] = "Extreme_One AV";
const char pass[]= "@%##*123";
const char token[]="_hog5kZ3P-uyTu0-o0spa0UapB6zhPnx";
const int led =D5;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(token,wname,pass);
  pinMode(led,OUTPUT);
}
void loop()
{
  Blynk.run();
}
