//ph.ino 

#define pHSensorPin A3

float getPH() {
  int pHRaw = analogRead(pHSensorPin);
  float pHVoltage = pHRaw * (5.0 / 1023.0);
  return 7.0 + ((2.5 - pHVoltage) / 0.18);  // Adjust based on calibration
}
