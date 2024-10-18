void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
}

void loop() {
  int height, age;

  // Höhe des Baums einlesen
  Serial.println("Gib die Höhe des Baums ein (in Metern):");
  while (Serial.available() == 0) {}
  height = Serial.parseInt();

  // Alter des Baums einlesen
  Serial.println("Gib das Alter des Baums ein (in Jahren):");
  while (Serial.available() == 0) {}
  age = Serial.parseInt();

  // Entscheidung, ob der Baum gefällt werden soll
  if (height > 20 && age > 70) {
    Serial.println("Der Baum soll gefällt werden."); // Baum fällen
  } else {
    // Gründe angeben, warum der Baum nicht gefällt werden soll
    if (height <= 20 && age <= 70) {
      Serial.println("Der Baum ist zu jung und zu klein."); // Baum ist zu klein und zu jung
    } else if (height <= 20) {
      Serial.println("Der Baum ist zu klein."); // Baum ist zu klein
    } else if (age <= 70) {
      Serial.println("Der Baum ist zu jung."); // Baum ist zu jung
    }
  }

  delay(5000); // Kurze Pause vor dem nächsten Durchlauf
}
