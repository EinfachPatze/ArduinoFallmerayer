// Pins for LEDs
const int LED1 = 2;  // Intervall 1 (0 bis 6)
const int LED2 = 3;  // Intervall 2 (6 bis 12)
const int LED3 = 4;  // Intervall 3 (-∞ bis -1)
const int LED4 = 5;  // Intervall 4 (0 bis ∞)
const int LED5 = 6;  // Intervall 5 (-∞ bis 4)

void setup() {
  // Set LED pins as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  Serial.begin(9600);  // For input via the Serial Monitor
}

void loop() {
  if (Serial.available() > 0) {
    int x = Serial.parseInt();  // Read the number from Serial Monitor

    // Reset all LEDs
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);

    // Intervall 1: [0, 6]
    if (x >= 0 && x <= 6) {
      digitalWrite(LED1, HIGH);  // LED1 on
    }

    // Intervall 2: [6, 12]
    if (x > 6 && x <= 12) {
      digitalWrite(LED2, HIGH);  // LED2 on
    }

    // Intervall 3: (-∞, -1]
    if (x < 0) {
      digitalWrite(LED3, HIGH);  // LED3 on
    }

    // Intervall 4: [0, ∞)
    if (x >= 0) {
      digitalWrite(LED4, HIGH);  // LED4 on
    }

    // Intervall 5: (-∞, 4]
    if (x <= 4) {
      digitalWrite(LED5, HIGH);  // LED5 on
    }
  }
}
