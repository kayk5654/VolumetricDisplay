#volumetric dispaly operation for raspberry pi zero w
import time
from dotstar import Adafruit_DotStar

SLICENUM = 40
NUMPIXELS = 256

#GPIO pin settings
DATAPIN_1 = 4
CLOCKPIN_1 = 5
strip_1 = Adafruit_DotStar(NUMPIXELS, DATAPIN_1, CLOCKPIN_1)

DATAPIN_2 = 6
CLOCKPIN_2 = 7
strip_2 = Adafruit_DotStar(NUMPIXELS, DATAPIN_2, CLOCKPIN_2)

DATAPIN_3 = 8
CLOCKPIN_3 = 9
strip_3 = Adafruit_DotStar(NUMPIXELS, DATAPIN_3, CLOCKPIN_3)

DATAPIN_4 = 10
CLOCKPIN_4 = 11
strip_4 = Adafruit_DotStar(NUMPIXELS, DATAPIN_4, CLOCKPIN_4)

#Initialize pins for output
strip_1.begin()
strip_1.setBrightness(64)
strip_2.begin()
strip_2.setBrightness(64)
strip_3.begin()
strip_3.setBrightness(64)
strip_4.begin()
strip_4.setBrightness(64)

#settings of rotation detection
prevPeriod[]
lastTime = 0
currentTime = 0
motorPinA = 14
currentVal = 1
prevVal = 1
def motorSetup:


def appendAndAverage(appendValue, array):
    len = len(array)
    if len < 7:
        array[len] = appendValue
        len += 1
    else:
        for i in len-1:
            array[i] = array[i+1]
        array[len - 1] = appendValue

    temp = 0
    for j in len:
        temp += array[j]

    average = temp / len
    return average
