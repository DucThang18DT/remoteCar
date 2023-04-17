//#pragma once  

#ifndef SERVOS_H
#define SERVOS_H
#include <Servo.h> 

class servos
{
private:
    Servo reaching;
    Servo pickup;
    Servo bentdown;
    int reachingDegrees;
    int pickupDegrees;
    int bentdownDegrees;
public:
    servos(/* args */);
    ~servos();

    void init();
    void setServoDegrees(int reachingD, int bentdownD, int pickupD);
    void ServosWrite();
    void reachingWrite();
    void bentdownWrite();
    void pickupWrite();
};

#endif