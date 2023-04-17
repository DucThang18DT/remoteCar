#include <control/control.h>
//#include <Arduino.h>

control ctrl = control();

void setup() {
  Serial.begin(9600);
  Serial.print("Start");
  ctrl.init();
}

void loop() {
  ctrl.getValue();
  ctrl.sendMessage();
  // ctrl.showLog();
  // Serial.println("LOOP");
  // delay(1000);
}