#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>
#include <DHT.h>
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const char wname[] = "Ajeet_Sharma";
const char pass[]= "sharma123";
const char token[]="7TFmf0MpXCaZD5jlUcyThqCmEJBvfWbV";
const int buzzer =D2; 
void setup()
{
  
  Serial.begin(9600);
   Blynk.begin(token,wname,pass);
  dht.begin();
    pinMode(buzzer, OUTPUT);
}
void loop()
{
  
  float temp = dht.readTemperature();
  int humidity = dht.readHumidity();
  float tempF = dht.readTemperature(true);
  delay(1000);
  Serial.println();
  Serial.print("Temperature(C) =");
  Serial.print(temp);
  Serial.println();
  Serial.print("Temperature(F) =");
  Serial.print(tempF);
  Serial.println();
  Serial.print("Temperature(%) =");
  Serial.print(humidity);
  delay(1000);
if(temp>=30)
 tone(buzzer, 1000);
 else
 noTone(buzzer);     
Blynk.run();
}
