// C++ code
//
#define RED 13
#define GREEN 12
#define YELLOW 11
#define PHOTORESISTOR A0
#define TEMPERATURE_SENSOR A1

int light_intensity;
double temperature;

double convertTemperature(int sensorReading)
{
    double voltage = sensorReading * 5.0;
    voltage /= 1024.0;
    temperature = (voltage - 0.5) * 100;
    return temperature;
}

unsigned long calculateLightPercentage(int sensorReading)
{
    int MAX_VALUE = 679;

    return (unsigned long)sensorReading * 100 / MAX_VALUE;
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

void loop()
{
    int light_intensity = calculateLightPercentage(analogRead(PHOTORESISTOR));
    temperature = convertTemperature(analogRead(TEMPERATURE_SENSOR));

    if (light_intensity == 0)
    {
        if (temperature < -12)
        {
            digitalWrite(RED, LOW);
            digitalWrite(GREEN, HIGH);
        }
        else if (temperature > -12)
        {
            digitalWrite(GREEN, LOW);
            digitalWrite(RED, HIGH);
        }
    }
    else if (light_intensity <= 20 && light_intensity >= 1)
    {
        if (temperature <= 0 && temperature >= -12)
        {
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, HIGH);
        }
        else if (temperature > -12)
        {
            digitalWrite(GREEN, LOW);
            digitalWrite(YELLOW, LOW);
            digitalWrite(RED, HIGH);
        }
        else if (temperature < 0)
        {
            digitalWrite(GREEN, LOW);
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, HIGH);
        }
    }
    else if (light_intensity >= 21 && light_intensity <= 60)
    {
        if (temperature <= 20 && temperature >= 1)
        {
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, HIGH);
        }
        else if (temperature >= 21)
        {
            digitalWrite(GREEN, LOW);
            digitalWrite(YELLOW, LOW);
            digitalWrite(RED, HIGH);
        }
        else if (temperature < 0)
        {
            digitalWrite(GREEN, LOW);
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, HIGH);
        }
    }
    else if (light_intensity >= 61)
    {
        if (temperature >= 21)
        {
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, LOW);
            digitalWrite(GREEN, HIGH);
        }
        else if (temperature < 21)
        {
            digitalWrite(RED, LOW);
            digitalWrite(YELLOW, HIGH);
            digitalWrite(GREEN, LOW);
        }
    }

    Serial.print("LIGHT LEVEL IS ");
    Serial.println(light_intensity);
    Serial.print("TEMPERATURE LEVEL IS ");
    Serial.println(temperature);
    delay(2000);
    // Serial.println(value);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(RED, HIGH);
}