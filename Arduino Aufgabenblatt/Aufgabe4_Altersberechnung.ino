void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
}

void loop() {
  int currentYear, birthYear, age;

  // Aktuelles Jahr einlesen
  Serial.println("Gib das aktuelle Jahr ein:");
  while (Serial.available() == 0) {}
  currentYear = Serial.parseInt();

  // Geburtsjahr einlesen
  Serial.println("Gib dein Geburtsjahr ein:");
  while (Serial.available() == 0) {}
  birthYear = Serial.parseInt();

  // Alter berechnen
  age = currentYear - birthYear;
  Serial.println("Du bist " + String(age) + " Jahre alt."); // Ausgabe des Alters

  delay(5000); // Kurze Pause vor dem nächsten Durchlauf
}
