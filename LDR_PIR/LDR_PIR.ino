// Pin definitions
#define LED_PIN 3        // Pin connected to LED
#define PIR_PIN 2      // Pin connected to PIR sensor
#define LDR_PIN A0       // Pin connected to LDR sensor module

// Variables
int pirState = LOW;      // Variable to store PIR sensor state
int ldrValue = 0;        // Variable to store LDR sensor value
int  count  = 0;        // Variable to store timerr value

void setup() {
  pinMode(LED_PIN, OUTPUT);   // LED pin as output
  pinMode(PIR_PIN, INPUT);    // PIR sensor pin as input
  pinMode(LDR_PIN, INPUT);    // LDR  sensor pin as input
  Serial.begin(9600);         // Initialize serial communication
}

void loop() {
  pirState = digitalRead(PIR_PIN);   // Read PIR sensor state
  ldrValue = analogRead(LDR_PIN);    // Read LDR sensor value

  // Check if it's night time (LDR value is below a threshold)
  if (ldrValue < 500) {
    // If motion is detected, turn on LED
    // count should be in particular second 
    if (pirState == HIGH && count < 5) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Motion detected! LED turned on.");
      count = count+1;
      delay(1000);
    } else {
      digitalWrite(LED_PIN, LOW);
      count = 0; 
    }
  } else {
    // It's daytime, turn off the LED
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);  // Delay for stability
}

