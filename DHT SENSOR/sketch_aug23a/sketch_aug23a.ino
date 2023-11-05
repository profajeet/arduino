#include <DHT.h>
#define DHTPIN A0  // digital pin connection
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(9600);
  dht.begin();
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
}
