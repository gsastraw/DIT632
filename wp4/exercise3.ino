// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31
// Work package 3
// Exercise 2
// Submission code:

#include <Arduino.h>           // Arduino library
#include <Adafruit_NeoPixel.h> // NeoPixel library

#define neo_pin = 10    // the pin number of the neopixel strip
#define num_pixels = 16 // number of the leds

int delay_val = 100; // delay value
int temperature;     // temperature
int red = 15;        // rgb red value
int green = 25;      // rgb green value
int blue = 35;       // rgb blue value

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(num_pixels, neo_pin, NEO_GRB + NEO_KHZ800); // instantiation of neopixel

float range[] = {-30.0, -20.0, -10.0, 0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 110.0, 120.0};
// array of breakpoints for the temperature

/**
 * @brief this function serves as a mathematical computation to convert the sensor reading into 
 *        a temperature. Firstly, there is a formula that converts the sensor reading into a voltage,
 *        which is then used in a formula used to get a temperature reading.
 * 
 */
void measure_temperature() // function that measures temperature
{
  int temperature = analogRead(A0);           // reads temperature from from analog pin
  float voltage = temperature * (5.0 / 1024); // conversion analog to voltage
  temperature = (voltage - 0.5) * 100;        // conversion from voltage get temperature
}

void setColors() // function to set the colors on the LED ring
{
  uint16_t i;              // unsigned 16 bit integer
  for (i = 0; i < 16; i++) // for loop for range of LEDs on the ring
  {
    if (temperature > range[i]) // if the temperature is in the correct range
    {
      pixels.setPixelColor(i, getColor((i * 16) & 255)); // set the color to display on the LED ring
      pixels.show();                                     // re-renders the leds on the ring
      if (i == 15)
      {
        digitalWrite(3, HIGH);
      }
    }
    else // else if its in the wrong range
    {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // turns off the ring's lights (all rgb values 0)
    }
  }
}

uint32_t getColor(byte color) // function for getting rainbow colours, unsigned 32 bit integer
{
  /* function to get rainbow colours for the Neopixel ring by mattnupen on codebender. */
  if (color < 85) // if the value is less than 85
  {
    return pixels.Color(color * 3, 255 - color * 3, 0); // increase the red, decrease the green, and set blue to 0
  }
  else if (color < 170) // if the value is between 85 and 170
  {
    color -= 85;
    return pixels.Color(255 - color * 3, 0, color * 3); // decrease the red, set green to 0, and increase the blue
  }
  else // if the value is between 170 and 255
  {
    color -= 170;                                       // value is equal to the value minus 170
    return pixels.Color(0, color * 3, 255 - color * 3); // set red to 0, increase the green, and decrease the blue
  }
}

/**
 * @brief Sets up pin modes, neopixel begins, serial begins, and brightness is set
 * 
 */
void setup()
{
  // put your setup code here, to run once:
  pinMode(2, INPUT);         // set analogue pin 0 to input
  pixels.begin();            //to start the led ring
  Serial.begin(9600);        // initializes serial
  pixels.setBrightness(120); // half brightness
}

/**
 * @brief 
 * loop function that holds logic for the program
 */
void loop()
{
  measure_temperature(); // calls function to measure temperature
  setColors();           // calls function to set colors
  delay(delay_val);      // delay
}
