// Koordinaten des Rechtecks
const int x1 = 2;  // linke untere Ecke x
const int y1 = 2;  // linke untere Ecke y
const int x2 = 6;  // rechte obere Ecke x
const int y2 = 6;  // rechte obere Ecke y

void setup() {
  Serial.begin(9600);
  Serial.println("Geben Sie die Koordinaten des Punktes ein (x, y):");
}

void loop() {
  // Überprüfen, ob Daten verfügbar sind
  if (Serial.available() > 0) {
    // Eingabe lesen
    int x = Serial.parseInt();
    int y = Serial.parseInt();

    // Überprüfen, ob der Punkt im Rechteck liegt
    if (punktImRechteck(x, y)) {
      Serial.println("Der Punkt liegt im Rechteck!");
    } else {
      Serial.println("Der Punkt liegt nicht im Rechteck.");
      informierePosition(x, y);
    }

    delay(2000);  // Kurze Pause, um das Ergebnis zu lesen
    Serial.println("Geben Sie die nächsten Koordinaten des Punktes ein (x, y):");
  }
}

// Funktion zur Überprüfung, ob der Punkt im Rechteck liegt
bool punktImRechteck(int x, int y) {
  return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}

// Funktion zur Bestimmung der relativen Position
void informierePosition(int x, int y) {
  if (x < x1) {
    Serial.print("Der Punkt ist links ");
  } else if (x > x2) {
    Serial.print("Der Punkt ist rechts ");
  }
  
  if (y < y1) {
    Serial.print("unten.");
  } else if (y > y2) {
    Serial.print("oben.");
  } else {
    Serial.print("im vertikalen Bereich.");
  }
  Serial.println();
}
