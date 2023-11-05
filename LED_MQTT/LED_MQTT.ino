#include<Adafruit_MQTT_Client.h>
#include "Adafruit_MQTT.h"
#include<ESP8266WiFi.h>
#define wifi_name "Extreme 1"

#define pswd "Be  Extreme" 
#define server "io.adafruit.com"

#define port 1883

#define username "extreme_1" 
#define aiokey "aio_Ojpe69j1sZ5dSj9T01iyE66xkHoD"
int trig=0;
const int led = D2;
WiFiClient me;
Adafruit_MQTT_Client mqtt(&me, server, port, username, aiokey);
Adafruit_MQTT_Subscribe led_iot = Adafruit_MQTT_Subscribe(&mqtt,username "/feeds/led-iot");
//Adafruit_MQTT_Subscribe lediot = Adafruit_MQTT_Subscribe(&mqtt, led_iot);
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

 mqtt.subscribe(&led_iot);
}

void loop()
{
 MQTT_connect();
Adafruit_MQTT_Subscribe *subscription;
while (subscription = mqtt.readSubscription(5000)) {
    // Check if its the onoff button feed
    
    if (subscription == &led_iot) {
      Serial.print(F("On-Off button: "));
      Serial.println((char *)led_iot.lastread);
       if (strcmp((char *)led_iot.lastread, "ON") ==0) {
        digitalWrite(led, HIGH); 
        delay(1000);
      }
      else{
        digitalWrite(led, LOW); 
        delay(1000);
      }
    }
}
// ping the server to keep the mqtt connection alive
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }
}
//MQTT connect function declation
void MQTT_connect() {
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
  Serial.println("MQTT Connected!");  
}
// Alternate Logic
  
//int trig = atoi((char *)lediot.lastread); 
//Serial.println(trig);
//if (trig == 1)
//{
//digitalWrite (led, HIGH);
//delay(2000);
//}
//else{
//  digitalWrite(led, LOW);
//  delay(2000);
//  }
//delay (2000);
//  }
