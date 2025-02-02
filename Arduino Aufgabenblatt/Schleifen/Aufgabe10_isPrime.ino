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

  // Check for factors from 5 to sqrt(num) with step of 6
  for (int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

int n_te_primzahl(int n) {
  int count = 0;
  int i = 2;
  while (true) {
    if (isPrime(i)) {
      count++;
      if (count == n) {
        return i;
      }
    }
    i++;
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number to see if it's a prime:");
}

void loop() {
  if (Serial.available() > 0) {
    int i = Serial.parseInt(); 
    Serial.print(i);
    if (isPrime(i)) {
      Serial.println(" is a prime number.");
    } else {
      Serial.println(" is not a prime number.");
    }
  }
}
