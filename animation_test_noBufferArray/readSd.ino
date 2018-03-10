#include "SdFat.h"

// for Teensy 3.5 and 3.6, SdFatSdio is used
SdFatSdio sd;
File myFile;

String folderName = "/animated_csv_40_1";
String fileName1 = "/dataset_";
String fileName2 = ".txt";



void sdSetup() {
  sd.begin();
  /*Serial.begin(115200);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");
  // to read sd with teensy 3.5 or 3.6, sd.begin() mustn't take an argument
  if (!sd.begin()) {
    Serial.println("initialization failed!");
    return;
  } else {
    Serial.println("initialization succeed!");
  }
  */
}
/*
void prepareDatasets(int _currentFrame, uint32_t *_currentArray, uint32_t *_nextArray) {

  int arrayLen = SLICENUM * 1024;
  for (int i = 0; i < arrayLen; i++) {
    _currentArray[i] = _nextArray[i];
  }
  readSd(_currentFrame);
}
*/
void readSd(int _currentFrame, uint32_t *_nextArray) {
  String temp = "";
  char ch;
  int arrayId = 0;
  int arraySize = SLICENUM * 1024;
  String fileName = folderName + fileName1 + String(_currentFrame) + fileName2;

  myFile = sd.open(fileName, FILE_READ);

  while (myFile.available()) {
    ch = (char)myFile.read(); //return next byte as int
    if (ch != '\n') {
      temp += ch;

    } else {
      char charbuf[9];
      temp.toCharArray(charbuf, 9);
      _nextArray[arrayId] = (uint32_t) strtol(charbuf, NULL, 0);
      temp = "";
      //Serial.println(charbuf);
      if (arrayId < arraySize - 1) {
        arrayId++;
      } else {
        arrayId = 0;
      }
    }

  }
  myFile.close();
}
