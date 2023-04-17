#include "Motor.h"
#include <Arduino.h>
#include <Definition.h>

Motor::Motor()
{
    init();
}

Motor::~Motor()
{

}

void Motor::init()
{
    pinMode (IN1, OUTPUT); 
    pinMode (IN2, OUTPUT);
    pinMode (IN3, OUTPUT);
    pinMode (IN4, OUTPUT);
    Stop();
}

void Motor::control(int x, int y)
{
    if (y <= MIN_THRESHOLD){
    goBack();
  }
  else if (y >= MAX_THRESHOLD )
  {
    goAhead();
  }
  else
  {
    if (x <= MIN_THRESHOLD)
    {
      turnLeft();
    }
    else if (x >= MAX_THRESHOLD)
    {
      turnRight();
    }
    else 
    {
      Stop();
    }
  }
}

void Motor::turnLeft() 
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void Motor::turnRight() 
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void Motor::Stop() 
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void Motor::goBack()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void Motor::goAhead()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}
