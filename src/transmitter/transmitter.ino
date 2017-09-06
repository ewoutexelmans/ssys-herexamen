#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <printf.h>

#define cePin 2
#define csPin 3

RF24 radio(cePin, csPin); 
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
  Serial.readBytesUntil('\n', msg, sizeof(msg));
  Serial.println(msg);
  radio.write(msg, sizeof(msg));
  memset(msg, 0, sizeof(msg));
}

