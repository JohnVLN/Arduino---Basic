#include <Servo.h>

Servo servo;
int pos;
int input = 0;

void setup(){
  servo.attach(9);
}

void loop(){
  pos = analogRead(input);
  pos = map(pos, 0, 1023, 0, 180);
  servo.write(pos);
  delay(20);
}