#include <math.h>

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0) {
    return false;
  }

  int limit = (int)sqrt(num);
  
  // Check for factors from 3 to sqrt(num)
  for (int i = 3; i <= limit; i += 2) {
    if (num % i == 0) {
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
        Serial.println(" is prime.");
      } else {
        Serial.println(" is not prime.");
      }
    } else {
      Serial.println("Invalid input. Please enter an integer.");
    }
  }
  delay(300);
}
