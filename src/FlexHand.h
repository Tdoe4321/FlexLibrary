////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Arduino Library for Flex Sensors. Created for a robotic hand project designed to mimic a human hand.
//	Flex Sensors were bought on sparkfun: https://www.sparkfun.com/products/8606
//	Author: Tyler Gragg
//	Start Date: 2/7/2018
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FlexHand_h
#define FlexHand_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h" 
#else
#include "WProgram.h"
#endif

#ifndef NONE
#define NONE -1
#endif

#ifndef AVG
#define AVG 0
#endif

#ifndef RUN_AVG
#define RUN_AVG 1
#endif

#ifndef EXP
#define EXP 2
#endif


class FlexHand {
private:
	int sensorPin;  // The analog pin the Flex sensor is read into 
	int maxInput;  	// Max Input on the flex sensors themselves - this is used for calibration on the sensors
	int minInput;	// Min Input on the flex sensors themselves - this is used for calibration on the sensors
	int numReadings; // The number of reading you want to take into the Averaging Process
	int* vals; // An array of Values
	int readIndex; // Where we are in the averaging process
	int smoothingType;
	int weight; // Only for exponential smoothing function
	int* expVals; // Used for the exponential smoothing function
	
	int noSmooth();
	int avgSmooth();
	int runAvgSmooth();
	int expSmooth();
	
public:
	FlexHand(int SensorPin);
	FlexHand(int SensorPin, int minInput, int maxInput);
	FlexHand(int SensorPin, int numReadings, int smoothingType);
	FlexHand(int SensorPin, int numReadings, int smoothingType, int weight);
	FlexHand(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType);
	FlexHand(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType, int weight);
	
	//Getter and Setter Functions:
	void setSensorPin(int sensorPin);
		
	int getSensorValue();
	
	void setMaxInput(int maxInput);
	void setMinInput(int minInput);
	void setMinMaxInput(int minInput, int maxInput);
	
	//Other Functions:
	void Calibrate();
	
	void updateVal();
	
	bool isBent();
	

};


#endif