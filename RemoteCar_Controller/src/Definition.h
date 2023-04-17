//#pragma once
#ifndef DEFINITION_H_
#define DEFINITION_H_

#define MAX_VALUE   1023

// NRF
#define CE_PIN  7
#define CSN_PIN 8
#define NUM_PIPE 1
#define  TXT_MAX_LEN 100
const char CHANNEL_READ_ADDRESS[6] = "00001";
const char CHANNEL_SEND_ADDRESS[6] = "00002";
#define Chanel 85
#define Bandwidth 250 

//controller
#define LEFT_X      A3
#define LEFT_Y      A2
#define RIGHT_X     A1
#define RIGHT_Y     A0
#define LEFT_SW     A5
#define RIGHT_SW    A4
#define READ_NUM    100

#endif