//tamp.ino 

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temperature = 25.0;

void temperatureSensorSetup() {
  sensors.begin();
}

void sampleTemperature() {
  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);
}

float getTemperature() {
  return temperature;
}
