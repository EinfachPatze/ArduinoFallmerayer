void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Enter the length of the rectangle:");
    float b = getInput();
    Serial.println("Enter the width of the rectangle:");
    float a = getInput();
    Serial.print("The area of the rectangle is: ");
    Serial.println(area(a, b));
    Serial.print("The perimeter of the rectangle is: ");
    Serial.println(umfang(a, b));
    
}

float area(float a, float b)
{
  return a * b;
}

float umfang(float a, float b)
{
  return 2 * a + 2 * b;
}

float getInput()
{
    while (Serial.available() == 0)
    {
    }
    float tmp =  Serial.parseFloat();
    return tmp;
    
}

