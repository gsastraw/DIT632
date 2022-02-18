// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31 (2022)
// Work package 4
// Exercise 2
// Submission code: h2mfv51V (provided by your TA-s)

// Includes
#include <Servo.h>

unsigned long currentTime = 0; // Time elapsed since runtime
unsigned long interval = 1000; // Interval we want to set in loop

// Instantiate servo
Servo servo;

// Setup 
// Inspired by https://www.instructables.com/Arduino-Timer-Interrupts/
// Also inspired by http://www.8bit-era.cz/arduino-timer-interrupts-calculator.html for calculations
void setup()
{
  servo.attach(9); // Power the servo on pin 9
  cli(); // Stop interrupts occurring atm so that we can set registers and internals accordingly
  TCCR1A = 0; // Set the entire TCCR1A register to 0
  TCCR1B = 0; // Set the entire TCCR1B register to 0 
  TCNT1  = 0; // TCNT is the timer/counter register which counts system clock ticks (set to 0 as well)
  // set compare match register for 1 Hz increments
  OCR1A = 16000000 / (256 * 1) - 1; // = compare match register = [ 16,000,000Hz/ (prescaler * desired interrupt frequency) ] - 1
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12, CS11 and CS10 bits for 256 prescaler
  TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10);
  // Enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // allow interrupts
  Serial.begin(9600); // Establish serial communication
}

// Loops and continuously calls timer function
void loop()
{
  timer();
}

// Function that continuously prints out the time every 1000ms
void timer() {
  // If the current time (millis()) has elapsed 1000ms, add this timed value to the interval
  if (millis() >= currentTime + interval)
  {
    // Add to interval
    currentTime += interval;
    // Print out current time / 1000 because we're handling ms
    Serial.println(currentTime / 1000);
  }
}