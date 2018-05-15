#include "FlexLibrary.h"

Flex flex(A1); // Analog pin the flex sensor is on

String debug = "";

void setup(){
  Serial.begin(9600);

  for(int i = 0; i < 1000; i++){
    flex.Calibrate();
  }

  Serial.print("Min Value: ");
  Serial.println(flex.getMinInput());
  Serial.print("Max Value: ");
  Serial.println(flex.getMaxInput());

  delay(5000);
}

void loop(){
  flex.updateVal();

  debug = ((String)"Val: " + flex.getSensorValue());
  Serial.println(debug);

}
