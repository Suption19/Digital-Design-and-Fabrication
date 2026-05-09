#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set LCD to 0x27 and 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define your pins
const int redBtn    = 2;
const int whiteBtn  = 3;
const int yellowBtn = 4;
const int blackBtn  = 5;
const int buzzer    = 6; // Buzzer moved to Pin 6

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM TEST");
  
  // Initialize Buttons (using Internal Pull-up)
  pinMode(redBtn, INPUT_PULLUP);
  pinMode(whiteBtn, INPUT_PULLUP);
  pinMode(yellowBtn, INPUT_PULLUP);
  pinMode(blackBtn, INPUT_PULLUP);
  
  // Initialize Buzzer
  pinMode(buzzer, OUTPUT);
  
  // Quick beep to show it's alive
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
}

void loop() {
  lcd.setCursor(0, 1);
  
  // Read buttons (LOW means pressed because of INPUT_PULLUP)
  bool r = !digitalRead(redBtn);
  bool w = !digitalRead(whiteBtn);
  bool y = !digitalRead(yellowBtn);
  bool b = !digitalRead(blackBtn);

  if (r) {
    lcd.print("RED Button OK   ");
    beep();
  } else if (w) {
    lcd.print("WHITE Button OK ");
    beep();
  } else if (y) {
    lcd.print("YELLOW Button OK");
    beep();
  } else if (b) {
    lcd.print("BLACK Button OK ");
    beep();
  } else {
    lcd.print("Press a button..");
  }
  
  delay(50); // Small delay to stop the LCD from flickering
}

void beep() {
  digitalWrite(buzzer, HIGH);
  delay(20); // Very short beep
  digitalWrite(buzzer, LOW);
}
