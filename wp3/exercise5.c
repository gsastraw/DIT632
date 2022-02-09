#include <Keypad.h>

const byte ROWS = 4;
const byte COLUMNS = 4;

char keys[ROWS][COLUMNS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rows[ROWS] = { 11, 10, 9, 8 };
byte columns[COLUMNS] = { 7, 6, 5, 4 };

Keypad keypad = Keypad(makeKeymap(keys), rows, columns, ROWS, COLUMNS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  key ? Serial.println(key) : NULL;
}
