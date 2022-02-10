// Define max # of rows + columns + standard baud rate (data transmission rate that arduino uses)
#define ROWS 4 
#define COLUMNS 4 
#define STANDARD_BAUD_RATE 9600 

// Define characters and layout of keypad that is hooked up to Arduino
char keys[ROWS][COLUMNS] = { 
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// Define pin #s for rows of keypad
int rows[ROWS] = { 11, 10, 9, 8 };
// Define pin #s for columns of keypad
int columns[COLUMNS] = { 7, 6, 5, 4 };

void setup() {
  // Instantiate all pins of keypad by looping through # of rows/columns (interchangeable because there are 4 rows and columns)
  // Set columns to input value (PORT D) and rows to output value (PORT B)
  for (int i = 0; i < ROWS; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(columns[i], INPUT);
  }
  // Establish serial communication with standard baud rate (9600)
  Serial.begin(STANDARD_BAUD_RATE);
}

void loop() {
  char input = isKeyPressed(); // store input in variable
  if (input != 0) { // if input does exist...
    Serial.println((char) input); // print to serial
    delay(1000); // delay program by 1sec
  }
}

// method that reads whether or not a key is pressed
char isKeyPressed() {
  char input; // store input in variable
  for (int i = 0; i < ROWS; i++) { // loop through all rows
    digitalWrite(rows[i], LOW); // set all rows to low sequentially
    for (int j = 0; j < COLUMNS; j++) { // loop through all columns
      if (digitalRead(columns[j]) == LOW) { // if a column is also set to low, then that means that button at that index is pressed
        input = keys[i][j]; // store value of input 
      }
    }
    digitalWrite(rows[i], HIGH); // set all rows to high after value has been stored
  }
  return input; // return input
}
