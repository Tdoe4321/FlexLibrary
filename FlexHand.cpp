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
	setSensorPin(SensorPin);
	setOutputPin(-1);
	setMaxOutput(700);
	setMinOutput(400);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(700);
	setMinOutput(400);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin, int maxOutput, int minOutput){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(maxOutput);
	setMinOutput(minOutput);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin, int maxOutput, int minOutput, bool isOutputReversed){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(maxOutput);
	setMinOutput(minOutput);
	setIsOuptutReversed(isOutputReversed);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

void FlexHand::setSensorPin(int sensorPin){
	this.sensorPin = sensorPin;
}

void FlexHand::setOutputPin(int outputPin){
	this.outputPin = outputPin;
}

int FlexHand::getSensorValue(){
	return sensorValue;
}

int FlexHand::getTranslatedValue(){
	return translatedValue;
}

void FlexHand::setMaxOutput(int maxOutput){
	this->maxOutput = maxOutput;
}

void FlexHand::setMinOutput(int minOutput){
	this.minOutput = minOutput;
}

bool FlexHand::getIsOutputReversed(){
	return isOutputReversed;
}

void FlexHand::setIsOuptutReversed(bool isOutputReversed){
	this.isOutputReversed = isOutputReversed;
}

void FlexHand::setMinMax(int minOutput, int maxOutput){
	this.minOutput = minOutput;
	this.maxOutput = maxOutput;
}

void FlexHand::turn(int deg){
	servo.write(deg)
}

void FlexHand::calculateDeg(){
	
}

void FlexHand::calcAndTurn(){
	calculateDeg();
	servo.write(this.translatedValue);
}