// some code taken from example code, some code taken from labs

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

void loop() { // if we read a command from the python thing, begin writing data onto serial monitor until counter reaches 75, then stop writing data
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); 
    if (command == "a" || command == "w" || command == "s" || command == "d" || command == "nothing") readingEnabled = true;
  }

  APDS.gestureAvailable();
  while (readingEnabled) {
    APDS.writeData();
    counter = counter + 1;
    if(counter == 75){
      counter = 0;
      readingEnabled = false;
      Serial.println("Ready to enter next command");
      break;
    }
  }
}
