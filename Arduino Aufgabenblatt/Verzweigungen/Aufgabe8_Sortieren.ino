// Pin-Zuweisungen für die Segmente der 7-Segment-Anzeige
const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
const int segDP = 9;  // Dezimalpunkt

// Pin-Zuweisungen für die Stellensteuerung (D1, D2, D3, D4)
const int digit1 = 10;
const int digit2 = 11;
const int digit3 = 12;
const int digit4 = 13;

// Ziffern-Muster für 0-9 auf der 7-Segment-Anzeige
const byte numbers[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void setup() {
  Serial.begin(9600);  // Serielle Kommunikation starten
  
  // Definiere alle Segment-Pins als Ausgang
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);
  
  // Definiere die Pins für die Stellen (Digits) als Ausgang
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
}

void loop() {
  // Lese die Eingaben für die drei Zahlen
  Serial.println("Geben Sie drei Zahlen (0-99) ein:");
  
  while (Serial.available() == 0);  // Warten auf Eingabe
  int num1 = Serial.parseInt();
  
  while (Serial.available() == 0);  // Warten auf Eingabe
  int num2 = Serial.parseInt();
  
  while (Serial.available() == 0);  // Warten auf Eingabe
  int num3 = Serial.parseInt();
  
  // Sortiere die Zahlen
  int sorted[3];
  sortNumbers(num1, num2, num3, sorted);
  
  // Zeige die ersten zwei sortierten Zahlen auf der 7-Segment-Anzeige
  displayNumber(sorted[0], sorted[1]);

  delay(5000);  // 5 Sekunden warten
}

// Funktion zur Sortierung der Zahlen
void sortNumbers(int a, int b, int c, int sorted[]) {
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
  
  sorted[0] = a;
  sorted[1] = b;
  sorted[2] = c;
}

// Funktion, um zwei Zahlen zu tauschen
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

// Funktion zur Anzeige der sortierten Zahlen auf der 7-Segment-Anzeige
void displayNumber(int num1, int num2) {
  // Zeige die erste Zahl auf der ersten Ziffer
  displayDigit(num1 / 10, digit1);  // Zehnerstelle von num1
  displayDigit(num1 % 10, digit2);  // Einerstelle von num1

  // Zeige die zweite Zahl auf der dritten und vierten Ziffer
  displayDigit(num2 / 10, digit3);  // Zehnerstelle von num2
  displayDigit(num2 % 10, digit4);  // Einerstelle von num2
}

// Funktion zur Anzeige einer Ziffer auf einer bestimmten Stelle
void displayDigit(int num, int digitPin) {
  digitalWrite(digit1, LOW);   // Alle Ziffern deaktivieren
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);

  // Schalte das entsprechende Segment-Muster für die Ziffer ein
  digitalWrite(segA, numbers[num][0]);
  digitalWrite(segB, numbers[num][1]);
  digitalWrite(segC, numbers[num][2]);
  digitalWrite(segD, numbers[num][3]);
  digitalWrite(segE, numbers[num][4]);
  digitalWrite(segF, numbers[num][5]);
  digitalWrite(segG, numbers[num][6]);

  // Schalte die gewünschte Ziffer ein
  digitalWrite(digitPin, HIGH);

  delay(5);  // Kurze Wartezeit, um das Flackern zu minimieren
}
