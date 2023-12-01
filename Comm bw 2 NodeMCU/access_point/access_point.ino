#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

const char* ssid = "WOMEN_Safety_AP";
const char* password = "123456789";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

}

void loop() {
  // put your main code here, to run repeatedly:

}
