////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Arduino Library for Flex Sensors. Created for a robotic hand project designed to mimic a human hand.
//	Flex Sensors were bought on sparkfun: https://www.sparkfun.com/products/8606
//	Author: Tyler Gragg
//	Start Date: 2/7/2018
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FlexLibrary_h
#define FlexLibrary_h

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


class Flex {
private:
	int sensorPin;  	// The analog pin the Flex sensor is read into 
	int minInput;		// Min Input on the flex sensors themselves - this is used for calibration on the sensors
	int maxInput;  		// Max Input on the flex sensors themselves - this is used for calibration on the sensors
	int numReadings; 	// The number of reading you want to take into the Averaging / Smoothing Process
	int readIndex; 		// Where we are in the averaging process
	int smoothingType;  // Options are: NONE, AVG, RUN_AVG, EXP
	int weight; 		// Only for exponential smoothing function
	int* vals; 			// An array of Values	
	int* expVals; 		// Used for the exponential smoothing function
	
	int noSmooth();		// Returns the unsmoothed value of the flex sensor
	int avgSmooth();	// Takes in 'numReadings' number of values and returns an average
	int runAvgSmooth();	// Uses a 'Running Average' calculation to compute a smoothed value
	int expSmooth(int weight);	// Uses an exponential smoothing algorithm
	
public:
	Flex(int SensorPin);
	Flex(int SensorPin, int minInput, int maxInput);
	Flex(int SensorPin, int numReadings, int smoothingType, int weight);
	Flex(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType);
	Flex(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType, int weight);
	
	//Getter and Setter Functions:
	void setSensorPin(int sensorPin);
		
	int getSensorValue();

	int getMinInput();
	int getMaxInput();
	
	void setMaxInput(int maxInput);
	void setMinInput(int minInput);
	void setMinMaxInput(int minInput, int maxInput);
	
	//Other Functions:
	void Calibrate();
	
	void updateVal();
	
	bool isBent();
	

};


#endif