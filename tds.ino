//tds.ino 

#define TdsSensorPin A2
#define SCOUNT 30
#define VREF 5.0

int analogBuffer[SCOUNT];
int analogBufferIndex = 0;
float tdsValue = 0;

void tdsSensorSetup() {
  pinMode(TdsSensorPin, INPUT);
}

void sampleTDS() {
  static unsigned long analogSampleTime = millis();
  if (millis() - analogSampleTime > 40U) {
    analogSampleTime = millis();
    analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);
    analogBufferIndex++;
    if (analogBufferIndex == SCOUNT) analogBufferIndex = 0;
  }
}

float getTDS() {
  float averageVoltage = 0;
  for (int i = 0; i < SCOUNT; i++) averageVoltage += analogBuffer[i];
  averageVoltage = (averageVoltage / SCOUNT) * VREF / 1024.0;

  float compensationCoefficient = 1.0 + 0.02 * (getTemperature() - 25.0);
  float compensatedVoltage = averageVoltage / compensationCoefficient;
  tdsValue = (133.42 * compensatedVoltage * compensatedVoltage * compensatedVoltage 
              - 255.86 * compensatedVoltage * compensatedVoltage 
              + 857.39 * compensatedVoltage) * 0.5;

  return tdsValue;
}
