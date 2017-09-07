#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <printf.h>



#define cePin 9
#define csPin 10

RF24 radio(cePin, csPin); //ce and cs pin
const uint64_t add1 = 0x0a0c0a0c0aLL;
char msg[10];

void setup() {
  Serial.begin(9600);
  radio.begin();
  printf_begin();
  radio.openWritingPipe(add1);
  radio.printDetails();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void serialEvent() {
  bool rslt;
  Serial.readBytesUntil('\n', msg, sizeof(msg));
  Serial.println(msg);
  rslt = radio.write(msg, sizeof(msg));
  if(rslt){
    Serial.println("Acknowledge recieved");
  }else{
    Serial.println("Transmission failed");
  }
  memset(msg, 0, sizeof(msg));
}

