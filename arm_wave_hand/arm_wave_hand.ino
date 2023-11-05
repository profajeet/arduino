#include <Servo.h>
Servo m1r; 
Servo m2r;
Servo m3r;

void setup() {
  Serial.begin(9600);

  m1r.attach(2);
  m2r.attach(3); 
  m3r.attach(4); 
}

void loop() {
if(Serial.available()){  
 switch (Serial.read()) {
      default:
              {
                Serial.println("Normal Method Executed");
                m1r.write(20);
                delay(50);
                m2r.write(90);
                delay(50);
                m3r.write(90);
                delay(50);
                break;
              }
      case '1':
              {//Talking state
                while(1){
                  Serial.println("Dynamic Method Executed");
                  m1r.write(60);
                  delay(1000);
                  m2r.write(90);
                  delay(2000);
                  m3r.write(60);
                  delay(1000);
                  //reverse
                  m1r.write(40);
                  delay(1000);
                  m2r.write(110);
                  delay(2000);
                  m3r.write(120);
                  delay(1000);
                  }
                break;
              }
      case '2':
              {//greeting state
                Serial.println("Greeting Method Executed");
                m1r.write(20);
                delay(50);
                m2r.write(90);
                delay(50);
                m3r.write(90);
                delay(50);
                //left
                m1r.write(130);
                delay(50);
                m2r.write(60);
                delay(50);
                m3r.write(180);
                delay(50);
                //right
                m2r.write(120);
                delay(50);
                //normal
                m2r.write(90);
                delay(50);
                m1r.write(20);
                delay(50);
                m3r.write(90);
                delay(50);
                break;
               }   
  }          
 }
}
