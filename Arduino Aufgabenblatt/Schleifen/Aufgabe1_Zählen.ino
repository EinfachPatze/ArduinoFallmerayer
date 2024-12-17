void setup() {
  Serial.begin(9600);
  Serial.println("Geben Sie eine Zahl ein:");
}

void loop() {
  if (Serial.available() > 0) {
    int zahl = Serial.parseInt();
    if (zahl == 0) {
      Serial.println("Das war keine gültige Zahl. Bitte geben Sie eine Zahl ein:");
      return;
    }
    Serial.print("Zähle bis ");
    Serial.println(zahl);
    
    String output = "";
    for (int i = 1; i <= zahl; i++) {
      output += String(i) + "\n";
    }
    Serial.print(output);
    delay(1000);

    output = "";
    int i = 1;
    do {
      output += String(i) + "\n";
      i++;
    } while(i <= zahl);
    
    Serial.print(output);
    while(i <= zahl) {
      output += String(i) + "\n";
      i++;
  }
    Serial.print(output);
    
    Serial.println("Fertig!");
    Serial.println("Geben Sie eine weitere Zahl ein:");
  }
}
