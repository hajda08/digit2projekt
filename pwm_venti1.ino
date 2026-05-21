#include <LiquidCrystal.h>

// LCD bekötése:
// RS = 12, E = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int homersekletPin = A0;
const int ventilatorPin = 9;

const float alsoHatar = 25.0;
const float felsoHatar = 40.0;

void setup() {
  pinMode(ventilatorPin, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ventilator PWM");
  lcd.setCursor(0, 1);
  lcd.print("Inditas...");
  delay(1500);
}

void loop() {
  int analogErtek = analogRead(homersekletPin);

  // Analóg érték átszámítása feszültségre
  float feszultseg = analogErtek * (5.0 / 1023.0);

  // TMP36 hőmérséklet számítása Celsius-fokban
  float homerseklet = (feszultseg - 0.5) * 100.0;

  int pwmErtek = 0;

  if (homerseklet < alsoHatar) {
    pwmErtek = 0;
  } else if (homerseklet >= felsoHatar) {
    pwmErtek = 255;
  } else {
    // 25 és 40 °C között fokozatos fordulatszám-növelés
    pwmErtek = map(homerseklet * 10, alsoHatar * 10, felsoHatar * 10, 80, 255);
  }

  analogWrite(ventilatorPin, pwmErtek);

	
  Serial.print("Homerseklet: ");
  Serial.print(homerseklet);
  Serial.print(" C | PWM: ");
  Serial.println(pwmErtek);

  // LCD kiírás
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hom: ");
  lcd.print(homerseklet, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("PWM: ");
  lcd.print(pwmErtek);

  if (pwmErtek == 0) {
    lcd.print(" OFF");
  } else if (pwmErtek == 255) {
    lcd.print(" MAX");
  } else {
    lcd.print(" ON");
  }

  delay(1000);
}