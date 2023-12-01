#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <ESP8266WiFiMulti.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String safety_status ;


const char* ssid = "WOMEN_Safety_AP";
const char* password = "123456789";

const char* serverNameStatus = "http://192.168.4.1/status";



void setup() {
   Serial.begin(115200);
  Serial.println();
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  display.clearDisplay();
  display.setTextColor(WHITE);
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
  }

}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
      safety_status = httpGETRequest(serverNameTemp);
      Serial.println("safety_status: " + safety_status );
      display.clearDisplay();
      
      // display Status
      display.setTextSize(2);
      display.setCursor(0,0);
      display.print("safety_status: ");
      display.print(safety_status);
      display.print(" ");
      display.setTextSize(1);
      display.cp437(true);
      display.write(248);
      display.setTextSize(2);


}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
