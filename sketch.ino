#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int buttonPin = 2;

long fib(int n) {
  if (n <= 1) return n; return fib(n - 1) + fib(n - 2);
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init(); lcd.backlight();
  randomSeed(analogRead(0));
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(100); 
    int n = random(5, 31);
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("i: "); lcd.print(n);
    unsigned long start = micros(); long result = fib(n);
    unsigned long end = micros(); float timeSec = (end - start) / 1000000.0;
    lcd.setCursor(0, 1); lcd.print("Time: "); 
    lcd.print(timeSec, 5); lcd.print("s");
    lcd.setCursor(0, 2); lcd.print("Fib: "); lcd.print(result);
    delay(500);
  }
}