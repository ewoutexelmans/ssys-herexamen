//#include <Servo.h>
//#define servoPin 9

int angle = 0;


//Servo myservo;

void setup()
{
  Serial.begin(9600);
  //myservo.attach(servoPin);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    angle = Serial.parseInt();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(angle, DEC);
  }
}
