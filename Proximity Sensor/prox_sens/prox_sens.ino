int trigger = 6;
int echo = 5;

// LEDs
int here = 11;
int there = 10;
int distant = 9;

float duration, distance;

void setup(){
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(distant, OUTPUT);
  pinMode(there, OUTPUT);
  pinMode(here, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = (duration * .0343) / 2;
  
  Serial.print(distance);  
  Serial.println("cm");  
  delay(100);
  
  if(distance >= 80){
    digitalWrite(distant, HIGH);
    digitalWrite(there, LOW);
    digitalWrite(here, LOW);
  } else if(distance < 80 && distance > 40){
    digitalWrite(distant, LOW);
    digitalWrite(there, HIGH);
    digitalWrite(here, LOW);
  } else if(distance < 40 && distance > 15){
    digitalWrite(distant, LOW);
    digitalWrite(there, LOW);
    digitalWrite(here, HIGH);
  } else {
    digitalWrite(distant, LOW);
    digitalWrite(there, LOW);
    digitalWrite(here, HIGH);
    delay(350);
    digitalWrite(here, LOW);
  }
  delay(250);
}