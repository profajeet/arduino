#include<Adafruit_MQTT_Client.h>
#include "Adafruit_MQTT.h"
#include<ESP8266WiFi.h>
#define wifi_name "Extreme 1"

#define pswd "BeExtreme" 
#define server "io.adafruit.com"

#define port 1883

#define username "extreme_1" 
#define aiokey "aio_Ojpe69j1sZ5dSj9T01iyE66xkHoD"
const int led = D2;
const int IR =D1;
WiFiClient me;
Adafruit_MQTT_Client mqtt(&me, server, port, username, aiokey);
Adafruit_MQTT_Publish IR_data = Adafruit_MQTT_Publish(&mqtt,username"/feeds/IR_data");

void setup()
{
pinMode (led, OUTPUT);
pinMode(IR,INPUT);

Serial.begin(9600);
delay(10);
pinMode(16,OUTPUT);
Serial.println("Connecting to ");
Serial.print (wifi_name);
WiFi.begin (wifi_name, pswd);

while (WiFi.status () != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("IP Address is :");
Serial.println (WiFi.localIP());
Serial.print("Connecting to MQTT");
while(mqtt.connect())
{
  Serial.print(".");
  }
 Serial.print("Connected   to MQTT");
}

void loop()
{
   int IR_state = analogRead(IR);
if ( mqtt.connected())
  {
      Serial.println(IR_state);
      Serial.print("...");
    if(IR_data.publish(IR_state))
  {
    Serial.println("Success");
    digitalWrite(led, HIGH);
  }
  else
  {
    Serial.println("Trying");
    digitalWrite(led,LOW);
  }
 }
delay(2000);
}
