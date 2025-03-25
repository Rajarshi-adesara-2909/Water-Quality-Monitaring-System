//main.ino

#define GREEN_LED_PIN 0  // Pin for green LED
#define RED_LED_PIN 1    // Pin for red LED

// Function declarations
void tdsSensorSetup();
void temperatureSensorSetup();
void displaySetup();
void sampleTDS();
void sampleTemperature();
float getTDS();
float getTemperature();
float getTurbidity();
float getPH();
bool isDrinkable(float pH, float tds, float turbidity, float temperature);
void displayData(float tds, float temperature, float turbidity, float pH);

void setup() {
  Serial.begin(9600);

  // Initialize sensors and display
  tdsSensorSetup();
  temperatureSensorSetup();
  displaySetup();
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  static unsigned long printTime = millis();

  // Sample sensors
  sampleTDS();
  sampleTemperature();

  // Update every second
  if (millis() - printTime > 1000U) {
    printTime = millis();

    // Gather sensor readings
    float tds = getTDS();
    float temperature = getTemperature();
    float turbidity = getTurbidity();
    float pH = getPH();

    // Serial output
    Serial.print("pH: ");
    Serial.print(pH);
    Serial.print(", TDS: ");
    Serial.print(tds);
    Serial.print(" ppm, Turbidity: ");
    Serial.print(turbidity);
    Serial.print(" NTU, Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    // Display on LCD
    displayData(tds, temperature, turbidity, pH);
  }
}
