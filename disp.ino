//disp.ino

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust I2C address if necessary

void displaySetup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Water Quality Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("----Welcome!----");
  lcd.setCursor(0, 1);
  lcd.print("-System Ready-->");
  delay(2000);
  lcd.clear();
}

void displayData(float tds, float temperature, float turbidity, float pH) {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("pH:");
  lcd.print(pH, 1);
  lcd.setCursor(8, 0);
  lcd.print("TDS:");
  lcd.print(tds, 0);

  lcd.setCursor(0, 1);
  lcd.print("Tur:");
  lcd.print(turbidity, 1);
  lcd.setCursor(8, 1);
  lcd.print("Temp:");
  lcd.print(temperature, 1);

  delay(2000);

  if (isDrinkable(pH, tds, turbidity, temperature)) {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Drinkable: YES");
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(300);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(300);
  } else {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Drinkable: NO");
    digitalWrite(RED_LED_PIN, HIGH);
    delay(300);
    digitalWrite(RED_LED_PIN, LOW);
    delay(300);
  }
  delay(1500);
}

bool isDrinkable(float pH, float tds, float turbidity, float temperature) {
  // Drinking water standards (adjust turbidity threshold)
  const float MIN_PH = 6.4;
  const float MAX_PH = 8.5;
  const float MAX_TDS = 150.0;
  const float MAX_TURBIDITY = 20.0; // Increased turbidity threshold to 10 NTU
  const float MAX_TEMP = 40.0; // Temperature in Celsius

  // Check if water is drinkable based on pH, TDS, turbidity, and temperature
  if (pH >= MIN_PH && pH <= MAX_PH && tds <= MAX_TDS && turbidity <= MAX_TURBIDITY && temperature <= MAX_TEMP) {
    return true;  // Water is drinkable
  }
  return false;  // Water is not drinkable
}
