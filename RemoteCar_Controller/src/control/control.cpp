#include "control.h"

control::control(/* args */)
{
    nrf = NRF24();
    
}

control::~control()
{
}

void control::init()
{
    nrf.init();
    // pinMode(LEFT_SW, INPUT);
    // pinMode(RIGHT_SW, INPUT);
    getValue();
}

void control::getValue()
{
    leftX = analogRead(LEFT_X);
    leftY = analogRead(LEFT_Y);
    rightX = analogRead(RIGHT_X);
    rightY = analogRead(RIGHT_Y);
    int leftSWPressed[READ_NUM];
    int rightSWPressed[READ_NUM];
    for (int index = 0; index < READ_NUM; index++)
    {
        leftSWPressed[index] = analogRead(LEFT_SW);
        rightSWPressed[index] = analogRead(RIGHT_SW);
    }
    for (int index = 0; index <READ_NUM; index++)
    {
        if (leftSWPressed[index] == 0){
            int count = 1;
            while ((leftSWPressed[index + count] == 0) && ((index + count) < READ_NUM))
            {
                ++count;
            }
            leftSW = (count >= (READ_NUM*2/3))? true: false;
            if (leftSW) break;
        }
    }
    for (int index = 0; index <READ_NUM; index++)
    {
        if (rightSWPressed[index] == 0){
            int count = 1;
            while ((rightSWPressed[index + count] == 0) && ((index + count) < READ_NUM))
            {
                ++count;
            }
            rightSW = (count >= (READ_NUM*2/3))? true: false;
            if (rightSW) break;
        }
    }
}

void control::showLog()
{
    Serial.print("left X = ");
    Serial.println(leftX);
    Serial.print("left Y = ");
    Serial.println(leftY);
    Serial.print("right X = ");
    Serial.println(rightX);
    Serial.print("right Y = ");
    Serial.println(rightY);
    Serial.print("left SW = ");
    Serial.println(leftSW);
    Serial.print("right SW = ");
    Serial.println(rightSW);
}

char* control::makeMessage()
{
    static char message[125] = {0};
    String mess = String(leftX) + "," + String(leftY)+ "," + String(rightY) + "," 
        + String(rightX) + "," + String(rightSW? MAX_VALUE: 0);
    strcpy(message, mess.c_str());
    return message;
}

void control::sendMessage()
{
    nrf.sendData(makeMessage());
}