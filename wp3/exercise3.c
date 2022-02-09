// C++ code
//

#define TEMPERATURE_SENSOR A1

int light_intensity;
double temperature;

double convertTemperature(int sensorReading) {
  double voltage = (sensorReading * 5.0) / 1024.0;
  temperature = (voltage - 0.5) * 100;
  return temperature;
}

void setup()
{
  pinMode(TEMPERATURE_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop()
{
  temperature = convertTemperature(analogRead(TEMPERATURE_SENSOR));
  
  Serial.print("TEMPERATURE LEVEL IS ");
  Serial.println(temperature);
  delay(2000);
  // Serial.println(value);
}