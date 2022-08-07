#define TRIG_PIN   26 // ESP32 pin GIOP26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN   25 // ESP32 pin GIOP25 connected to Ultrasonic Sensor's ECHO pin
#define BUZZER_PIN 17 // ESP32 pin GIOP17 connected to Piezo Buzzer's pin
#define DISTANCE_THRESHOLD 80 // centimeters

float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);         // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);   // set ESP32 pin to output mode
  pinMode(ECHO_PIN, INPUT);    // set ESP32 pin to input mode
  pinMode(BUZZER_PIN, OUTPUT); // set ESP32 pin to output mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);  

  if (distance_cm < DISTANCE_THRESHOLD){
    digitalWrite(BUZZER_PIN, HIGH); // turn on Piezo Buzzer
    delay(12.5 * distance_cm); 
    digitalWrite(BUZZER_PIN, LOW);  // turn off Piezo Buzzer
    delay(12.5 * distance_cm);
  }
}
