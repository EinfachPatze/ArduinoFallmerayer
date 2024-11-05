void setup() {
  Serial.begin(9600); // Initialisiere die serielle Kommunikation
  Serial.println("Geben Sie Zahlen ein (negative Zahl zum Beenden):");
}

void loop() {
  // Überprüfen, ob Daten verfügbar sind
  if (Serial.available() > 0) {
    unsigned long int zahl = Serial.parseInt(); // Lese die eingegebene Zahl

    // Überprüfen, ob die Zahl negativ ist
    if (zahl < 0) {
      Serial.println("Negative Zahl eingegeben. Programm beendet.");
      while (true); // Beende das Programm (schleife unendlich)
    } else {
      Serial.print("Positive Zahl: "); 
      Serial.println(zahl); // Gebe die positive Zahl aus
    }
  }
}
