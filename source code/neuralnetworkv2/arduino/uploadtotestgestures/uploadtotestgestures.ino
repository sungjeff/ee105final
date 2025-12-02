// some code was taken from the example

#include <iostream>

#include <Arduino_APDS9960.h>


void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Monitor to open

  if (!APDS.begin()) {
    Serial.println("Error initializing APDS-9960 sensor.");
    while (true); // Stop forever
  }
}

void loop() { // prints out if the arduino library detects a gesture and which gesture it detects. also prints out all the proximity sensor readings onto serial monitor
  if (Serial.available() > 0) {
    if(APDS.gestureAvailable()){
      int gesture = APDS.readGesture();
      switch (gesture) {
        case GESTURE_DOWN:
          Serial.println("Arduino Library Detected UP gesture");
          break;
        case GESTURE_UP:
          Serial.println("Arduino Library Detected DOWN gesture");
          break;
        case GESTURE_RIGHT:
          Serial.println("Arduino Library Detected LEFT gesture");
          break;
        case GESTURE_LEFT:
          Serial.println("Arduino Library Detected RIGHT gesture");
          break;
        default:
          // ignore
          break;
      }
    }
    APDS.writeData();
  }
}
