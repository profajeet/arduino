#include <Servo.h>
Servo m1r; 
Servo m2r;

void setup() {
  Serial.begin(9600);

  m1r.attach(2);
  m2r.attach(3); 
  m1r.write(20);
  delay(50);
  m2r.write(90);
  delay(50);
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
                break;
              }
      case '1': 
              {//Talking state
                int i=2;
                while(i>0){
                  Serial.println(i);
                  Serial.println("Dynamic Method Executed");
                  m1r.write(50);
                  delay(1000);
                  m2r.write(60);
                  delay(1000);
                  //reverse
                  m1r.write(40);
                  delay(1000);
                  m2r.write(110);
                  delay(1000);
                  //normal
                  m1r.write(20);
                  delay(1000);
                  m2r.write(90);
                  delay(1000);
                  i = i-1;
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
                //left
                m1r.write(130);
                delay(50);
                for(int i=1;i<=30;i++){
                  m2r.write(90-i);
                  delay(50);
                  }
                  delay(500);
                  //right
                  
                for(int i=1;i<=60;i++){
                  m2r.write(60+i);
                  delay(50);
                  }
                  delay(1000);
                //normal
                for(int i=1;i<=30;i++){
                m2r.write(120-i);
                delay(50);
                }
                m1r.write(20);
                break;
               }   
  }          
 }
}
