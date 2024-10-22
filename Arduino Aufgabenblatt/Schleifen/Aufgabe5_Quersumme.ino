void setup() {
  Serial.begin(9600);
  Serial.println("Geben Sie eine positive ganze Zahl ein:");
}

void loop() {
  while (Serial.available() == 0) {
    // Warten auf Eingabe
  }

  int number = Serial.parseInt(); // Lese die eingegebene Zahl

  if (number > 0) {
    int sum = 0; // Variable zur Speicherung der Quersumme

    // Berechnung der Quersumme
    while (number > 0) {
      sum += number % 10; // Letzte Ziffer extrahieren und zur Quersumme addieren
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
