void setup() {
  // Serielle Kommunikation starten
  Serial.begin(9600);
  
  // Aufforderung zur Eingabe einer Jahreszahl
  Serial.println("Geben Sie eine Jahreszahl ein:");
}

void loop() {
  int year;
  
  // Überprüfen, ob Daten zur Verfügung stehen
  if (Serial.available() > 0) {
    // Lesen der eingegebenen Jahreszahl
    year = Serial.parseInt();
    
    // Überprüfen, ob die Jahreszahl ein Schaltjahr ist
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      Serial.print(year);
      Serial.println(" ist ein Schaltjahr.");
    } else {
      Serial.print(year);
      Serial.println(" ist kein Schaltjahr.");
    }
    
    // Leere den Eingabepuffer, um erneute Eingaben zu ermöglichen
    while (Serial.available() > 0) {
      Serial.read();
    }
    
    // Warten auf die nächste Eingabe
    Serial.println("Geben Sie eine neue Jahreszahl ein:");
  }
}
