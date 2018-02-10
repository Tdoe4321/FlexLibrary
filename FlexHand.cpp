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
	setMaxOutput(180);
	setMinOutput(0);
	setMaxInput(700);
	setMinInput(400);
	setIsOuptutReversed(false);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(180);
	setMinOutput(0);
	setMaxInput(700);
	setMinInput(400);
	setIsOuptutReversed(false);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin, int minOutput, int maxOutput){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(maxOutput);
	setMinOutput(minOutput);
	setMaxInput(700);
	setMinInput(400);
	setIsOuptutReversed(false);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin, int minInput, int maxInput, int minOutput, int maxOutput){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(maxOutput);
	setMinOutput(minOutput);
	setMaxInput(minInput);
	setMinInput(maxInput);
	setIsOuptutReversed(false);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin, int minOutput, int maxOutput, bool isOutputReversed){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(maxOutput);
	setMinOutput(minOutput);
	setMaxInput(700);
	setMinInput(400);
	setIsOuptutReversed(isOutputReversed);
	this.servo.attach(outputPin);
	pinMode(SensorPin, INPUT);
}

FlexHand::FlexHand(int SensorPin, int OutputPin, int minInput, int maxInput, int minOutput, int maxOutput, bool isOutputReversed){
	setSensorPin(SensorPin);
	setOutputPin(OutputPin);
	setMaxOutput(maxOutput);
	setMinOutput(minOutput);
	setMaxInput(minInput);
	setMinInput(maxInput);
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

void FlexHand::setMaxOutput(int maxOutput){
	this.maxOutput = maxOutput;
}

void FlexHand::setMinOutput(int minOutput){
	this.minOutput = minOutput;
}

void FlexHand::setMaxInput(int maxInput){
	this.maxInput = maxInput;
}	

void FlexHand::setMinInput(int minInput){
	this.minInput = minInput;
}

void FlexHand::setMinMaxOutput(int minOutput, int maxOutput){
	this.minOutput = minOutput;
	this.maxOutput = maxOutput;
}

void FlexHand::setMinMaxInput(int minInput, int maxInput){
	this.minInput = minInput;
	this.maxInput = maxInput;
}

bool FlexHand::getIsOutputReversed(){
	return isOutputReversed;
}

void FlexHand::setIsOuptutReversed(bool isOutputReversed){
	this.isOutputReversed = isOutputReversed;
}

int FlexHand::getTranslatedValue(){ 
	return isOutputReversed ? map(sensorValue, minInput, maxInput, minOutput, maxOutput) : map(sensorValue, minInput, maxInput, minOutput, maxOutput);
}

void FlexHand::turn(int deg){
	isOutputReversed ? servo.write(180 - deg) : servo.write(deg);
}


void FlexHand::calcAndTurn(){
	calculateDeg();
	isOutputReversed ? servo.write(180 - deg) : servo.write(deg);
}