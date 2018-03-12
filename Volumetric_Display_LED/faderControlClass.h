//
//  faderControlClass.h
//
//
//
//

#ifndef ____faderControlClass__
#define ____faderControlClass__

#include <stdio.h>
#include "Arduino.h"

class faderControlClass {
  public:
    int controlPin1;
    int controlPin2;
    int positionDetectPin;
    //unsigned long startTime;
    faderControlClass();
    void setup(int _controlPin1, int _controlPin2, int _positionDetectPin);
    void moveFader(int destination);
    void setPwmFrequency(int pin, int divisor);
};

#endif /* defined(____faderControlClass__) */
