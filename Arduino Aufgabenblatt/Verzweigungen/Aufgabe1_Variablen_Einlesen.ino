void setup() {
  Serial.begin(9600); // Serielle Kommunikation starten
}

void loop() {
  //Daten einlesen
  Serial.println("Gib eine Ganzzahl ein:");
  while (Serial.available() == 0) {} // Warten auf Eingabe
  int num = Serial.parseInt();


  Serial.println("Gib eine Kommazahl ein:");
  while (Serial.available() == 0) {}
  float decimal = Serial.parseFloat();


  Serial.println("Gib deinen Namen ein:");
  while (Serial.available() == 0) {}
  String name = Serial.readString();

  // ursprünglichen Werte ausgeben
  Serial.println(num);
  Serial.println(decimal);
  Serial.println(name);

  //Werte verändern und neu ausgeben
  Serial.println(num * 2);    // Verdopple die Ganzzahl
  Serial.println(decimal / 2); // Halbiere die Kommazahl
  Serial.println("Hallo " + name); // Begrüße den Benutzer

  delay(10000); // Kurze Pause
}
