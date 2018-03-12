#include "faderControlClass.h"
#include <math.h>

// instances
faderControlClass faderControl;

// pins to control motors
int motorPin1_1 = 3;
int motorPin1_2 = 9;
int motorPin1_3 = A1;

// pin for potentiometer
int potentiometerPin = A0;

// direction of the movement of motor fader
bool direction;

// pins to control LED matrix
int LEDrow[8] = {0, 1, 2, 4, 5, 6, 7, 8};
int LEDcol[8] = {10, 11, 12, 13, 16, 17, 18, 19};

void setup() {
  // setup motor faders
  faderControl.setup(motorPin1_1, motorPin1_2, motorPin1_3);
  direction = true;
  
  // setup LED matrix
  LEDsetup();
  //Serial.begin(115200);
}

void loop() {
  // move fader, get the position
  scan2(motorPin1_1, motorPin1_2, motorPin1_3, potentiometerPin,  millis());
  //scan(motorPin1_1, motorPin1_2, potentiometerPin, millis());

  int pos = analogRead(motorPin1_3);

  //display graphics on LED matrix
  drawLED(pos);
  //Serial.println(int(pos/int(1024 / 20)));
}
