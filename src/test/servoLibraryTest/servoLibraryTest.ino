#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(9);
}

void loop() {
  myservo.write(0); //clockwise rotation
  delay(1365);      // time for 360° rotation
  myservo.write(90);  // stop servo
  delay(1200);
  myservo.write(180); //counterclockwise rotation
  delay(1365);
  myservo.write(90);  // stop servo
  delay(1200);
}
