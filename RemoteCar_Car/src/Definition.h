//#pragma once
#ifndef DEFINITION_H
#define DEFINITION_H

#define MAX_VALUE   1023

// NRF
#define CE_PIN  7
#define CSN_PIN 8
#define NUM_PIPE 1
#define  TXT_MAX_LEN 100
const char CHANNEL_READ_ADDRESS[6] = "00002";
const char CHANNEL_SEND_ADDRESS[6] = "00001";
#define Chanel 85
#define Bandwidth 250 

// Motor
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5   
#define MIN_THRESHOLD   80
#define MAX_THRESHOLD  100


// Servo
#define REACHING    6
#define PICKUP      9
#define BENTDOWN    10
#define WAIT_WRITE  30
#define INIT_DEGREES    90
#define PICK_PRESS      60
#define REACH_MIN       20
#define REACH_MAX       180
#define BENT_MIN        30
#define BENT_MAX        170

#endif