////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Arduino Library for Flex Sensors. Created for a robotic hand project designed to mimic a human hand.
//	Flex Sensors were bought on sparkfun: https://www.sparkfun.com/products/8606
//	Author: Tyler Gragg
//	Start Date: 2/7/2018
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Extended Description:
//	This Library is designed to implement the flex sensors from sparkfun as an input device for a robot
//	hand. The hope is to make it easier to register inputs like "taps" and whether a finger is currently
//	bent or straight. It also has things like re-calibration methods and the ability to reverse servos
//	if you hook somehting up backwards. Here is the link to the instructables: TODO: *ADD LINK*
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FlexHand.h"
#include "Arduino.h"

FlexHand::FlexHand(int SensorPin){
	this->sensorPin = SensorPin;
	this->maxInput = 700;
	this->minInput = 400;
	this->numReadings = 10;
	this->smoothingType = AVG;
	vals = new int[numReadings];
	readIndex = 0;
}

FlexHand::FlexHand(int SensorPin, int minInput, int maxInput){
	this->sensorPin = SensorPin;
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = 10;
	this->smoothingType = AVG;
	vals = new int[numReadings];
	readIndex = 0;
}

FlexHand::FlexHand(int SensorPin, int numReadings, int smoothingType){
	this->sensorPin = SensorPin;
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = numReadings;
	this->smoothingType = smoothingType;
	vals = new int[numReadings];
	readIndex = 0;
}

FlexHand::FlexHand(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType){
	this->sensorPin = SensorPin;
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = numReadings;
	this->smoothingType = smoothingType;
	vals = new int[numReadings];
	readIndex = 0;
}

void FlexHand::setSensorPin(int sensorPin){
	this->sensorPin = sensorPin;
}

int FlexHand::getSensorValue(){
	//TODO Edit
}

void FlexHand::setMaxInput(int maxInput){
	this->maxInput = maxInput;
}	

void FlexHand::setMinInput(int minInput){
	this->minInput = minInput;
}

void FlexHand::setMinMaxInput(int minInput, int maxInput){
	this->minInput = minInput;
	this->maxInput = maxInput;
}

void Calibrate(){
	//TODO: Edit
}

void FlexHand::updateVal(){
	//TODO edit
}

bool isBend(){
	//TODO Edit
}

