void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten

  // Berechnungen durchführen
  float result1 = (1 + 7) * 3.0 / 7;
  float result2 = 15 + 6 * 3;
  float result3 = 63 - 4 + 6.0 / 9;

  // Ergebnisse ausgeben
  Serial.println(result1);
  Serial.println(result2);
  Serial.println(result3);
}

void loop() {}
