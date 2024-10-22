#include <math.h>

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }
  if (num <= 3) {
    return true;
  }
  if (num % 2 == 0 || num % 3 == 0) {
    return false;
  }

  int limit = 1;
  while (limit * limit <= num) {
    limit++;
  }
  limit--;

  // Check for factors from 5 to sqrt(num) with step of 6
  for (int i = 5; i <= limit; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number to see if it's a prime:");
}

void loop() {
  if (Serial.available() > 0) {
    int i = Serial.parseInt();
    if (Serial.read() == '\n') {
      Serial.print(i);
      if (isPrime(i)) {
        Serial.println(" is a prime number.");
      } else {
        Serial.println(" is not a prime number.");
      }
    }
  }
}
