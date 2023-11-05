#include<Adafruit_MQTT_Client.h>
#include "Adafruit_MQTT.h"
#include<ESP8266WiFi.h>
#define wifi_name "Extreme 1"

#define pswd "BeExtreme" 
#define server "io.adafruit.com"

#define port 1883

#define username "extreme_1" 
#define aiokey "aio_Ojpe69j1sZ5dSj9T01iyE66xkHoD"
int trig=0;
int led = D2;
WiFiClient me;
Adafruit_MQTT_Client mqtt(&me, server, port, username, aiokey);
Adafruit_MQTT_Subscribe feed = Adafruit_MQTT_Subscribe(&mqtt,username"/feeds/ifttt");
void setup()
{
pinMode (led, OUTPUT);
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
if ( mqtt.readSubscription(500))
{
Serial.print ("Got:");

Serial.print((char *)feed.lastread);    
int trig = atoi((char *)feed.lastread); 
Serial.println(trig);
if (trig == 1)
{
digitalWrite (led, HIGH);
delay (10000);
digitalWrite(led, LOW);
}
delay (2000);
  }
}  
