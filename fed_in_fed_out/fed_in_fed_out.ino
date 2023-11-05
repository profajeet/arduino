void setup(){
  //initialize the led pins 4-11
  for (int thisPin=8; thisPin<11; thisPin++){
    pinMode(thisPin, OUTPUT);
  }//end for
}//end setup

void loop(){
  //Fade leds up
  for (int thisPin=8; thisPin<11; thisPin++){
    for (int fadeValue = 0; fadeValue < 256; fadeValue++){
      analogWrite(thisPin,fadeValue);
      delay(2);
    }//end for
    //Fade leds down
    for (int fadeValue = 255; fadeValue >=0; fadeValue--){
      analogWrite(thisPin,fadeValue);
      delay(2);
    }//end for 
    delay(1000);
  }//end for
}//end loop
