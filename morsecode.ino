void setup() {                                   // dieser code wird am anfang einmal ausgeführt um bestimmte sachen einzustellen
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);                            //definiert den output auf pin Nr.7
}

void kurz() {                                    //eine Funktion die den ablauf für kurzes blinken definiert
  digitalWrite(7, HIGH);                         //schaltet das licht ein
  delay(200);                                    //Verzögerung von 200ms bis zum erneuten ausschalten der LED
  digitalWrite(7, LOW);                          //schaltet das licht wieder aus
  delay(1000);                                   // längere Verzögerung um das ende des kurzen/langen blinken zu symbolisieren
}

void lang() {                                    //eine Funktion die den ablauf für langes blinken definiert
  digitalWrite(7, HIGH);
  delay(600);
  digitalWrite(7, LOW);
  delay(1000);
}

void loop() {                                    // der code der hier drinsteht wird durchgehend wiederholt
  
  kurz();                                        //führt die Funktion für kurzes blinken aus
  kurz();
  kurz();
  delay(2000);                                   //Verzögerung zwischen den Buchstaben von 2000ms
  kurz();
  kurz();
  delay(2000);
  lang();                                        //führt die Funktion für kurzes blinken aus
  lang();
  delay(2000);
  lang();
  lang();
  lang();
  delay(2000);
  lang();
  kurz();
  delay(5000);                                  //Verzögerung am ende des Namens bis zum erneuten abspielen 
}
