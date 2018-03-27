#include "FlexLibrary.h"
#include <Servo.h>

Servo ringS, thumbS, pinkyS, middleS, indexS;

String debug = "";

int servoPin1 = 5; // ring
int servoPin2 = 2; // thumb
int servoPin3 = 9;  // pinky
int servoPin4 = 11; // middle
int servoPin5 = 3; // index

int maxRing = 580;
int maxThumb = 600;
int maxPinky = 620;
int maxMiddle = 570;
int maxIndex = 575;

int minRing = 420;
int minThumb = 440;
int minPinky = 420;
int minMiddle = 440;
int minIndex = 450;

Flex ring(A3, minRing, maxRing, 10, RUN_AVG, 0);
Flex thumb(A0, minThumb, maxThumb, 10, RUN_AVG, 0);
Flex pinky(A4, minPinky, maxPinky, 10, RUN_AVG, 0);
Flex middle(A2, minMiddle, maxMiddle, 10, RUN_AVG, 0);
Flex index(A1, minIndex, maxIndex, 10, RUN_AVG, 0);

void setup(){
  Serial.begin(9600);
  
  ringS.attach(servoPin1);
  thumbS.attach(servoPin2);
  pinkyS.attach(servoPin3);
  middleS.attach(servoPin4);
  indexS.attach(servoPin5);
  
  ringS.write(90);
  thumbS.write(90);
  pinkyS.write(90);
  middleS.write(90);
  indexS.write(90);

  delay(3000);

//  for(int i = 0; i < 1000; i++){
//    ring.Calibrate();
//    thumb.Calibrate();
//    pinky.Calibrate();
//    middle.Calibrate();
//    index.Calibrate();
//  }
}

void loop(){
  ring.updateVal();
  thumb.updateVal();
  pinky.updateVal();
  middle.updateVal();
  index.updateVal();

  int ringPos = map(ring.getSensorValue(), minRing, maxRing, 180, 0);
  ringPos = constrain(ringPos, 0, 180);
  int thumbPos = map(thumb.getSensorValue(), minThumb, maxThumb, 180, 0);
  thumbPos = constrain(thumbPos, 0, 180);
  int pinkyPos = map(pinky.getSensorValue(), minPinky, maxPinky, 0, 180);
  pinkyPos = constrain(pinkyPos, 0, 180);
  int middlePos = map(middle.getSensorValue(), minMiddle, maxMiddle, 0, 180);
  middlePos = constrain(middlePos, 0, 180);
  int indexPos = map(index.getSensorValue(), minIndex, maxIndex, 0, 180);
  indexPos = constrain(indexPos, 0, 180);

  
  //Tells servos to move by the amount specified in the "pos" variables
  ringS.write(ringPos);
  thumbS.write(thumbPos);
  pinkyS.write(pinkyPos);
  middleS.write(middlePos);
  indexS.write(indexPos);

  //debug = ((String)"Thumb: " + thumbPos + "\tIndex: " + indexPos + "\tMiddle: " + middlePos + "\tRing: " + ringPos + "\tPinky: " + pinkyPos);
  debug = ((String)"Thumb: " + thumb.getSensorValue() + "\tIndex: " + index.getSensorValue() + "\tMiddle: " + middle.getSensorValue() + "\tRing: " + ring.getSensorValue() + "\tPinky: " + pinky.getSensorValue());
  Serial.println(debug);

}
