int operation;
int licht = 0; // 0 = aus, 1 = an

void  setup() {
    Serial.begin(9600);
}

void lichtschalter() {
    Serial.println("Licht einschalten (1) oder ausschalten (0)?");
    while (Serial.available() == 0) {}
    int an_aus = Serial.parseInt();

    if (an_aus == 1) {
        if (licht == 1) {
            Serial.println("Licht ist bereits an.");
            delay(1000); 
        } else {
            licht = 1;
            Serial.println("Licht ist an.");
            delay(1000);
        }
    } else if (an_aus == 0) {
        if (licht == 0) {
            Serial.println("Licht ist bereits aus.");
            delay(1000);
        } else {
            licht = 0;
            Serial.println("Licht ist aus.");
            delay(1000);
        }
    } else {
        Serial.println("Ungueltige Eingabe. Bitte 1 oder 0 eingeben.");
    }
}

void anzahlNegativer(int zahlen[], int size) {
    int neg = 0;
    for (int i = 0; i < size; i++) {
        if (zahlen[i] < 0) {
            neg++;
        }
    }
    Serial.println("Du hast " + String(neg) + " negative Zahlen eingegeben.");
    delay(1000);
}


void even(int zahl) {
    int erg = zahl % 2;
    if (erg == 0) {
        Serial.println("Die Zahl ist gerade.");
        delay(1000);
    } else {
        Serial.println("Die Zahl ist ungerade.");
        delay(1000);
    }
}

void loop() {
    Serial.println("Welche Operation soll gemacht werden?");
    Serial.println("1. Gerade oder ungerade Zahl pruefen");
    Serial.println("2. Anzahl der negativen Zahlen in einer Liste pruefen");
    Serial.println("3. Lichtschalter");
    while (Serial.available() == 0) {}
    operation = Serial.parseInt();

    if (operation == 1) {
        int number;
        Serial.println("Bitte eine Zahl eingeben:");
        while (Serial.available() == 0) {}
        number = Serial.parseInt();
        even(number);
    } else if (operation == 2) {
        Serial.println("Wie viele Zahlen willst du eingeben?");
        while (Serial.available() == 0) {}
        int size = Serial.parseInt();
        int zahlen[size];

        Serial.println("Bitte die Zahlen nacheinander eingeben:");
        for (int i = 0; i < size; i++) {
            while (Serial.available() == 0) {}
            zahlen[i] = Serial.parseInt();
        }

        anzahlNegativer(zahlen, size);
    } else if (operation == 3) {
        lichtschalter();
    } else {
        Serial.println("Ungueltige Operation. Bitte 1, 2 oder 3 waehlen.");
    }
}
