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


  int sqrtNum = 1;
  while (sqrtNum * sqrtNum <= num) {
    sqrtNum++;
  }
  sqrtNum--;


  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Enter a number to see if its a prime:");
}

void loop() {

    if (Serial.available() > 0) {
        int i = Serial.parseInt();
        Serial.print(i);
        if (isPrime(i)) {
        Serial.println(" is prime.");
        } else {
        Serial.println(" is not prime.");
        }
    }
    delay(300);
}
