// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31
// Work package 3
// Exercise 2
// Submission code: ieBXfeFq

#define RED 13                //the red light is connected to 13
#define GREEN 12              //the green light is connected to 12
#define YELLOW 11             //the yellow light is connected to 11
#define PHOTORESISTOR A0      //the photoresistor connects to A0
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
    double voltage = sensorReading * 5.0; //calculation for voltage
    voltage /= 1024.0;                    //calculation for voltage per unit
    temperature = (voltage - 0.5) * 100;  //calculation for temperature
    return temperature;
}

/**
 * @brief a function to flash the green light. This function is called upon only when the temperature falls within the expected
 *        range given the specified luminosity.
 * @return ** void 
 */
void flash_green()
{
    digitalWrite(RED, LOW);    //turns red light off
    digitalWrite(GREEN, HIGH); //turns green light on
    digitalWrite(YELLOW, LOW); //turns yellow light on
}

/**
 * @brief a function to flash the red light. This function is called upon only when the temperature falls higher than the 
 *        expected range given the specified luminosity.
 * 
 * @return ** void 
 */
void flash_red()
{
    digitalWrite(RED, HIGH);   //turns red light on
    digitalWrite(GREEN, LOW);  //turns green light off
    digitalWrite(YELLOW, LOW); //turns yellow light off
}

/**
 * @brief a function to flash the yellow light. This function is called upon only when the temperature falls lower than the 
 *        expected range given the specified luminosity.
 * 
 * @return ** void 
 */
void flash_yellow()
{
    digitalWrite(RED, LOW);     //turns red light off
    digitalWrite(GREEN, LOW);   //turns green light off
    digitalWrite(YELLOW, HIGH); //turns yellow light on
}

/**
 * @brief this function serves to calculate the light percentage. The percentage of the sensor reading is divided by 679, 
 *        which is derived from the analog value that's read from the sensor after resistor. It is usually 1024 but, 
 *        because there is a resistor, the value is instead 679 
 * 
 * @param sensorReading 
 * @return ** unsigned long 
 */
unsigned long calculateLightPercentage(int sensorReading)
{
    int MAX_VALUE = 679; //

    return (unsigned long)sensorReading * 100 / MAX_VALUE; //calculation for light percentage
}

void setup()
{
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(YELLOW, OUTPUT);
    pinMode(PHOTORESISTOR, INPUT);
    pinMode(TEMPERATURE_SENSOR, INPUT);
    Serial.begin(9600);
}

/**
 * @brief This is a loop function that increments every 2 seconds. For every 2 seconds, the temperature and luminosity
 *        are read and measured via the temperature sensor and photoresistor. The reading is then printed onto serial given
 *        the conditionals stated below.
 * 
 * @return ** void 
 */
void loop()
{
    int light_intensity = calculateLightPercentage(analogRead(PHOTORESISTOR)); //light intensity is calculated through calculateLightPercentage
    temperature = convertTemperature(analogRead(TEMPERATURE_SENSOR));          //temperature is calculated through convertTemperature

    //if light intensity is zero
    if (light_intensity == 0)
    {
        if (temperature < -12) //if the temperature is within normal range then the light should flash green
        {
            flash_green();
        }
        else if (temperature > -12) //if the temperature is higher than the expected range then the light should flash red
        {
            flash_red();
        }
    }

    //if the light intensity ranges from 1-20
    else if (light_intensity <= 20 && light_intensity >= 1)
    {
        if (temperature >= 0 && temperature <= -12) //if the temperature is within normal range then the light should flash green
        {
            flash_green();
        }
        else if (temperature > -12) //if the temperature reads higher than the normale range then the light should flash red
        {
            flash_red();
        }
        else if (temperature < 0) //if the temperature reads lower than the expected temperature then the lights should flash yellow
        {
            flash_yellow();
        }
    }

    //if the light intensity ranges from 21-60
    else if (light_intensity >= 21 && light_intensity <= 60)
    {
        //the boundary here is adjusted to one as the table in the requirements specification has a duplicated 0 value temperature in two cells.
        //There should only be one range of luminosity that accepts 0 as an acceptable value
        if (temperature <= 20 && temperature >= 1) //if the temperature is within normal range then the light should flash green
        {
            flash_green();
        }
        //the boundary here is adjusted to one as the table in the requirements specification has a duplicated 0 value temperature in two cells.
        //There should only be one range of luminosity that accepts 0 as an acceptable value
        else if (temperature >= 1) //if the temperature reads higher than the normale range then the light should flash red
        {
            flash_red();
        }
        else if (temperature < 0) //if the temperature reads lower than the expected temperature then the lights should flash yellow
        {
            flash_yellow();
        }
    }

    //if the light intensity is 61 or higher
    else if (light_intensity >= 61)
    {
        if (temperature >= 21) //if the temperature is within normal range then the light should flash green
        {
            flash_green();
        }
        else if (temperature < 21) //if the temperature reads lower than the expected temperature then the lights should flash yellow
        {
            flash_yellow();
        }
    }

    Serial.print("LIGHT LEVEL IS ");       //String is printed onto serial to serve as information
    Serial.println(light_intensity);       //value of light_intensity is printed onto serial
    Serial.print("TEMPERATURE LEVEL IS "); //String is printed onto serial to serve as information
    Serial.println(temperature);           //value of temperature is printed onto serial
    delay(2000);
    // Serial.println(value);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(RED, HIGH);
}