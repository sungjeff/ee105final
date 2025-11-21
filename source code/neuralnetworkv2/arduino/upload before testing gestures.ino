/*
  APDS-9960 - All sensor data from APDS-9960

  This example reads all data from the on-board APDS-9960 sensor of the
  Nano 33 BLE Sense:
   - color RGB (red, green, blue)
   - proximity
   - gesture
  and prints updates to the Serial Monitor every 100 ms.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

bool readingEnabled = false; 
int counter = 0;

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

int proximity = 0;
int r = 0, g = 0, b = 0;
unsigned long lastUpdate = 0;

void loop() {
  if (Serial.available() > 0) {
    if(APDS.gestureAvailable()){
      int gesture = APDS.readGesture();
      // Serial.println(gesture);
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
