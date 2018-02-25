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

FlexHand::FlexHand(int SensorPin){
	this->sensorPin = SensorPin;
	pinMode(sensorPin, INPUT);
	this->maxInput = 700;
	this->minInput = 400;
	this->numReadings = 10;
	this->smoothingType = AVG;
	vals = new int[numReadings];
	expVals = new int[numReadings];
	readIndex = 0;
	this->weight = 0;
	constrain(weight, 0, 100);
	
	for(int i = 0; i < numReadings; i++) vals[i] = 0;
	for(int i = 0; i < numReadings; i++) expVals[i] = 0;
}

FlexHand::FlexHand(int SensorPin, int minInput, int maxInput){
	this->sensorPin = SensorPin;
	pinMode(sensorPin, INPUT);
	this->maxInput = maxInput;
	this->minInput = minInput;
	this->numReadings = 10;
	this->smoothingType = AVG;
	vals = new int[numReadings];
	expVals = new int[numReadings];
	readIndex = 0;
	this->weight = 0;
	constrain(weight, 0, 100);
	
	for(int i = 0; i < numReadings; i++) vals[i] = 0;
	for(int i = 0; i < numReadings; i++) expVals[i] = 0;
}

FlexHand::FlexHand(int SensorPin, int numReadings, int smoothingType, int weight){
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

FlexHand::FlexHand(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType){
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

FlexHand::FlexHand(int SensorPin, int minInput, int maxInput, int numReadings, int smoothingType, int weight){
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

void FlexHand::setSensorPin(int sensorPin){
	this->sensorPin = sensorPin;
}

int FlexHand::getSensorValue(){
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

void FlexHand::Calibrate(){
	//TODO: Edit
}

void FlexHand::updateVal(){
	readIndex++;
	if(readIndex >= numReadings) readIndex = 0;
	vals[readIndex] = analogRead(sensorPin);
}

bool FlexHand::isBent(){
	//TODO Edit
}

int FlexHand::noSmooth(){
	return vals[readIndex];
}

int FlexHand::avgSmooth(){
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

int FlexHand::runAvgSmooth(){
	double avg = 0;
	for(int i = 0; i < numReadings; i++){
		avg += vals[i];
	}
	return (int)avg;
}

int FlexHand::expSmooth(int weight){
	double avg = 0;
	int index = readIndex;
	double w = weight / (100.0);
	if(index == 0) index = numReadings-1;
	avg = (w * vals[readIndex]) + ((1-w) * expVals[index]);
	expVals[readIndex] = (int)avg;
}