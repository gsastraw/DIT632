// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31
// Work package 6
// Exercise 2
// Submission code:

// Include arduino standard library
#include <Arduino.h>

// DEFINES that correspond to pins and/or LEDs connected to ports on Arduino
#define SPEAKER_PIN 9
#define TRIG_PIN 7
#define ECHO_PIN 6
#define LED_ONE 5
#define LED_TWO 4
#define LED_THREE 3
#define LED_FOUR 2

#define STANDARD_BAUD_RATE 9600 // Define the standard baud rate for serial communication between arduino board and external device
#define MAX_DISTANCE 200 // Define a max distance of 200 for the ultrasonic sensor
#define MIN_DISTANCE 25 // Define a min distance of 25 for the ultrasonic sensor

long duration; //length of time for sound wave to travel back and forth 
long distance; //for distance

// Setup
void setup()
{
  pinMode(SPEAKER_PIN, OUTPUT); // instantiate piezo speaker pin to output noise
  pinMode(TRIG_PIN, OUTPUT); // instantiate trigger pin on ultrasonic sensor to emit (OUTPUT) high pitched frequency noise
  pinMode(ECHO_PIN, INPUT); // instantiate echo pin on ultrasonic sensor to record noise (INPUT) from trigger pin
  pinMode(LED_ONE, OUTPUT); // first LED from the left set to output
  pinMode(LED_TWO, OUTPUT); // second LED set to output
  pinMode(LED_THREE, OUTPUT); // third LED set to output
  pinMode(LED_FOUR, OUTPUT); // fourth LED set to output
  Serial.begin(STANDARD_BAUD_RATE); // Begin serial communication between Arduino board and another device
}

void loop()
{
  ultrasonic_sensor(); // call ultrasonic_sensor() method (see below)
  turnOnLedBasedOnDistance(); // call turnOnLedBasedOnDistance method (see below)
  turnOnSoundBasedOnDistance(); // call turnOnLedBasedOnDistance method (see below)
  Serial.println(distance); // print out distance between sensor and object in its path 
}

// Helper method that calculates the sound waves - takes in the pulse length
unsigned long sound_wave_calculation(unsigned long pulseLength)
{
  duration = pulseLength * 0.034 / 2; // pulseLength * speed of sound (0.034 == 340ms) divided by two 
  return duration / 29; // divided by 29 to convert to cm
}

// A method that handles behavior of the ultrasonic sensor when encountering an object
void ultrasonic_sensor()
{
  //clears the system and waits two milliseconds
  digitalWrite(TRIG_PIN, LOW);
  delay(2);

  // write to the trigger pin and set it to HIGH with a delay of 10ms in order to emit a high pitched sound
  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW); // turn off trigger pin afterwards 

  duration = pulseIn(ECHO_PIN, HIGH); // store length of pulse in duration variable
  distance *= sound_wave_calculation(duration); // call sound_wave_calculation method 

  // duration = duration * sound_wave_calculation()
  // basically becomes (PULSE LENGTH) * (0.034 / 2) / 29 for the complete formula
}

// Helper method that defines the behavior of LEDs given object distance
void turnOnLedBasedOnDistance()
{
  // if distance is less than 30..
  if (distance < 30)
  {
    digitalWrite(LED_ONE, HIGH); // print out HIGH to all lights which turns them on
    digitalWrite(LED_TWO, HIGH); // print out HIGH to all lights which turns them on
    digitalWrite(LED_THREE, HIGH); // print out HIGH to all lights which turns them on
    digitalWrite(LED_FOUR, HIGH); // print out HIGH to all lights which turns them on
  }
  // else if distance is greater than or equal to 30 and less than 80...
  else if (distance < 80 && distance >= 30)
  {
    digitalWrite(LED_ONE, HIGH); // print out HIGH to LED_ONE (defined at top) which turns it on
    digitalWrite(LED_TWO, HIGH); // print out HIGH to LED_TWO (defined at top) which turns it on
    digitalWrite(LED_THREE, HIGH); // print out HIGH to LED_THREE (defined at top) which turns it on
    digitalWrite(LED_FOUR, LOW); // prints out LOW to LED_FOUR (defined at top) which turns it off satisfying requirements in assignment doc
  }
  // else if distance is greater than or equal to 80 and less than 130
  else if (distance < 130 && distance >= 80)
  {
    digitalWrite(LED_ONE, HIGH); // print out HIGH to LED_ONE (defined at top) which turns it on
    digitalWrite(LED_TWO, HIGH); // print out HIGH to LED_TWO (defined at top) which turns it on
    digitalWrite(LED_THREE, LOW); // prints out LOW to LED_THREE (defined at top) which turns it off satisfying requirements in assignment doc
    digitalWrite(LED_FOUR, LOW); // prints out LOW to LED_FOUR (defined at top) which turns it off satisfying requirements in assignment doc
  }
  // greater than or equal to 130 and less than or equal to 200
  else if (distance <= MAX_DISTANCE && distance >= 130)
  {
    digitalWrite(LED_ONE, HIGH); // print out HIGH to LED_ONE (defined at top) which turns it on
    digitalWrite(LED_TWO, LOW); // print out LOW to LED_TWO (defined at top) which turns it off satisfying requirements in assignment doc 
    digitalWrite(LED_THREE, LOW); // prints out LOW to LED_THREE (defined at top) which turns it off satisfying requirements in assignment doc
    digitalWrite(LED_FOUR, LOW); // prints out LOW to LED_FOUR (defined at top) which turns it off satisfying requirements in assignment doc
  }
  else
  {
    digitalWrite(LED_ONE, LOW); // prints out LOW to LED_ONE (defined at top) which turns it off satisfying requirements in assignment doc
    digitalWrite(LED_TWO, LOW); // prints out LOW to LED_TWO (defined at top) which turns it off satisfying requirements in assignment doc
    digitalWrite(LED_THREE, LOW); // prints out LOW to LED_THREE (defined at top) which turns it off satisfying requirements in assignment doc
    digitalWrite(LED_FOUR, LOW); // prints out LOW to LED_FOUR (defined at top) which turns it off satisfying requirements in assignment doc
  }
}

// Helper method that defines the behavior of the piezo speaker given object distance
void turnOnSoundBasedOnDistance()
{
  // if the distance is less than the minimum distance of 25..
  if (distance < MIN_DISTANCE)
  {
    // set speaker tone to 5000hz
    tone(SPEAKER_PIN, 5000);
  }
  // if the distance is less than 80 and the distance is greater than or equal to 25
  else if (distance < 80 && distance >= MIN_DISTANCE)
  {
    // set speaker tone to 1500hz
    tone(SPEAKER_PIN, 1500);
  }
  // if the distance is less than 130 and the distance is greater than or equal to 80
  else if (distance < 130 && distance >= 80)
  {
    // set speaker tone to 750hz
    tone(SPEAKER_PIN, 750);
    // greater than or equal to 130 and less than or equal to 200
  }
  // if the distance is less than or equal to 200 and the distance is greater than or equal to 130
  else if (distance <= MAX_DISTANCE && distance >= 130)
  {
    // set speaker tone to 325hz
    tone(SPEAKER_PIN, 325);
  }
  // otherwise..
  else
  {
    // no tone whatsoever if the object does not satisfy the predefined distance conditions up top in the method body
    noTone(SPEAKER_PIN);
  }
}
