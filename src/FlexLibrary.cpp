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

#include "FlexLibrary.h"

Flex::Flex(int SensorPin){
	this->sensorPin = SensorPin;
	pinMode(sensorPin, INPUT);
	this->maxInput = 400;	// These values are intentionally designed to use the 
	this->minInput = 700;	// calibrate() function
	this->numReadings = 10;
	this->smoothingType = NONE;
	vals = new int[numReadings];
	expVals = new int[numReadings];
	readIndex = 0;
	this->weight = 0;
	constrain(weight, 0, 100);
	
	for(int i = 0; i < numReadings; i++) vals[i] = 0;
	for(int i = 0; i < numReadings; i++) expVals[i] = 0;
}

Flex::Flex(int SensorPin, int minInput, int maxInput){
	this->sensorPin = SensorPin;
	pinMode(sensorPin, INPUT);
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = 10;
	this->smoothingType = NONE;
	vals = new int[numReadings];
	expVals = new int[numReadings];
	readIndex = 0;
	this->weight = 0;
	constrain(weight, 0, 100);
	
	for(int i = 0; i < numReadings; i++) vals[i] = 0;
	for(int i = 0; i < numReadings; i++) expVals[i] = 0;
}

Flex::Flex(int SensorPin, int numReadings, int smoothingType, int weight){
	this->sensorPin = SensorPin;
	pinMode(sensorPin, INPUT);
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = numReadings;
	this->smoothingType = smoothingType;
	vals = new int[numReadings];
	expVals = new int[numReadings];
	readIndex = 0;
	this->weight = weight;
	constrain(weight, 0, 100);
	
	for(int i = 0; i < numReadings; i++) vals[i] = 0;
	for(int i = 0; i < numReadings; i++) expVals[i] = 0;
}

Flex::Flex(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType){
	this->sensorPin = SensorPin;
	pinMode(sensorPin, INPUT);
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = numReadings;
	this->smoothingType = smoothingType;
	vals = new int[numReadings];
	expVals = new int[numReadings];
	readIndex = 0;
	this->weight = 0;
	constrain(weight, 0, 100);
	
	for(int i = 0; i < numReadings; i++) vals[i] = 0;
	for(int i = 0; i < numReadings; i++) expVals[i] = 0;
}

Flex::Flex(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType, int weight){
	this->sensorPin = SensorPin;
	pinMode(sensorPin, INPUT);
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = numReadings;
	this->smoothingType = smoothingType;
	vals = new int[numReadings];
	expVals = new int[numReadings];
	readIndex = 0;
	this->weight = weight;
	constrain(weight, 0, 100);
	
	for(int i = 0; i < numReadings; i++) vals[i] = 0;
	for(int i = 0; i < numReadings; i++) expVals[i] = 0;
}

void Flex::setSensorPin(int sensorPin){
	this->sensorPin = sensorPin;
}

int Flex::getSensorValue(){
	switch(smoothingType){
		case -1 : 
			return noSmooth();
			break;
		case 0 :
			return avgSmooth();
			break;
		case 1 :
			return runAvgSmooth();
			break;
		case 2 : 
			return expSmooth(weight);
			break;
		
	}
}

int Flex::getMinInput(){
	return minInput;
}

int Flex::getMaxInput(){
	return maxInput;
}

void Flex::setMaxInput(int maxInput){
	this->maxInput = maxInput;
}	

void Flex::setMinInput(int minInput){
	this->minInput = minInput;
}

void Flex::setMinMaxInput(int minInput, int maxInput){
	this->minInput = minInput;
	this->maxInput = maxInput;
}

void Flex::Calibrate(){
	updateVal();
	int val = getSensorValue();
	if(val > maxInput) maxInput = val;
	if(val < minInput) minInput = val;
}

void Flex::updateVal(){
	readIndex++;
	if(readIndex >= numReadings) readIndex = 0;
	vals[readIndex] = analogRead(sensorPin);
}

bool Flex::isBent(){
	if(map(getSensorValue(), minInput, maxInput, 0, 100) <= 40) return true;
	else return false;
}

int Flex::noSmooth(){
	return vals[readIndex];
}

int Flex::avgSmooth(){
	double avg = 0;
	for(int i = 0; i < numReadings; i++){
		avg += vals[i];
	}
	return (int)(avg / (double)numReadings);
}

int Flex::runAvgSmooth(){
	double avg = 0;
	readIndex = 0;
	for(int i = 0; i < numReadings; i++){
		updateVal();
		avg += vals[i];
		delayMicroseconds(10);
	}
	avg = avg / (double)numReadings;
	return (int)avg;
}

int Flex::expSmooth(int weight){
	double avg = 0;
	int index = readIndex;
	double w = (double)weight / (100.0);
	if(index == 0) index = numReadings-1;
	avg = (w * vals[readIndex]) + ((1-w) * expVals[index]);
	expVals[readIndex] = (int)avg;
	return (int)avg;
}