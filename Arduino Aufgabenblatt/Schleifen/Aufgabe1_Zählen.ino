void setup() {
  Serial.begin(9600);
  Serial.println("Geben Sie eine Zahl ein:");
}

void loop() {
  if (Serial.available() > 0) {
    int zahl = Serial.parseInt();
    Serial.print("Zähle bis ");
    Serial.println(zahl);
    
    String output = "";
    for (int i = 1; i <= zahl; i++) {
      output += String(i) + "\n";
    }
    
    Serial.print(output);
    Serial.println("Fertig!");
    Serial.println("Geben Sie eine weitere Zahl ein:");
  }
}
