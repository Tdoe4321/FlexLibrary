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
	int maxOutput;	// Max output on the translated value
	int minOutput;	// Min output on the translated value
	int maxInput;  	// Max Input on the flex sensors themselves - this is used for calibration on the sensors
	int minInput;	// Min Input on the flex sensors themselves - this is used for calibration on the sensors
	bool isOutputReversed;	//De1notes notes whether the output translated value needs to be reversed or not
	Servo servo;

public:
	FlexHand(int SensorPin);
	FlexHand(int SensorPin, int OutputPin);
	FlexHand(int SensorPin, int OutputPin, int minOutput, int maxOutput);
	FlexHand(int SensorPin, int OutputPin, int minInput, int maxInput, int minOutput, int maxOutput);
	FlexHand(int SensorPin, int OutputPin, int minOutput, int maxOutput, bool isOutputReversed);
	FlexHand(int SensorPin, int OutputPin, int minInput, int maxInput, int minOutput, int maxOutput, bool isOutputReversed);

	//Getter and Setter Functions:
	void setSensorPin(int sensorPin);
	
	void setOutputPin(int outputPin);
	
	int getSensorValue();

	void setMaxOutput(int maxOutput);
	void setMinOutput(int minOutput);
	
	void setMaxInput(int maxInput);
	void setMinInput(int minInput);
	
	void setMinMaxOutput(int minOutput, int maxOutput);
	void setMinMaxInput(int minInput, int maxInput);

	bool getIsOutputReversed();
	void setIsOuptutReversed(bool isOutputReversed);
	
	//Other Functions:
	int getTranslatedValue(); // returns the exact number that would be sent to the servo
	
	void turn(int deg);  // Turn to a specific degree
	
	void calculateDeg();  // Intermediary function to translate the output value

	void calcAndTurn();  // In loop(), every time you want to update, you need to call this function
};


#endif