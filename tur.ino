  //tur.ino

  #define TurbiditySensorPin A1

  float getTurbidity() {
    int turbidityRaw = analogRead(TurbiditySensorPin);
    float turbidityVoltage = turbidityRaw * (5.0 / 1023.0);
    int turbidity = map(turbidityRaw, 0, 750, 100, 0); 
    return turbidity;
  }
