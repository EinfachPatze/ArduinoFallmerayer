void setup() {
  Serial.begin(9600); // Initialisiere die serielle Kommunikation
  Serial.println("Geben Sie die Werte fuer a und b ein (z.B. 3 5):");
}

void loop() {
  // Überprüfen, ob Daten verfügbar sind
  if (Serial.available() > 0) {
    int a = Serial.parseInt(); // Lese den ersten Wert (a)
    int b = Serial.parseInt(); // Lese den zweiten Wert (b)

    // Überprüfen, ob beide Werte positive Ganzzahlen sind
    if (a > 0 && b > 0) {
      // Addition mit for-Schleife
      int sumFor = a;
      for (int i = 0; i < b; i++) {
        sumFor += 1; // addiere 1 zu a, b-mal
      }
      Serial.print("Summe (for): "); 
      Serial.println(sumFor);

      // Addition mit while-Schleife
      int sumWhile = a;
      int count = 0;
      while (count < b) {
        sumWhile += 1; // addiere 1 zu a, bis count b erreicht
        count++;
      }
      Serial.print("Summe (while): ");
      Serial.println(sumWhile);

      // Addition mit do...while-Schleife
      int sumDoWhile = a;
      count = 0;
      do {
        sumDoWhile += 1; // addiere 1 zu a
        count++;
      } while (count < b);
      Serial.print("Summe (do...while): ");
      Serial.println(sumDoWhile);

      // Multiplikation mit for-Schleife
      int productFor = 0; // Initialisiere das Produkt
      for (int i = 0; i < b; i++) {
        productFor += a; // addiere a, b-mal
      }
      Serial.print("Produkt (for): ");
      Serial.println(productFor);

      // Multiplikation mit while-Schleife
      int productWhile = 0; // Initialisiere das Produkt
      count = 0;
      while (count < b) {
        productWhile += a; // addiere a, bis count b erreicht
        count++;
      }
      Serial.print("Produkt (while): ");
      Serial.println(productWhile);

      // Multiplikation mit do...while-Schleife
      int productDoWhile = 0; // Initialisiere das Produkt
      count = 0;
      do {
        productDoWhile += a; // addiere a
        count++;
      } while (count < b);
      Serial.print("Produkt (do...while): ");
      Serial.println(productDoWhile);
    } else {
      Serial.println("Fehler: Beide Werte muessen positive Ganzzahlen sein."); // Fehlermeldung
    }

    delay(5000); // Warte 5 Sekunden vor der nächsten Eingabe
    Serial.println("Geben Sie die Werte fuer a und b erneut ein (z.B. 3 5):");
  }
}
