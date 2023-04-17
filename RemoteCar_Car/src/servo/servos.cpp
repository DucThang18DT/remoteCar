#include "servos.h"
#include <Arduino.h>
#include <Definition.h>

servos::servos(/* args */)
{
    //init();
}

servos::~servos()
{
}

void servos::init()
{
    reachingDegrees = INIT_DEGREES;
    pickupDegrees = INIT_DEGREES;
    bentdownDegrees = INIT_DEGREES;
    // reaching.attach(REACHING);
    // reaching.write(INIT_DEGREES);
    // delay(WAIT_WRITE);
    // reaching.detach();
    // pickup.attach(REACHING);
    // pickup.write(INIT_DEGREES);
    // delay(WAIT_WRITE);
    // pickup.detach();
    // bentdown.attach(REACHING);
    // bentdown.write(INIT_DEGREES);
    // delay(WAIT_WRITE);
    // bentdown.detach();
}

void servos::setServoDegrees(int reachingD, int bentdownD, int pickupD)
{
    bool reachChanged = false;
    bool picChanged = false;
    bool bentChanged = false;
    if ((reachingD >=0) && (reachingD <= 180))
    {
        reachingD = 180 - reachingD;
        if (reachingD < REACH_MIN) reachingD = REACH_MIN;
        if (reachingD >REACH_MAX) reachingD = REACH_MAX;
        if (abs(reachingD - reachingDegrees) >= 10)
        {
            reachingDegrees = reachingD;
            reachChanged = true;
        }
    }
    if ((bentdownD >=0) && (bentdownD <= 180))
    {
        if (bentdownD < BENT_MIN) bentdownD = BENT_MIN;
        if (bentdownD > BENT_MAX) bentdownD = BENT_MAX;
        if (abs(bentdownD - bentdownDegrees) >= 10)
        {
            bentdownDegrees = bentdownD;
            bentChanged = true;
        }
    }
    if ((pickupD >=0) && (pickupD <= 180))
    {
        if (abs(pickupD - pickupDegrees) >= 10)
        {
            pickupDegrees = pickupD;
            picChanged = true;
        }
    }
    if (reachChanged && bentChanged && picChanged)
    {
        ServosWrite();
    }
    else
    {
        if (reachChanged)
        {
            reachingWrite();
        }
        if (bentChanged)
        {
            bentdownWrite();
        }
        if (picChanged)
        {
            pickupWrite();
        }
    }
}

void servos::ServosWrite()
{
    reaching.attach(REACHING);
    reaching.write(reachingDegrees);
    pickup.attach(PICKUP);
    pickup.write((pickupDegrees > (180/2))? PICK_PRESS: INIT_DEGREES);
    bentdown.attach(BENTDOWN);
    bentdown.write(bentdownDegrees);
    delay(WAIT_WRITE*1.5);
    pickup.detach();
    reaching.detach();
    bentdown.detach();
}

void servos::reachingWrite()
{
    reaching.attach(REACHING);
    reaching.write(reachingDegrees);
    int waitTime = ((180-reachingDegrees)>INIT_DEGREES)? WAIT_WRITE*(180-reachingDegrees)/30: WAIT_WRITE*1.5;
    delay(waitTime);
    reaching.detach();
}

void servos::bentdownWrite()
{
    bentdown.attach(BENTDOWN);
    bentdown.write(bentdownDegrees);
    delay(WAIT_WRITE);
    bentdown.detach();
}

void servos::pickupWrite()
{
    pickup.attach(PICKUP);
    pickup.write((pickupDegrees > (180/2))? PICK_PRESS: INIT_DEGREES);
    delay(WAIT_WRITE);
    pickup.detach();
}