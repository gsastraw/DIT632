// C++ code
//

// Defines
#define PIN13 13
#define PIN12 12

void setup()
{
  pinMode(PIN13, OUTPUT);
  pinMode(PIN12, OUTPUT);
}

void loop()
{
  digitalWrite(PIN13, HIGH);
  digitalWrite(PIN12, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(PIN13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}