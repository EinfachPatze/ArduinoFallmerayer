int ergebnis = 0;

void setup()
{
    Serial.begin(9600);

    for (int i = 1; i <= 10; i++)
    {
        for (int l = 1; l <= 10; l++)
        {
            Serial.print(i);
            Serial.print(" * ");
            Serial.print(l);
            Serial.print(" = ");
            Serial.println(i * l);
        }
    }
}

void loop()
{
}
