#include<Servo.h>
Servo lips;
Servo eyes;
const int spk=A0;
const int led[5]={2,3,4,5,6};

int sound = 0;

void setup() {
  Serial.begin(9600);
  lips.attach(8);
  eyes.attach(7);
  for(int i=0;i<5;i++){
      pinMode(led[i],OUTPUT);
    }
//  pinMode(r0,OUTPUT);
//  pinMode(r1,OUTPUT);
//  pinMode(r2,OUTPUT);
//  pinMode(r3,OUTPUT);
//  pinMode(r4,OUTPUT);
  pinMode(spk,INPUT);
  eyes.write(90);
}

void loop() {
  sound = analogRead(spk);
  Serial.println(sound);
  delay(100);
  while(sound < 500){
      for(int i=0;i<5;i++){
          Serial.println("LED HIGH");
          digitalWrite(led[i],HIGH);
          delay(5);
          lips.write(20);
          delay(5);
          eyes.write(75);
          delay(5);
          eyes.write(90);
          delay(5);
          lips.write(0);
          delay(5);
          eyes.write(105);
          delay(5);
        }
        delay(500);
        for(int i=0;i<5;i++){
          Serial.println("LED LOW");
          digitalWrite(led[4-i],LOW);
          delay(5);
          lips.write(20);
          delay(5);
          eyes.write(75);
          delay(5);
          eyes.write(90);
          delay(5);
          lips.write(0);
          delay(5);
          eyes.write(105);
          delay(5);
        }
    }
    if(sound > 500){
        for(int i=0;i<5;i++){
          Serial.println("LED HIGH");
          digitalWrite(led[i],HIGH);
          delay(100);
        }
        eyes.write(75);
        delay(10);
        eyes.write(105);
        delay(10);
        eyes.write(90);
        delay(10);
        for(int i=0;i<5;i++){
          Serial.println("LED LOW");
          digitalWrite(led[4-i],LOW);
          delay(100);
        }
        eyes.write(90);
        delay(10);
      }
}
