// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 123 __ (2022)
// Work package 3
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

#define TEMPERATURE_SENSOR A1 //the temperature sensore connects to A1

int light_intensity; //the range of light intensity from 0-100
double temperature;  //the value of temperature measured in celsius

/**
 * @brief this function serves as a mathematical computation to convert the sensor reading into 
 *        a temperature. Firstly, there is a formula that converts the sensor reading into a voltage,
 *        which is then used in a formula used to get a temperature reading.
 * @param sensorReading 
 * @return ** double 
 */
double convertTemperature(int sensorReading)
{
  double voltage = (sensorReading * 5.0) / 1023.0; //calculation for voltage per unit
  temperature = (voltage - 0.5) * 100;             //calculation for temperature
  return temperature;
}

/**
 * @brief This is the setup function. This is where the hardware is instantiated into the code.
 * 
 * @return ** void 
 */
void setup()
{
  pinMode(TEMPERATURE_SENSOR, INPUT); //these are the hardware used on the Arduino circuitry
  Serial.begin(9600);
}

/**
 * @brief This is a loop function that increments every 2 seconds. For every 2 seconds, the temperature
 *        is read and measured via the temperature sensor. The reading is then printed onto serial.
 * 
 * @return ** void 
 */
void loop()
{
  temperature = convertTemperature(analogRead(TEMPERATURE_SENSOR)); //the value of temperature is assigned from the input passed as a params to convertTemperature

  Serial.print("TEMPERATURE LEVEL IS "); //String is printed onto serial to serve as information
  Serial.println(temperature);           //value of temperature is printed onto serial
  delay(2000);
  // Serial.println(value);
}