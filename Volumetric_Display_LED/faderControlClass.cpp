//
//  faderControlClass.cpp
//
//
//this class knows pins, but doesn't touch choreography
//it doesn't know the timecode. just saying "go to this place".
//it compares current position and destination

#include "faderControlClass.h"
#include "Arduino.h"

faderControlClass :: faderControlClass() {

}
// initialize pins
void faderControlClass::setup(int _controlPin1, int _controlPin2, int _positionDetectPin) {
  controlPin1 = _controlPin1;
  controlPin2 = _controlPin2;
  positionDetectPin = _positionDetectPin;

  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, LOW);

  setPwmFrequency(controlPin1, 1);
  setPwmFrequency(controlPin2, 1);
}

// set motor fader's direction and speed
void faderControlClass::moveFader(int destination) {
  int currentPos = analogRead(positionDetectPin);

  //for P part
  int currentError = currentPos - destination;

  //for I part
  int accumlatedError;
  accumlatedError = constrain(accumlatedError, -10000, 10000);
  accumlatedError += currentError;

  //for D part
  int lastError = 0;
  int changeOfError = currentError - lastError;
  lastError = currentError;

  //multipliers of PID control
  float pFactor = 1;
  float iFactor = 0;
  float dFactor = 0;
/*
  //to adjust parameters of PID control
  float pFactor = analogRead(A3)/1000.;
  float iFactor = analogRead(A4)/1000.;
  float dFactor = analogRead(A5)/1000.;
  //float dFactor = 0;
*/
/*
  Serial.println(pFactor);
  Serial.print("\t");
  Serial.print(iFactor);
  Serial.print("\t");
  Serial.print(dFactor);
  Serial.print("\t");
*/

  int faderSpeed = constrain(abs(pFactor * currentError + iFactor * accumlatedError + dFactor * changeOfError), 0, 255);

  if (currentPos < destination) {
    analogWrite(controlPin1, faderSpeed);
    analogWrite(controlPin2, 0);
  } else if (currentPos > destination) {
    analogWrite(controlPin1, 0);
    analogWrite(controlPin2, faderSpeed);
  }

}

void faderControlClass::setPwmFrequency(int pin, int divisor) {
  byte mode;
  if (pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch (divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if (pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if (pin == 3 || pin == 11) {
    switch (divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
