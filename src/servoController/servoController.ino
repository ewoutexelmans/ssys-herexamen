#include <Servo.h>
#include <math.h>

#define servoPin 9




Servo myservo;

void setup()
{
  Serial.begin(9600);
  myservo.attach(servoPin);
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
      Serial.print(data, DEC);
      Serial.println("° clockwise.");
      angle = round(data * 3.7917);

    } else if (data < 0) {
      Serial.print("rotate servo ");
      Serial.print(data, DEC);
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
    delay(angle)
  } else if (angle < 0) {
    myservo.write(180);
    delay(abs(angle));
  }
  myservo.write(90);

}

