#include <Adafruit_GFX.h>     // Erforderlich für LED Matrix
#include <Max72xxPanel.h>     // Bibliothek für LED Matrix

// Pins für die LED Matrix
const int pinCS = 10;         // Pin für CS (Chip-Select)

// Definiere die Größe der LED Matrix
const int numberOfHorizontalDisplays = 1;
const int numberOfVerticalDisplays = 1;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

// Stundenplan-Daten als Arrays für jeden Tag
const char* montag[] = {"Englisch", "Englisch", "Chemie", "Chemie", "Mathematik", "Biologie", "Physik", "Technologien und Technisches Zeichnen"};
const char* dienstag[] = {"Deutsch/Geschichte", "Religion", "Recht und Wirtschaft", "Angewandte Technologien", "Angewandte Technologien", "Italienisch"};
const char* mittwoch[] = {"Mathematik", "Mathematik", "Chemie", "Sport", "Deutsch/Geschichte", "Deutsch/Geschichte", "Englisch", "Italienisch"};
const char* donnerstag[] = {"Physik", "Physik", "Technologien und Technisches Zeichnen", "Recht und Wirtschaft", "Biologie", "Deutsch/Geschichte"};
const char* freitag[] = {"Deutsch/Geschichte", "Deutsch/Geschichte", "Italienisch", "Italienisch", "Sport", "Mathematik"};

void setup() {
  Serial.begin(9600);             // Serielle Kommunikation starten
  
  // Initialisiere die LED Matrix
  matrix.setIntensity(5);         // Setze die Helligkeit (0 ist dunkel, 15 ist hell)
  matrix.fillScreen(LOW);         // Bildschirm löschen
  matrix.write();                 // Anzeige aktualisieren
}

void loop() {
  if (Serial.available() > 0) {
    int tag = Serial.parseInt();   // Eingabe des Wochentages (1 für Montag, 2 für Dienstag, etc.)
    int stunde = Serial.parseInt(); // Eingabe der Stunde (1 für die erste Stunde, 2 für die zweite Stunde, etc.)

    const char* fach = "";

    // Zeige das Fach basierend auf dem Tag und der Stunde an
    switch (tag) {
      case 1:
        fach = montag[stunde - 1];
        break;
      case 2:
        fach = dienstag[stunde - 1];
        break;
      case 3:
        fach = mittwoch[stunde - 1];
        break;
      case 4:
        fach = donnerstag[stunde - 1];
        break;
      case 5:
        fach = freitag[stunde - 1];
        break;
      default:
        Serial.println("Ungültiger Tag");
        return;
    }

    // Ausgabe des ausgewählten Faches
    Serial.print("Gewähltes Fach: ");
    Serial.println(fach);
    
    // Zeige die gewählte Stunde auf der LED Matrix an
    zeigeStundeAufMatrix(stunde);
  }
}

// Funktion, um die gewählte Stunde auf der LED Matrix anzuzeigen
void zeigeStundeAufMatrix(int stunde) {
  matrix.fillScreen(LOW);          // Bildschirm löschen

  // LEDs entsprechend der gewählten Stunde einschalten
  if (stunde >= 1 && stunde <= 8) {
    for (int i = 0; i < 8; i++) {
      matrix.drawPixel(stunde - 1, i, HIGH);  // LEDs in der Spalte für die gewählte Stunde einschalten
    }
  }

  matrix.write();                  // Matrix aktualisieren
}
