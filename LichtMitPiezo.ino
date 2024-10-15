const int PHOTO_RESISTOR_PIN = A0;
const int SPEAKER_PIN = 2;

int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  sensorValue = analogRead(PHOTO_RESISTOR_PIN);
  Serial.println(sensorValue);
  tone(SPEAKER_PIN, sensorValue + 100);
  delay(500);
}
