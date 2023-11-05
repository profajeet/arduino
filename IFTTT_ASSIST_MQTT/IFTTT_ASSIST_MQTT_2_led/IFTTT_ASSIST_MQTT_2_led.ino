#include<Adafruit_MQTT_Client.h>
#include<ESP8266WiFi.h>
#define wifi_name "Extreme 1"

#define pswd "BeExtreme" 
#define server "io.adafruit.com"

#define port 1883

#define username "extreme_1" 
#define aiokey "aio_Ojpe69j1sZ5dSj9T01iyE66xkHoD"
int trig=0;
int led1 = D1;
int led2 = D2;
WiFiClient me;
Adafruit_MQTT_Client mqtt(&me, server, port, username, aiokey);
Adafruit_MQTT_Subscribe ledfeed1= Adafruit_MQTT_Subscribe(&mqtt,username"/feeds/ifttt");
Adafruit_MQTT_Subscribe ledfeed2 = Adafruit_MQTT_Subscribe(&mqtt,username"/feeds/led2");
void setup()
{
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
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
Serial.println("Connecting to MQTT");
while(mqtt.connect())
{
  Serial.println(".");
  }
 Serial.print("Connected to MQTT");
}

void loop()
{
  MQTT_connect();
  Adafruit_MQTT_Subscribe *subscription;
  while((subscription = mqtt.readSubscription(500))){
    if (subscription == &ledfeed1)
      {
    Serial.print ("Got:");
    Serial.print((char *)ledfeed1.lastread); 
    int trig = atoi((char *)ledfeed1.lastread); 
    Serial.println(trig);
    if (trig == 1)
    {
    digitalWrite (led1, HIGH);
    delay (10000);
    digitalWrite(led1, LOW);
      }
    delay (1000);
    }
    if (subscription == &ledfeed2) {
      Serial.print(F("Got: "));
      Serial.println((char *)ledfeed1.lastread);
      int led_state= atoi((char *)ledfeed2.lastread);
     if(led_state==1){
      digitalWrite(led2, HIGH);
      delay(10000);
      digitalWrite(led2, LOW);
     }
     delay(2000);
    }  
  }  
}

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
