#include <Servo.h>
#include <math.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <printf.h>

#define servoPin 9
#define cePin 2
#define csPin 3

RF24 radio(cePin, csPin);
const uint64_t add1 = 0x0a0c0a0c0aLL;
char msg[10];



Servo myservo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(servoPin); radio.begin();
  printf_begin();
  radio.openReadingPipe(1, add1);
  radio.startListening();
}

void loop() {
  rotate(Angle());
}

int Angle() {
  float data = 0;
  int angle = 0;
  if (Serial.available() > 0) {
    // read the incoming byte:
    data = Serial.parseFloat();
    if (data > 0) {
      // say what you got:
      Serial.print("rotate servo ");
      Serial.print((int)data, DEC);
      Serial.println("° clockwise.");
      angle = round(data * 3.7917);

    } else if (data < 0) {
      Serial.print("rotate servo ");
      Serial.print(abs((int)data), DEC);
      Serial.println("° counterclockwise.");
      angle = round(data * 3.7917);
    } else {
      Serial.println("No angle larger then 0° given.");
    }
  }
  return angle;
}

void rotate(int angle) {
  if (angle > 0) {
    myservo.write(0);
    delay(angle);
  } else if (angle < 0) {
    myservo.write(180);
    delay(abs(angle));
  }
  myservo.write(90);

}

