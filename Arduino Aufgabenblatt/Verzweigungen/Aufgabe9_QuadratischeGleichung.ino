#include <math.h>  // Für sqrt()

double a, b, c;  // Koeffizienten
double discriminant, root1, root2;  // Diskriminante und Wurzeln

void setup() {
  // Serielle Kommunikation starten
  Serial.begin(9600);
  
  // Anweisungen zur Eingabe
  Serial.println("Geben Sie die Koeffizienten a, b und c für die quadratische Gleichung ax^2 + bx + c = 0 ein:");
  
  // Warten auf die Eingabe von a, b und c über den seriellen Monitor
  getInput();
  
  // Berechne die Diskriminante
  discriminant = b * b - 4 * a * c;
  
  // Überprüfe die Anzahl der Lösungen anhand der Diskriminante
  if (discriminant > 0) {
    // Zwei reelle und unterschiedliche Lösungen
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);
    Serial.println("Die Gleichung hat zwei unterschiedliche reelle Lösungen:");
    Serial.print("x1 = ");
    Serial.println(root1);
    Serial.print("x2 = ");
    Serial.println(root2);
  } else if (discriminant == 0) {
    // Eine reelle Lösung
    root1 = -b / (2 * a);
    Serial.println("Die Gleichung hat eine doppelte reelle Lösung:");
    Serial.print("x1 = x2 = ");
    Serial.println(root1);
  } else {
    // Keine reellen Lösungen, sondern zwei komplexe Lösungen
    double realPart = -b / (2 * a);
    double imaginaryPart = sqrt(-discriminant) / (2 * a);
    Serial.println("Die Gleichung hat zwei komplexe Lösungen:");
    Serial.print("x1 = ");
    Serial.print(realPart);
    Serial.print(" + ");
    Serial.print(imaginaryPart);
    Serial.println("i");
    Serial.print("x2 = ");
    Serial.print(realPart);
    Serial.print(" - ");
    Serial.print(imaginaryPart);
    Serial.println("i");
  }
}

void loop() {
  // Der Code im Loop ist leer, weil wir nur einmal die Eingabe und Berechnung brauchen.
}

void getInput() {
  while (Serial.available() == 0) {
    // Warten auf Eingabe
  }
  a = Serial.parseFloat();
  while (Serial.available() == 0) {
    // Warten auf Eingabe
  }
  b = Serial.parseFloat();
  while (Serial.available() == 0) {
    // Warten auf Eingabe
  }
  c = Serial.parseFloat();
}
