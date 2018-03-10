int currentFrame = 0;
int prevFrame;



void LEDdisplay() {
  // array to store datasets
  uint32_t nextArray[SLICENUM * 1024]; // 40960 for 40 slices, 51200 for 50 slices

  // define the index of slice to render
  int sliceNum = calculateSlice();
  //int sliceNum = 15; // fake data for test

  // define the frame number to render
  int lastFrame = 900;
  currentFrame = int(millis() / (1000.0 / 15.0));
  if (currentFrame >= lastFrame) {
    currentFrame = 899;
  }

  // read dataset from microSD
  if (currentFrame > prevFrame || currentFrame == 0) {
    readSd(currentFrame, nextArray);
  }

  int numPixel = 1024;
  int pixelBlock = numPixel / 4;

  // assign color info for each pixels
  for (int i = 0; i < pixelBlock; i++ ) {
    int pid1 = i + sliceNum * numPixel;
    int pid2 = i + sliceNum * numPixel + pixelBlock;
    int pid3 = i + sliceNum * numPixel + pixelBlock * 2;
    int pid4 = i + sliceNum * numPixel + pixelBlock * 3;

    uint8_t pixelId_1 = (uint8_t) pid1;
    uint8_t pixelId_2 = (uint8_t) pid2;
    uint8_t pixelId_3 = (uint8_t) pid3;
    uint8_t pixelId_4 = (uint8_t) pid4;
    /*
      //convert datasest from microSD to uint32_t
      strip_1.setPixelColor(pixelId_1, (uint32_t) nextArray[pid1]);
      strip_2.setPixelColor(pixelId_2, (uint32_t) nextArray[pid2]);
      strip_3.setPixelColor(pixelId_3, (uint32_t) nextArray[pid3]);
      strip_4.setPixelColor(pixelId_4, (uint32_t) nextArray[pid4]);
    */

    strip_1.setPixelColor(pixelId_1, nextArray[pid1]);
    strip_2.setPixelColor(pixelId_1, nextArray[pid2]);
    strip_3.setPixelColor(pixelId_1, nextArray[pid3]);
    strip_4.setPixelColor(pixelId_1, nextArray[pid4]);

  }
  strip_1.show();
  strip_2.show();
  strip_3.show();
  strip_4.show();
  delayMicroseconds(10);

  /*
    // to test reading microSD
    for (int i = 0; i < numPixel; i++){
    Serial.println(nextArray[i]);
    }
  */

  prevFrame = currentFrame;
}
