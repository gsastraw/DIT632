// (C) Gregory Sastrawidjaya, Klara Svensson, Julia Van Kirk, group: 31
// Work package 6
// Exercise 1
// Submission code:

#define SPEAKER_PIN 9
#define TRIG_PIN 7
#define ECHO_PIN 6
#define LED_ONE 5
#define LED_TWO 4
#define LED_THREE 3
#define LED_FOUR 2

#define MAX_DISTANCE 200
#define MIN_DISTANCE 25

long duration; //for sound wave
long distance; //for distance

void setup()
{
  // put your setup code here, to run once:
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_ONE, OUTPUT);
  pinMode(LED_TWO, OUTPUT);
  pinMode(LED_THREE, OUTPUT);
  pinMode(LED_FOUR, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  ultrasonic_sensor();
  turnOnLedBasedOnDistance();
  turnOnSoundBasedOnDistance();
  Serial.println(distance);
}

unsigned long sound_wave_calculation(unsigned long pulseLength)
{
  distance = pulseLength * 0.034 / 2;
  return distance / 29; // speed of sound
}

void ultrasonic_sensor()
{
  //clears the system and waits two milliseconds
  digitalWrite(TRIG_PIN, LOW);
  delay(2);

  //
  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  distance = pulseIn(ECHO_PIN, HIGH);
  duration *= sound_wave_calculation(distance);

  // duration = duration * sound_wave_calculation()
}

void turnOnLedBasedOnDistance()
{
  // less than 30
  if (distance < 30)
  {
    digitalWrite(LED_ONE, HIGH);
    digitalWrite(LED_TWO, HIGH);
    digitalWrite(LED_THREE, HIGH);
    digitalWrite(LED_FOUR, HIGH);
    // >= 30 and <= 80
  }
  else if (distance < 80 && distance >= 30)
  {
    digitalWrite(LED_ONE, HIGH);
    digitalWrite(LED_TWO, HIGH);
    digitalWrite(LED_THREE, HIGH);
    digitalWrite(LED_FOUR, LOW);
    // >= 80 and < 130
  }
  else if (distance < 130 && distance >= 80)
  {
    digitalWrite(LED_ONE, HIGH);
    digitalWrite(LED_TWO, HIGH);
    digitalWrite(LED_THREE, LOW);
    digitalWrite(LED_FOUR, LOW);
    // greater than or equal to 130 and less than or equal to 200
  }
  else if (distance <= MAX_DISTANCE && distance >= 130)
  {
    digitalWrite(LED_ONE, HIGH);
    digitalWrite(LED_TWO, LOW);
    digitalWrite(LED_THREE, LOW);
    digitalWrite(LED_FOUR, LOW);
  }
  else
  {
    digitalWrite(LED_ONE, LOW);
    digitalWrite(LED_TWO, LOW);
    digitalWrite(LED_THREE, LOW);
    digitalWrite(LED_FOUR, LOW);
  }
}

void turnOnSoundBasedOnDistance()
{
  if (distance < MIN_DISTANCE)
  {
    tone(SPEAKER_PIN, 5000);
    // >= 30 and <= 80
  }
  else if (distance < 80 && distance >= MIN_DISTANCE)
  {
    tone(SPEAKER_PIN, 1500);
    // >= 80 and < 130
  }
  else if (distance < 130 && distance >= 80)
  {
    tone(SPEAKER_PIN, 750);
    // greater than or equal to 130 and less than or equal to 200
  }
  else if (distance <= MAX_DISTANCE && distance >= 130)
  {
    tone(SPEAKER_PIN, 325);
  }
  else
  {
    noTone(SPEAKER_PIN);
  }
}
