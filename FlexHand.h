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

#include "Arduino.h"
#include <Servo.h>  // Needed to output data to servos if running a hand-setup

class FlexHand {
private:
	int sensorPin;  // The analog pin the Flex sensor is read into 
	int outputPin;  // The digital pin the new values are outputting to
	int sensorValue;     //The read in value from the Flex Sensor
	int translatedValue; //The value that is going to be sent out	
	int maxOutput;	// Max output on the translated value
	int minOutput;	// Min output on the translated value
	bool isOutputReversed;	//Denotes whether the output translated value needs to be reversed or not

public:
	FlexHand(int SensorPin);
	FlexHand(int SensorPin, int OutputPin);
	FlexHand(int SensorPin, int OutputPin, int maxOutput, int minOutput);
	FlexHand(int SensorPin, int OutputPin, int maxOutput, int minOutput, bool isOutputReversed);

	void setSensorPin(int sensorPin);
	
	void setOutputPin(int outputPin);
	
	int getSensorValue();

	int getTranslatedValue();

	void setMaxOutput(int maxOutput);

	void setMinOutput(int minOutput);

	bool getIsOutputReversed();
	void setIsOuptutReversed(bool isOutputReversed);

	void setMinMax(int minOutput, int maxOutput);
};


#endif