void setup() {
  Serial.begin(9600);
  Serial.println("Geben Sie die Anzahl der Glieder für jede Folge ein:");

  int anzahlFolgen;
  while (true) {
    if (Serial.available() > 0) {
      anzahlFolgen = Serial.parseInt();
      generiereFolgen(anzahlFolgen);
      break;
    }
  }
}

void loop() {
}

void generiereFolgen(int anzahl) {
  Serial.println("Folge 1: -5, -2, 1, 4, 7, 10, ...");
  for (int i = 0; i < anzahl; i++) {
    Serial.print(-5 + i * 3);
    Serial.print(", ");
  }
  Serial.println();

  Serial.println("Folge 2: 1, 2, 4, 8, 16, ...");
  for (int i = 0; i < anzahl; i++) {
    Serial.print(pow(2, i));
    Serial.print(", ");
  }
  Serial.println();

  Serial.println("Folge 3: 3, 4, 6, 10, 18, ...");
  int previous = 3;
  Serial.print(previous);
  for (int i = 1; i < anzahl; i++) {
    int next;
    if (i == 1) {
      next = 4;
    } else if (i == 2) {
      next = 6;
    } else {
      next = previous + (previous + 2);
    }
    Serial.print(", ");
    Serial.print(next);
    previous = next;
  }
  Serial.println();

  Serial.println("Folge 4: 1, 2, 4, 7, 11, ...");
  int nextValue = 1;
  Serial.print(nextValue);
  for (int i = 1; i < anzahl; i++) {
    nextValue += (i + 1);
    Serial.print(", ");
    Serial.print(nextValue);
  }
  Serial.println();
}
