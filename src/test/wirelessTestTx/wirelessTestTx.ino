#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <printf.h>

RF24 radio(2,3);//ce and cs pin
const uint64_t add1 = 0x0a0c0a0c0aLL;
char msg[10];

void setup() {
  Serial.begin(9600);
  radio.begin();
  printf_begin();
  radio.openWritingPipe(add1);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void serialEvent() {
  Serial.readBytesUntil('\n', msg,sizeof(msg));
  radio.write(msg,sizeof(msg));
}

