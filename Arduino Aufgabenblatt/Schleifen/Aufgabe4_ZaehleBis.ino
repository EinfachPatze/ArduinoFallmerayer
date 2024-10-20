void setup() {
  Serial.begin(9600); // Initialisiere die serielle Kommunikation
  Serial.println("Geben Sie Zahlen ein (negative Zahl zum Beenden):");
}

void loop() {
  // Überprüfen, ob Daten verfügbar sind
  if (Serial.available() > 0) {
    int zahl = Serial.parseInt(); // Lese die eingegebene Zahl

    // Überprüfen, ob die Zahl negativ ist
    if (zahl < 0) {
      Serial.println("Negative Zahl eingegeben. Programm beendet.");
      while (true); // Beende das Programm (schleife unendlich)
    } else {
      Serial.print("Zähle bis "); 
      Serial.println(zahl); // Gebe die positive Zahl aus
      
      // Zähle von 1 bis zur eingegebenen Zahl
      for (int i = 1; i <= zahl; i++) {
        Serial.println(i); // Gebe jede Zahl auf dem seriellen Monitor aus
      }
    }
  }
}
