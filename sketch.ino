#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

const int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;
unsigned long count = 0;

void setup() {
  pinMode(buttonPin, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Button Counter");
  Serial.begin(9600);
  lcd.setCursor(0, 1);
  lcd.print("Count: 0");
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detect button press (LOW -> HIGH transition)
  if (buttonState == HIGH && lastButtonState == LOW) {
    count++;

    lcd.setCursor(0, 1);
    lcd.print("Count:      "); // Clear old value
    lcd.setCursor(7, 1);
    lcd.print(count);
    Serial.println(count);
    delay(200); // Simple debounce
  }

  lastButtonState = buttonState;
}