//#pragma once
#ifndef NRF24_H
#define NRF24_H
#include <Definition.h>
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


class NRF24{
    public:
        NRF24();
        ~NRF24();

        void init();
        char* readData();
        void sendData(const char* inData);
        RF24* getRadioRef();
    protected:
    private:
        RF24 radio;
};

#endif