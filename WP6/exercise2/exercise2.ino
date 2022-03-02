#define SPEAKER 9
#define TRIG_PIN 7
#define ECHO_PIN 6
#define LED_ONE 5
#define LED_TWO 4
#define LED_THREE 3
#define LED_FOUR 2

#define MAX_DISTANCE 200
#define MIN_DISTANCE 25

int duration = 0; //for sound wave
int distance = 0; //for distance


void setup() {
  // put your setup code here, to run once: 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_ONE, OUTPUT);
  pinMode(LED_TWO, OUTPUT);
  pinMode(LED_THREE, OUTPUT);
  pinMode(LED_FOUR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


}

float sound_wave_calculation() {
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034/2;
    cm = distance / 29; // speed of sound
}

void ultrasonic_sensor() {
    //clears the system and waits two milliseconds
    digitalWrite(TRIG_PIN, LOW);
    delay(2);

    //
    digitalWrite(TRIG_PIN, HIGH);
    delay(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = duration * sound_wave_calculation()

}
