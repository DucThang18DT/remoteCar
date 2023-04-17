//#pragma once
#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
  public:
    Motor();
    ~Motor();
    void init();
    void control(int x, int y);
    void turnLeft();
    void turnRight();
    void Stop();
    void goAhead(); 
    void goBack(); 
};

#endif