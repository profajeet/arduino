#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG
#define USE_NODE_MCU_BOARD

// define the GPIO connected with LED 
#define LED1 5  //D1
#define LED2 4  //D2
#define LED3 14 //D5

#define wifiLed   16   //D0

//Change the virtual pins according the rooms
#define VPIN_BUTTON_1    V1
#define VPIN_BUTTON_2    V2
#define VPIN_BUTTON_3    V3 

// LED State
bool LED_1 = LOW; //Define integer to remember the toggle state for LED 1
bool LED_2 = LOW; //Define integer to remember the toggle state for LED 2
bool LED_3 = LOW; //Define integer to remember the toggle state for LED 3

#include "BlynkEdgent.h"

BLYNK_CONNECTED() {
  // Request the latest state from the server
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
  Blynk.syncVirtual(VPIN_BUTTON_3);
}

BLYNK_WRITE(VPIN_BUTTON_1) {
  LED_1 = param.asInt();
  if(LED_1 == 1){
    digitalWrite(LED1, LOW);
  }
  else { 
    digitalWrite(LED1, HIGH);
  }
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  LED_2 = param.asInt();
  if(LED_2 == 1){
    digitalWrite(LED2, LOW);
  }
  else { 
    digitalWrite(LED2, HIGH);
  }
}

BLYNK_WRITE(VPIN_BUTTON_3) {
  LED_3 = param.asInt();
  if(LED_3 == 1){
    digitalWrite(LED3, LOW);
  }
  else { 
    digitalWrite(LED3, HIGH);
  }
}
void setup() {
 Serial.begin(115200);
  delay(100);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(wifiLed, OUTPUT);

    //During Starting all LED should TURN OFF
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(wifiLed, HIGH);

   BlynkEdgent.begin();
  Blynk.virtualWrite(VPIN_BUTTON_1, LED_1);
  Blynk.virtualWrite(VPIN_BUTTON_2, LED_2);
  Blynk.virtualWrite(VPIN_BUTTON_3, LED_3);
}

void loop() {
  BlynkEdgent.run();
}
