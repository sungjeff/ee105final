# Gesture Recognition and Neural Networks

Richard Guo, Emily Jiang, Annie Nguyen, Leila Saxby, Jeffrey Sung

EE-105 - Professor Yasser Khan

December 2, 2025

## Abstract:
In this project, we built a neural network that detects gestures using the APDS9960 optical sensor. The neural network implemented a single hidden layer to classify hand gestures from the sensor’s raw data. The overall responsiveness was mostly accurate, though not significantly more responsive than the built-in gesture detection library. With the right optimizations, the performance of the neural network can be significantly improved. 

## Introduction & Theory
Gesture detection is a technology that enables machines to interpret and respond to specific human motions as meaningful commands. In this project, we focus on recognizing directional hand swipes (up, down, left, right) using an APDS9960 optical sensor. The APDS9960 integrates four directional proximity sensors.
The Arduino microcontroller, programmed via the Arduino IDE, is responsible for interfacing with the APDS9960 sensor, continuously reading raw proximity values from its four photodiodes, and streaming this data serially to a computer. A Python notebook uses the pyserial library to capture this data stream for real-time analysis.
An algorithm identifies the onset of a gesture by detecting the first proximity reading exceeding a threshold of 30. It then extracts a focused window of 15 data points, which captures the core gesture signal. Furthermore, to enhance pattern recognition for the neural network, we added two more features that are calculated from the raw four-sensor data: (Left-Right) and (Up-Down).

## Objectives:
 - Hardware & Data Acquisition: To successfully interface the APDS9960 sensor with an Arduino and develop robust firmware to reliably capture and output the raw proximity data from all four directional sensors.
 - Real-Time Data Interpretation: To establish a real-time serial communication pipeline (using pyserial) between the Arduino and a Python environment, enabling the continuous flow of sensor data for immediate processing.
 - Data Processing & Feature Engineering: To implement an on-computer algorithm that filters the serial data stream, identifies gesture onset using a proximity threshold, extracts a relevant 15-point data window, and calculates derived features (L-R and U-D) to prepare the data for classification.
 - Gesture Classification Implementation: To design and deploy a processing system (initially in Python) capable of classifying the processed sensor data into one of the four directional gestures (up, down, left, right) in real time.
 - System Evaluation: To quantitatively evaluate the completed system's accuracy and reliability in gesture recognition, comparing its performance against baseline methods (e.g., the sensor's built-in library) and identifying key performance metrics.

## Materials:
 - Hardware:
 - APDS9960 optical sensor
 - Microcontroller on Arduino
 - USB cable
 - Software:
 - Arduino IDE
 - VS Code
 - APDS9960 Library
 - CSV Library (Data Collection)
 - Other:
   - Laptop

## Procedure:
To collect data, we modified the Arduino Library for the APDS9960 sensor so that the proximity values from the four sensors on the microcontroller would be printed to the serial monitor. To filter noise, we selected 15 proximity readings from each data point from approximately 100 readings we recorded per gesture. There was code to detect any spike in the proximity values from each data point and take the 15 proximity readings around that time. To train the neural network, we took thousands of CSV files, each representing a gesture, and then loaded them into the lab Python code. 
Using systematic sampling, 20% of all data was used for testing, another 20% was used for the final test, and 60% was used for training. We created a Python notebook that collects and processes the 15 most recent data points and puts them into the neural network link for training. The notebook then prints out the gesture that has the highest output value if it's greater than the threshold value. The trained model was imported from the training notebook using Python’s pickle module. 

## Data:
The data collected from the sensor was recorded in CSV files, which contained the raw proximity readings from the four sensors. Some noise was present during the readings, but it was reduced by taking only 15 data points that were spiked. Gestures did not overlap during testing because the tester only gave the gesture that had the highest output value, coded to only return one gesture.

Output from Serial Monitor:

<img width="191" height="521" alt="{34920123-DF3F-40DD-9C83-07024AE0BA1B}" src="https://github.com/user-attachments/assets/1b6ad45f-c74d-41bd-bb89-1575e36f5e17" />

## Analysis & Calculations:
Gesture thresholds were computed by testing different output values from the neural network and choosing the value that resulted in the most accurate gesture recognition. The threshold value of 8 was chosen because it consistently allowed the neural network to detect gestures accurately. An algorithm was used to identify the spikes in proximity readings by searching for the first reading that exceeded the proximity value of 30. Once the spikes were detected, the algorithm would splice the data so it was the data readings from five before that data point to ten after. In addition to the four proximity readings, we added two more features to the data point when processing it: the difference between the right and left sensors, and the difference between the up and down sensors. The accuracy of our neural network was determined by comparing the network’s predictions to expected gestures, and the model generally made accurate predictions. 


## Error Analysis:

<img width="328" height="466" alt="{B4497C9A-EF4B-4FDC-AABB-8258A1D79499}" src="https://github.com/user-attachments/assets/4fd15951-3afd-4099-b9f7-bc8cc6697081" />


## Results:
The accuracy of the gesture detection with our neural network was moderate compared to the built-in Arduino library. Some gestures were classified correctly; however, testing different gesture data sets from different group members with one model resulted in low accuracy. The gesture that worked the best was the “up” gesture, though the performance was consistent across gestures. We created a new gesture called “nothing” to prevent any false gesture detections when a hand was placed on top of the sensor without moving. Previously, when a hand was placed on top of the sensory, it would be detected as the “up” gesture. The response time for our model was fast; however, it was slower than the Arduino Library. This may be because the APDS9960 Library was uploaded to the Arduino while our training was done through a Python notebook via PySerial to take the data from the serial monitor.

## Screenshot of successful output:
<img width="470" height="102" alt="{DAD98F69-405B-4FE0-BFDF-76F2E38352C6}" src="https://github.com/user-attachments/assets/c48ab746-c408-482b-b680-17d793894bb2" />


7.2587 is the confidence value the model outputted for the up gesture. 
 
## Conclusion:
In this project, we learned how to use Python, particularly with PySerial, to communicate with Arduino and the Pickle module to train and analyze our neural network. We also learned that it’s important to filter data because it gave better results when we used it to train our model. The biggest challenge was training the neural network. Overall, our system performed well, though there were some inaccuracies; the Arduino Library was also inaccurate sometimes. To improve our model and training, increasing the size of the data set for each gesture or using a convolutional neural network could improve its accuracy. In real-world applications, this system can be used for gesture-based controls in electronics, improving accessibility for those with limited mobility, motor impairments, or other physical limitations, and making technology more inclusive for everyone. 
