unsigned long prevPeriod[7];
unsigned long lastTime = 0;
unsigned long currentTime = 0;

int motorPinA = 14;
bool currentVal, prevVal;

void motorSetup() {
  pinMode(motorPinA, INPUT);
  currentVal = digitalRead(motorPinA);
}

unsigned long appendAndAverage(unsigned long appendValue, unsigned long array[]) {
  int len = sizeof(array) / sizeof(unsigned long);
  unsigned long average;

  for (int i = 0; i < len - 1; i++) {
    array[i] = array [i + 1];
  }
  array[len - 1] = appendValue;

  unsigned long sum;
  int divisor = len;
  for (int j = 0; j < len; j++) {
    if (array[j] > 0) {
      sum += array[j];
    } else {
      divisor--;
    }
  }
  average = sum / divisor;
  return average;
}

int calculateSlice() {
  int totalSliceNum = SLICENUM;
  int sliceNum;
  unsigned long lastPeriod;

  // calculate time to rotate once
  prevVal = currentVal;
  currentVal = digitalRead(motorPinA);

  // when the magnet COMES to the hall sensor
  if (currentVal != prevVal && currentVal < prevVal) {
    lastTime = currentTime;
    currentTime = micros();
    lastPeriod = currentTime - lastTime;
  }

  // calculate frequency of rotation
  //long averagePeriod = long(appendAndAverage(lastPeriod, prevPeriod));
  /*
    long averagePeriod = 1000000 / 15;

    // calculate index of slices
    sliceNum = int((totalSliceNum / averagePeriod) * micros() % totalSliceNum);
  */
  float averagePeriod = 1000000.0 / 25.0;

  // calculate index of slices
  float temp = int(40.0 / averagePeriod * micros());
  sliceNum = int(temp) % totalSliceNum;
  return sliceNum;
}

