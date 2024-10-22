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
    int einsen = countOnes(number); // Anzahl der Einsen zählen

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

int countOnes(int number) {
  int einsen = 0; // Zähler zurücksetzen für jede neue Eingabe

  while (number > 0) {
    int digit = number % 10; // Letzte Ziffer extrahieren
    if (digit == 1) {
      einsen++; // Zähler erhöhen, wenn die Ziffer 1 ist
    }
    number /= 10; // Ziffer entfernen
  }

  return einsen; // Anzahl der Einsen zurückgeben
}
