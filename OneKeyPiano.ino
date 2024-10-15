const int speakerPin = 8;
const int buttonPin = 2;
int tones[] = {
        392.00,  
        523.25,  
        659.25,  
        784.00,  
        698.46,  
        587.33,  
        440.00   
    };
int toneIndex = 0;



bool isPlaying = false;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    if (!isPlaying) {
      isPlaying = true;
      playTone();
    }
  } else {
    isPlaying = false;
    noTone(speakerPin);
  }
}

void playTone() {
  tone(speakerPin, tones[toneIndex]);
  delay(500);
  toneIndex = (toneIndex + 1) % 7;
  noTone(speakerPin);
}
