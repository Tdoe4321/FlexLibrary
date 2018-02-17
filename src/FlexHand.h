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

#define AVG 0
#define RUN_AVG 1
#define EXP 2

class FlexHand {
private:
	int sensorPin;  // The analog pin the Flex sensor is read into 
	int maxInput;  	// Max Input on the flex sensors themselves - this is used for calibration on the sensors
	int minInput;	// Min Input on the flex sensors themselves - this is used for calibration on the sensors
	int numReadings; // The number of reading you want to take into the Averaging Process
	int* Vals; // An array of Values
	int readIndex; // Where we are in the averaging process
	int smoothingType;
	
public:
	FlexHand(int SensorPin);

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