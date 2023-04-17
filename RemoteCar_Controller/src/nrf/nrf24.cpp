#include "nrf24.h"

NRF24::NRF24()//:radio { RF24(CE_PIN, CSN_PIN)}
{
  //Serial.begin(9600);
  // Serial.print("Init NRF");
  // delay(500);
  // pinMode(CE_PIN, OUTPUT);
  // pinMode(CSN_PIN, OUTPUT);
  //init();
}

NRF24::~NRF24(){
    // delete [] readAddress;
    // delete [] writeAddress;
}

void NRF24::init(){
  Serial.println("Cannot start module...!");
  radio = RF24(CE_PIN, CSN_PIN);

  while (!radio.begin())
  {
    Serial.println("Cannot start module...!");
    delay(500);
  }
  radio.openReadingPipe(NUM_PIPE, (byte*)CHANNEL_READ_ADDRESS);
  radio.openWritingPipe((byte*)CHANNEL_SEND_ADDRESS);
  radio.setPALevel(RF24_PA_MIN); 
  radio.setChannel(Chanel); 
  radio.setDataRate(RF24_250KBPS); 
  radio.startListening(); 
  if(!radio.available())
  {
      Serial.println("Cannot connect to TX...!");
      Serial.println("Waiting...");
  } 
}

char* NRF24::readData(){
  static char* text = new char[TXT_MAX_LEN];
  memset(text, 0, TXT_MAX_LEN);
  if(radio.available())
  {
    radio.read(text, TXT_MAX_LEN); 
  }
  return text;
}

void NRF24::sendData(const char* inData){
  radio.stopListening();
  radio.write(inData, strlen(inData));
  radio.startListening();
}

RF24* NRF24::getRadioRef(){
  return &radio;
}