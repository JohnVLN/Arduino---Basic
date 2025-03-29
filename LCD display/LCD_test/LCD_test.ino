#include <LiquidCrystal.h>

int cont =120; 
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);
void setup() {
  pinMode(9, OUTPUT);
  analogWrite(8,cont);
  lcd.begin(16, 2);
}
void loop() {
  int i = 0;
  digitalWrite(9, 1);
  while(i < 3){
    lcd.setCursor(4, 0);
  	lcd.print("DANGER!!");
  	lcd.setCursor(2, 1);
  	lcd.print("LOW OXYGEN!!");
  	delay(500);
  	lcd.clear();
  	delay(500);
    i += 1;
  }
  digitalWrite(9, 0);
  delay(1000);
}