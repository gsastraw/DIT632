// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31 (2022)
// Work package 4
// Exercise 1
// Submission code: h2mfv51V (provided by your TA-s)

#include <Adafruit_NeoPixel.h> // header for the led ring functionality

#define NUM_PIN 10
#define LED_COUNT 16
#define DELAY 100
#define RED_LED 5

//instantiation of the neo pixel
Adafruit_NeoPixel neo_pixel = Adafruit_NeoPixel(LED_COUNT, NUM_PIN, NEO_GRB + NEO_KHZ800);

int temp;

/**
 * @brief this function serves as a mathematical computation to convert the sensor reading into 
 *        a temperature. Firstly, there is a formula that converts the sensor reading into a voltage,
 */
void measure_temperature() // function to check the temperature
{
  int temperature = analogRead(A0);           //reads temp from AO
  float voltage = temperature * (5.0 / 1024); //calculation for voltage
  temp = (voltage - 0.5) * 100;               //calculation for temperature
}

/**
 * @brief setup function that initializes pins and the hardwares connected to them
 */
void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(A0, INPUT);
  neo_pixel.begin();
  Serial.begin(9600);
  neo_pixel.setBrightness(120);
}

/**
 * @brief loop function that takes in a delay where the temperature is measured every 100ms and the colors
 *        are set depending on the if the conditionals are fulfilled. The temperature is read and printed onto
 *        serial for proper measurement. 
 */
void loop()
{
  measure_temperature(); // call function to check the temperature
  set_rgb();             // call function to set the colors
  Serial.println(temp);
  delay(DELAY); // delay (100 arbitrarily chosen)
}

//ranges for intervals
int interval[] = {-30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};

/**
 * @brief Set the Colors object on the neopixel
 * 
 */
void set_rgb() // function to set the colors on the LED ring
{
  uint16_t i; // unsigned int of 16 bits
  //loop that iterates through every light
  for (i = 0; i < 16; i++)
  {
    //if temperature surpasses range interval
    if (temp > interval[i])
    {
      //a light on the neopixel will come alight for every interval surpassed in the predefined ranges,
      neo_pixel.setPixelColor(i, get_rgb((i * 16) & 255)); //this is a function that is provided in the Adafruit_Neopixel library where we pass in count times number of lights
      neo_pixel.show();                                    //another function within the Adafruit_Neopixel Library to show the light
      //once the cursor has reached the 16th element, the standard red LED must come alight
      if (i == 15)
      {
        //red led turns on
        digitalWrite(RED_LED, HIGH);
      }
      else if (i < 16)
      {
        //red lef turns off
        digitalWrite(RED_LED, LOW);
      }
      else
      { //conditional statement to turn off the neo pixel if the conditionals are not fulfilled
        neo_pixel.setPixelColor(i, neo_pixel.Color(0, 0, 0));
      }
    }
  }
}

/**
 * @brief Get the Color object; gets rainbow colors for the neo pixel
 *        code taken from https://codebender.cc/sketch:80438#Neopixel%20Rainbow.ino
 * 
 * @param color 
 * @return uint32_t 
 */
uint32_t get_rgb(byte color)
{
  // Input a value 0 to 255 to get a color value.
  // The colours are a transition r - g - b - back to r.
  if (color < 85) // if the value is less than 85
  {
    //red is upped, green comes down, blue is off
    return neo_pixel.Color(color * 3, 255 - color * 3, 0);
  }
  else if (color < 170) // if less than 170
  {
    color -= 85; //85 deducted from sum total
    //red is down, green is off, blue is upped
    return neo_pixel.Color(255 - color * 3, 0, color * 3);
  }
  else //for all values above 170
  {
    color -= 170; //170 is deducted from the sum total
    //red is off, green is upped, blue comes down
    return neo_pixel.Color(0, color * 3, 255 - color * 3);
  }
}