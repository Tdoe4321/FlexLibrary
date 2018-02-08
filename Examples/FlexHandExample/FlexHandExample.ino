//Define sensors and servos

#include "FlexHand.h"

Servo ring, thumb, pinky, middle, index;

int servoPin1 = 5; // ring
int servoPin2 = 2; // thumb
int servoPin3 = 9;// pinky
int servoPin4 = 11; // middle
int servoPin5 = 3; // index

int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int flexPin5 = A4;

int fRing = 0;
int fThumb = 0;
int fPinky = 0;
int fMiddle = 0;
int fIndex = 0;

int maxRing = 700;
int maxThumb = 650;
int maxPinky = 700;
int maxMiddle = 640;
int maxIndex = 700;

int minRing = 450;
int minThumb = 380;
int minPinky = 450;
int minMiddle = 480;
int minIndex = 450;

void setup()
{
	//Attach the servo objects to their respective pins
	ring.attach(servoPin1);
	thumb.attach(servoPin2);
	pinky.attach(servoPin3);
	middle.attach(servoPin4);
	index.attach(servoPin5);

	/* set each servo pin to output; I'm not acutally sure if this is
	even necessary, but I did just in case it is */
	pinMode(servoPin1, OUTPUT);
	pinMode(servoPin2, OUTPUT);
	pinMode(servoPin3, OUTPUT);
	pinMode(servoPin4, OUTPUT);
	pinMode(servoPin5, OUTPUT);

	//Set each flex sensor pin to input: this is necessary
	pinMode(flexPin1, INPUT);
	pinMode(flexPin2, INPUT);
	pinMode(flexPin3, INPUT);
	pinMode(flexPin4, INPUT);
	pinMode(flexPin5, INPUT);

	ring.write(90);
	thumb.write(90);
	pinky.write(90);
	middle.write(90);
	index.write(90);

	delay(3000);

	Serial.begin(9600);

	//  for(int i = 0; i < 300; i++){
	//      fRing = analogRead(flexPin1);
	//      fThumb = analogRead(flexPin2);
	//      fPinky = analogRead(flexPin3);
	//      fMiddle = analogRead(flexPin4);
	//      fIndex = analogRead(flexPin5);
	//      
	//    if(fRing > maxRing) maxRing = fRing;
	//    if(fRing < minRing) minRing = fRing;
	//
	//    if(fThumb > maxThumb) maxThumb = fThumb;
	//    if(fThumb < minThumb) minThumb = fThumb;
	//
	//    if(fPinky > maxPinky) maxPinky = fPinky;
	//    if(fPinky < minPinky) minPinky = fPinky;
	//
	//    if(fMiddle > maxMiddle) maxMiddle = fMiddle;
	//    if(fMiddle < minMiddle) minMiddle = fMiddle;
	//
	//    if(fIndex > maxIndex) maxIndex = fIndex;
	//    if(fIndex < minIndex) minIndex = fIndex;
	//  
	//    delay(1);
	//    Serial.print("Min: ");
	//    Serial.print(minThumb);
	//    Serial.print("   Max: ");
	//    Serial.println(maxThumb);
	//  }
	//  
}

void loop()
{
//Defines analog input variables
	fThumb = analogRead(flexPin1);
	fIndex = analogRead(flexPin2);
	fMiddle = analogRead(flexPin3);
	fRing = analogRead(flexPin4);
	fPinky = analogRead(flexPin5);

	/* Defines "pos" variables as being proportional to the flex inputs.
	The 400 to 700 value range seemed adequate for my sensors, but you can change
	yours accordingly. */
	int ringPos = map(fRing, minRing, maxRing, 180, 0);
	ringPos = constrain(ringPos, 0, 180);
	int thumbPos = map(fThumb, minThumb, maxThumb, 180, 0);
	thumbPos = constrain(thumbPos, 0, 180);
	int pinkyPos = map(fPinky, minPinky, maxPinky, 0, 180);
	pinkyPos = constrain(pinkyPos, 0, 180);
	int middlePos = map(fMiddle, minMiddle, maxMiddle, 0, 180);
	middlePos = constrain(middlePos, 0, 180);
	int indexPos = map(fIndex, minIndex, maxIndex, 0, 180);
	indexPos = constrain(indexPos, 0, 180);

	Serial.println(fMiddle);


	//Tells servos to move by the amount specified in the "pos" variables
	ring.write(ringPos);
	thumb.write(thumbPos);
	pinky.write(pinkyPos);
	middle.write(middlePos);
	index.write(indexPos);
}
