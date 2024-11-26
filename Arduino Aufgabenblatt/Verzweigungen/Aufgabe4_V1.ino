void setup() {
  Serial.begin(9600);

  // Aktuelles Jahr einlesen
  Serial.println("Gib das aktuelle Jahr ein:");
  while (Serial.available() == 0) {}
  int currentYear = Serial.parseInt();

  // Geburtsjahr einlesen
  Serial.println("Gib dein Geburtsjahr ein:");
  while (Serial.available() == 0) {}
  int birthYear = Serial.parseInt();

  // Geburtsmonat einlesen
  Serial.println("Gib deinen Geburtsmonat ein (1-12):");
  while (Serial.available() == 0) {}
  int birthMonth = Serial.parseInt();

  // Geburtstag einlesen
  Serial.println("Gib deinen Geburtstag ein (1-31):");
  while (Serial.available() == 0) {}
  int birthDay = Serial.parseInt();

  // Aktuellen Monat und Tag einlesen
  Serial.println("Gib den aktuellen Monat ein (1-12):");
  while (Serial.available() == 0) {}
  int currentMonth = Serial.parseInt();

  Serial.println("Gib den aktuellen Tag ein (1-31):");
  while (Serial.available() == 0) {}
  int currentDay = Serial.parseInt();

  // Alter berechnen
  int ageYears = currentYear - birthYear;
  int ageMonths = currentMonth - birthMonth;
  int ageDays = currentDay - birthDay;

  
  if (ageDays < 0) {
    ageMonths--;
    ageDays += 30; // Annahme: 30 Tage pro Monat
  }

  if (ageMonths < 0) {
    ageYears--;
    ageMonths += 12;
  }

  // Alter ausgeben
  Serial.print("Dein Alter ist: ");
  Serial.print(ageYears);
  Serial.print(" Jahre, ");
  Serial.print(ageMonths);
  Serial.print(" Monate, und ");
  Serial.print(ageDays);
  Serial.println(" Tage.");
}

void loop() {
  
}