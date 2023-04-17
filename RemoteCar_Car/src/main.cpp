#include <nrf/nrf24.h>
#include <servo/servos.h>
#include <control/Motor.h>
#include <string.h>

NRF24 nrf = NRF24();
Motor motor = Motor();
servos servs = servos();
long long timeOut{0};

void parseData();

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  nrf.init();
  servs.init();
  timeOut = millis();
}

void loop() {
  parseData();
  if (abs(millis() - timeOut) > 10000)
  {
    Serial.println("Reset");
    motor.init();
    servs.init();
    timeOut = millis();
  }
  // Serial.println("LOOP");
  // delay(500);
}

void parseData()
{
  /**
   * @brief Data format: "A,B,C,D,E'\0'"
   *  A: Value of horizontal axis for car
   *  B: Value of vertical axis for car
   *  C: Value of reaching servo - need convert to degrees
   *  D: Value of bentdown servo - need convert to degrees
   *  E: Value of pickup servo - need onvert to degrees
  **/
  char* receivedData = nrf.readData();
  //Serial.println(receivedData);
  if (!strlen(receivedData))
  {
    return;
  }
  char* strData[5];
  strData[0] = strtok(receivedData, ",");
  for (int index = 0; index < 4; index++)
  {
    if (strData[index] != nullptr)
    {
      strData[index+1] = strtok(NULL, ",");
    }
    else
    {
      return;
    }
  }
  int dataVal[5] = {0};
  for (int index = 0; index < 5; index++)
  {
    dataVal[index] = String(strData[index]).toInt();
    if (dataVal[index] < 0)
    {
      dataVal[index] = 0;
    }
    if (dataVal[index] > MAX_VALUE)
    {
      dataVal[index] = MAX_VALUE;
    }
    dataVal[index] = int((float(dataVal[index] * 180.0 )) / MAX_VALUE);
  }

  motor.control(dataVal[0], dataVal[1]);  
  servs.setServoDegrees(dataVal[2], dataVal[3], dataVal[4]);
  timeOut = millis();
}