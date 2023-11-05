/*
 ESP8266 ESP-12E (Nodemcu 1.0) Receiver code
*/
#include <RCSwitch.h>
const int redLed = 6;
RCSwitch mySwitch = RCSwitch();
void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  mySwitch.enableReceive(5);  // Connected to GPIO0 (D3) of Nodemcu 1.0 module
}
void loop() {
  int value = mySwitch.getReceivedValue();
  Serial.println(mySwitch.getReceivedValue());
  if (mySwitch.available()) {
    if (value == 5592368)
    {
    digitalWrite(redLed, HIGH);
    }
    else if (value == 5592332)
    {
      digitalWrite(redLed, LOW);
     }
    else 
    {
      Serial.print("Bad code. You code is ");
      Serial.println(mySwitch.getReceivedValue());
      };
    // output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
  }
}
