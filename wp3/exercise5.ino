// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31
// Work package 3
// Exercise 2
// Submission code: ieBXfeFq

#include <Keypad.h>
// Instantiate # of rows & columns
const byte ROWS = 4;
const byte COLUMNS = 4;

// Instantiate layout of keypad
char keys[ROWS][COLUMNS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

// Instantiate pin #s of rows and columns
byte rows[ROWS] = {11, 10, 9, 8};
byte columns[COLUMNS] = {7, 6, 5, 4};

/* Instantiate keypad object via Keypad.h library and make a keymap containing 4 rows, 4 columns and the keys
   specified
*/
Keypad keypad = Keypad(makeKeymap(keys), rows, columns, ROWS, COLUMNS);

void setup()
{
  // Begin serial communication with baud rate of 9600 (default Arduino value)
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();       // get key pressed from keypad
  key ? Serial.println(key) : NULL; // if key exists, print out to serial, else nothing at all
}
