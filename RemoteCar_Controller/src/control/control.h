#ifndef CONTROL_H
#define CONTROL_H
#include <nrf/nrf24.h>

class control
{
private:
    int leftX;
    int leftY;
    bool leftSW;
    int rightX;
    int rightY;
    bool rightSW;
    NRF24 nrf;
public:
    control(/* args */);
    ~control();

    void init();
    void getValue();
    void showLog();
    char* makeMessage();
    void sendMessage();
};

#endif