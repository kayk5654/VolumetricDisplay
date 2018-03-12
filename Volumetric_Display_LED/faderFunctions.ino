// move faders to scan virtual volume
void scan(int _faderPin1, int _faderPin2, int _controllerPin, unsigned long time) {
  float cyclePeriod = map(analogRead(_controllerPin), 0, 1024, 4000, 260); //original: 130, LED Matrix: 260
  float phase = time % long(cyclePeriod);

  int faderSpeed = map(analogRead(_controllerPin), 0, 1024, 10, 255);

  if (phase < cyclePeriod / 2) {
    analogWrite(_faderPin1, faderSpeed);
    analogWrite(_faderPin2, 0);
  } else {
    analogWrite(_faderPin1, 0);
    analogWrite(_faderPin2, faderSpeed);
  }
}

void scan2(int _faderPin1, int _faderPin2, int _positionPin, int _speedPin, unsigned long time) {
  int pos = analogRead(_positionPin);
  int faderSpeed = map(analogRead(_speedPin), 0, 1024, 10, 255);
  
  // About threshold
  // Full range of rail is 0 to 1024.
  // Some datasets use full range, but others don't.
  // So you can use short range of rail to display.
  // As far as I tested, using 150 to 854 makes less noise,
  // because fader deosn't hit each end of rails.
  if (pos < 150) {
    direction = true;
  } else if (pos > 854) {
    direction = false;
    }

  if (direction == true) {
    analogWrite(_faderPin1, faderSpeed);
    analogWrite(_faderPin2, 0);
  } else {
    analogWrite(_faderPin1, 0);
    analogWrite(_faderPin2, faderSpeed);
  }

}
