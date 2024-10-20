void setup() {
  Serial.begin(9600); // Initialisiere die serielle Kommunikation mit 9600 Baud
  Serial.println("Geben Sie eine Zahl ein:"); // Fordere den Benutzer auf, eine Zahl einzugeben
}

void loop() {
  // Überprüfen, ob Daten verfügbar sind
  if (Serial.available() > 0) {
    int zahl = Serial.parseInt(); // Lese die eingegebene Zahl

    Serial.print("Zähle bis "); // Zeige an, bis wohin gezählt wird
    Serial.println(zahl);
    
    // Zähle von 1 bis zur eingegebenen Zahl
    for (int i = 1; i <= zahl; i++) {
      Serial.println(i); // Gebe jede Zahl auf dem seriellen Monitor aus
    }
    
    Serial.println("Fertig!"); // Zeige an, dass das Zählen beendet ist
    delay(2000); // Kurze Pause, um das Ergebnis zu lesen
    Serial.println("Geben Sie eine weitere Zahl ein:"); // Fordere den Benutzer auf, eine neue Zahl einzugeben
  }
}
