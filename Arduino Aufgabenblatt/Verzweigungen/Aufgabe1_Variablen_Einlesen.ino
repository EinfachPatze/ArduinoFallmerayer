void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
}

void loop() {
  // Schritt 1: Lies eine Ganzzahl, eine Kommazahl und einen Namen ein
  Serial.println("Gib eine Ganzzahl ein:");
  while (Serial.available() == 0) {} // Warten auf Eingabe
  int num = Serial.parseInt();
  Serial.parseString();

  Serial.println("Gib eine Kommazahl ein:");
  while (Serial.available() == 0) {}
  float decimal = Serial.parseFloat();
  Serial.parseString();

  Serial.println("Gib deinen Namen ein:");
  while (Serial.available() == 0) {}
  String name = Serial.readString();

  // Schritt 2: Gib die ursprünglichen Werte aus
  Serial.println(num);
  Serial.println(decimal);
  Serial.println(name);

  // Schritt 3: Werte verändern und erneut ausgeben
  Serial.println(num * 2);    // Verdopple die Ganzzahl
  Serial.println(decimal / 2); // Halbiere die Kommazahl
  Serial.println("Hallo " + name); // Begrüße den Benutzer

  delay(10000); // Kurze Pause, damit der Benutzer die Ausgabe sieht
}
