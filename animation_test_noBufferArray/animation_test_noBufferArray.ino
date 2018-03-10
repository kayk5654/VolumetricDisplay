// Split matrix into four groups, which are 4 pieces of products each.
#include <math.h>
#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET

#define SLICENUM 40
#define NUMPIXELS 256 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN_1    4
#define CLOCKPIN_1   5
Adafruit_DotStar strip_1 = Adafruit_DotStar(
                             NUMPIXELS, DATAPIN_1, CLOCKPIN_1, DOTSTAR_BRG);

#define DATAPIN_2    6
#define CLOCKPIN_2   7
Adafruit_DotStar strip_2 = Adafruit_DotStar(
                             NUMPIXELS, DATAPIN_2, CLOCKPIN_2, DOTSTAR_BRG);
#define DATAPIN_3    8
#define CLOCKPIN_3   9
Adafruit_DotStar strip_3 = Adafruit_DotStar(
                             NUMPIXELS, DATAPIN_3, CLOCKPIN_3, DOTSTAR_BRG);

#define DATAPIN_4    10
#define CLOCKPIN_4   11
Adafruit_DotStar strip_4 = Adafruit_DotStar(
                             NUMPIXELS, DATAPIN_4, CLOCKPIN_4, DOTSTAR_BRG);

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip_1.begin(); // Initialize pins for output
  strip_1.show();  // Turn all LEDs off ASAP
  strip_2.begin(); // Initialize pins for output
  strip_2.show();  // Turn all LEDs off ASAP
  strip_3.begin(); // Initialize pins for output
  strip_3.show();  // Turn all LEDs off ASAP
  strip_4.begin(); // Initialize pins for output
  strip_4.show();  // Turn all LEDs off ASAP

  motorSetup();
  sdSetup();
}

void loop() {
  LEDdisplay();
}

