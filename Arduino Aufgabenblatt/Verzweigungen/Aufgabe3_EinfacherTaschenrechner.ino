void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
}

void loop() {
  int zahl1, zahl2, ergebnis;
  char operatorInput;

  // Erster Wert einlesen
  Serial.println("Gib die erste Zahl ein:");
  while (Serial.available() == 0) {}
  zahl1 = Serial.parseInt();

  // Zweiter Wert einlesen
  Serial.println("Gib die zweite Zahl ein:");
  while (Serial.available() == 0) {}
  zahl2 = Serial.parseInt();

  // Operator einlesen
  Serial.println("Gib einen Operator ein (+, -, *, /):");
  while (Serial.available() == 0) {}
  operatorInput = Serial.read();

  //Berechnung durchführen
  switch (operatorInput) {
    case '+':
      ergebnis = zahl1 + zahl2;
      Serial.println("Ergebnis: " + String(ergebnis)); 
      break;
    case '-':
      ergebnis = zahl1 - zahl2;
      Serial.println("Ergebnis: " + String(ergebnis)); 
      break;
    case '*':
      ergebnis = zahl1 * zahl2;
      Serial.println("Ergebnis: " + String(ergebnis)); 
      break;
    case '/':
      if (zahl2 != 0) {
        ergebnis = zahl1 / zahl2;
        Serial.println("Ergebnis: " + String(ergebnis)); 
      } else {
        Serial.println("Division durch Null ist nicht erlaubt!"); 
      }
      break;
    default:
      Serial.println("Unbekannter Operator!"); 
      break;
  }
  delay(5000); //Pause nächsten Durchlauf
}
