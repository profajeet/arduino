#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Bjer-qgV3NHZTb9Isu8Uz1otxVPOEAqm";

char ssid[] = "HP";
char pass[] = "0123456789";
void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
}

void loop()
{
  Blynk.run();
}
