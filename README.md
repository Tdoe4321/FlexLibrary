# FlexLibrary

This Library is designed to make the integration of 'Flex Sensors' easier and simpler. The Idea of this Library is to create a built in way to smooth out data, register 'bent' actions, as well as create an easy way of tracking individual Sensors.

Author: Tyler Gragg

## Overview

This repo was first created to provide an easier way to read, calibrate, and implement flex sensors in a project. This repo provides the abliity to smooth out data as in comes in from the Flex Sensor using a few different smoothing algoithms. I first used this in a 3D printed robotic hand:  
https://www.youtube.com/watch?v=TQ_TahQRkv4&t=2s

Here's a tutorial that SparkFun made on how to use the sensors:  
https://learn.sparkfun.com/tutorials/flex-sensor-hookup-guide?_ga=2.94213149.1270623430.1522179726-1541878408.1500580526

## Documentation 

Latest documentation is kept in the wiki page here:  
https://github.com/Tdoe4321/FlexLibrary/wiki

## Data Members  
The _Flex()_ class has the following data members:

* int sensorPin&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  	 - The analog pin the Flex sensor is read into 
* int minInput&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;		 - Min Input on the flex sensors themselves - this is used for calibration on the sensors
* int maxInput&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  	 - Max Input on the flex sensors themselves - this is used for calibration on the sensors
* int numReadings&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 	 - The number of reading you want to take into the Averaging / Smoothing Process
* int readIndex&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 	 - Where we are in the averaging process
* int smoothingType&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  - Options are: NONE, AVG, RUN_AVG, EXP
* int weight&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 		 - Weight for the Exponential smoothing process only. Has no effect on other smoothing algorithms.
* int* vals&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 		 - An array to hold the previous Values	
* int* expVals&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 		 - Used for the exponential smoothing function

## Functions  

### Constructors  
I have overloaded the constructor so that you can do anything from super quick and easy implementation to defining all the parameters of your Flex Sensor in one go.

For any constructor that does not define all the data members, the following are set as the default:  
minInput = 400  
maxInput = 700  
numReadings = 10  
smoothingType = NONE  
weight = 0  

##### Flex(int SensorPin)  

##### Flex(int SensorPin, int minInput, int maxInput)  

##### Flex(int SensorPin, int numReadings, int smoothingType, int weight)  

##### Flex(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType)  

##### Flex(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType, int weight)  

### Get and Set  
You have the ability to get or set the following data members:

##### void setSensorPin(int sensorPin)

##### int getSensorValue()  
Returns the most recent value from the sensor.

##### int getMinInput()  
Returns the min value from a calibrated FlexSensor

##### int getMaxInput()  
Returns the max value from a calibrated FlexSensor

##### void setMaxInput(int maxInput)

##### void setMinInput(int minInput)

##### void setMinMaxInput(int minInput, int maxInput)

### Other Functions  
##### void Calibrate()    
Updates the sensor once, then replaces minInput or maxInput if that sensor reading was smaller or larger respectively. Designed to be used in a loop multiple times, see example.

##### void updateVal()<br/>
Updates the current reading of the sensor. Should be somewhere in your main loop().

##### bool isBent()    
Returns *true* if the current sensor value is greater than 60% bent, otherwise false.