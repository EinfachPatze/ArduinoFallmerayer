int einsen = 0; // Zähler für die Einsen

void setup() {
  Serial.begin(9600); // Initialisiere die serielle Kommunikation
  Serial.println("Geben Sie eine positive ganze Zahl ein:");
}

void loop() {
  if (Serial.available() > 0) {
    int number = Serial.parseInt(); // Lese die eingegebene Zahl

    if (number > 0) {
      einsen = 0; // Zähler zurücksetzen für jede neue Eingabe
      int sum = 0; 

      while (number > 0) {
        int digit = number % 10; // Letzte Ziffer extrahieren
        if (digit == 1) {
            einsen++; // Zähler erhöhen, wenn die Ziffer 1 ist
        }
        number /= 10; // Ziffer entfernen
      }

      // Ausgabe der Anzahl der Einsen
      Serial.print("Die Zahl enthält ");
      Serial.print(einsen); // Zähler ausgeben
      Serial.println(" Einsen");
    } else {
      Serial.println("Bitte geben Sie eine positive ganze Zahl ein.");
    }
    
    delay(5000); // Warte 5 Sekunden
    Serial.println("Geben Sie eine weitere positive ganze Zahl ein:");
  }
}
