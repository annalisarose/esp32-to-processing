//libraries
#include <WiFi.h>
#include <WiFiUdp.h>  
#include <OSCMessage.h>
#include <ezButton.h>

//switch states / serial messages
const int SWITCH_OFF = 0; // state of all buttons initially
const int SWITCH_OFF1 = 10; //serial message when button 1 (pin 33) is off
const int SWITCH_ON1 = 1;
const int SWITCH_OFF2 = 20; //serial message when button 2 (pin 32) is off
const int SWITCH_ON2 = 2;
const int SWITCH_OFF3 = 30; //serial message when button 3 (pin 34) is off
const int SWITCH_ON3 = 3;
const int SWITCH_OFF4 = 40; //serial message when button 4 (pin 35) is off
const int SWITCH_ON4 = 4;


ezButton button(33); // create ezButton object that attach to pin 33;
ezButton button2(32); // create ezButton object that attach to pin 32;
ezButton button3(34); // create ezButton object that attach to pin 34;
ezButton button4(35); // create ezButton object that attach to pin 35;

int switch_state1 = SWITCH_OFF; // initial state of button 1 (pin 33);
int switch_state2 = SWITCH_OFF; // initial state of button 2 (pin 32);
int switch_state3 = SWITCH_OFF3; // initial state of button 1 (pin 34);
int switch_state4 = SWITCH_OFF4; // initial state of button 2 (pin 35);

void setup() {
  
  Serial.begin(9600);
  
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  button2.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {

  button3.loop(); 
  button4.loop(); 

  if (button3.isPressed()) {
    // change state of switch
    if (switch_state3 == SWITCH_OFF4)
      switch_state3 = SWITCH_ON3;
     //Serial.write(1);
    else
      switch_state3 = SWITCH_OFF3;
      //Serial.write(0);

    //Serial.print("switch's state -> ");
    Serial.println(switch_state3);
  }

  if (button4.isPressed()) {
    // change state of switch
    if (switch_state4 == SWITCH_OFF4)
      switch_state4 = SWITCH_ON4;
     //Serial.write(1);
    else
      switch_state4 = SWITCH_OFF4;
      //Serial.write(0);

    //Serial.print("switch's state -> ");
    Serial.println(switch_state4);
  }
}
