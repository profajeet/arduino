#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define led0 0               //D3
#define led1 2                //D4

int count = 0;
String safety_status = ""; 


DynamicJsonBuffer jsonBuffer;

const char *ssid      = "ssid";
const char *password  = "password";

int sensorValue0 = 0;        
int sensorValue1 = 0;        
      
String sensor_values;

ESP8266WebServer server(80);

void handleSentVar() {

  if (server.hasArg("sensor_reading"))
  {
    sensor_values = server.arg("sensor_reading");
    Serial.println(sensor_values);
  }
  JsonObject& root = jsonBuffer.parseObject(sensor_values);
//  if (!root.success()) {
//    Serial.println("parseObject() failed");
//    return;
//  }
//  if (root.success())
//  {
    sensorValue0          = root["sensor0_reading"].as<int>();
    sensorValue1          = root["sensor1_reading"].as<int>();

//  }

  Serial.println(sensorValue0);
  Serial.println(sensorValue1);


  toggle_leds();

  server.send(200, "text/html", "Data received");
}


void setup() {
  Serial.begin(9600);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("        Women \n\n     Safety Device \n\n        Ready");
  display.display(); 

  
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);

  
  //toggle_leds();                 //turn off all leds as all the sensor values are zero
  
  server.on("/data/", HTTP_GET, handleSentVar); // when the server receives a request with /data/ in the string then run the handleSentVar function
  server.begin();
}

void loop() {
  server.handleClient();
  delay(100);
}

void toggle_leds()
{
  if (count ==0){
  safety_status = "Secured";
  Serial.println("safety_status: " + safety_status );
  display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Women Safety Status \n\n " + safety_status);
  display.display(); 
  }
      
  Serial.print("COUNT--- ");
  Serial.println(count);
  if (sensorValue0 == 0)  digitalWrite(led0, LOW);
  if (sensorValue1 == 0)  digitalWrite(led1, LOW);


  if (sensorValue0 == 1) {
     digitalWrite(led0, HIGH);
     count = count + 1;
    }
  if (sensorValue1 == 1) {
     digitalWrite(led1, HIGH);
     count = 0;
    }

  if (count >1 && count <5){
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      // Display static text
      display.println("Women Safety Status \n\n ");
      display.setTextSize(2);
      display.println(" \t Alert");
      display.display(); 
//      delay(100);
     
  }
  if (count > 5){
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      // Display static text
      display.println("Women Safety Status \n\n");
      display.setTextSize(2);
      display.println("\t High \n \t Alert");
      display.display(); 
//      delay(100);
     
  }

  

}
