void setup() {
  Serial.begin(9600); // Initialisiere die serielle Kommunikation
  Serial.println("Geben Sie eine positive ganze Zahl ein:");
}

void loop() {
  // Überprüfen, ob Daten verfügbar sind
  if (Serial.available() > 0) {
    int number = Serial.parseInt(); // Lese die eingegebene Zahl

    // Überprüfen, ob die Zahl positiv ist
    if (number > 0) {
      int sum = 0; // Variable zur Speicherung der Quersumme

      // Berechnung der Quersumme
      while (number > 0) {
        int digit = number % 10; // Letzte Ziffer extrahieren
        sum += digit; // Ziffer zur Quersumme addieren
        number /= 10; // Ziffer entfernen
      }

      // Ausgabe der Quersumme
      Serial.print("Die Quersumme ist: ");
      Serial.println(sum);
    } else {
      Serial.println("Bitte geben Sie eine positive ganze Zahl ein.");
    }
    
    delay(5000); // Warte 5 Sekunden, bevor die nächste Eingabe angenommen wird
    Serial.println("Geben Sie eine weitere positive ganze Zahl ein:");
  }
}
