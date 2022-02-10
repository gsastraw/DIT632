#define ROWS 4
#define COLUMNS 4
#define STANDARD_BAUD_RATE 9600

char keys[ROWS][COLUMNS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

int rows[ROWS] = { 11, 10, 9, 8 };
int columns[COLUMNS] = { 7, 6, 5, 4 };

void setup() {
  for (int i = 0; i < ROWS; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(columns[i], INPUT);
  }
  Serial.begin(STANDARD_BAUD_RATE);
}

void loop() {
  char input;
  for (int i = 0; i < ROWS; i++) {
    digitalWrite(rows[i], LOW);
    for (int j = 0; j < COLUMNS; j++) {
      if (digitalRead(columns[j]) == LOW) {
        input = keys[i][j];
      }
    }
    digitalWrite(rows[i], HIGH);
  }
  
  if (input != 0) {
    Serial.println((char) input);
    delay(500);
  }
}
