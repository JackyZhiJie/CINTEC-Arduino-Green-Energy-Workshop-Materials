const int echoPin = 8;
const int trigPin = 9;
const int sensorPin = A0;
int sensorValue = 0;
const int ledRed = 13;
const int ledGreen = 12;
const int threshold = 400;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
}

void loop() {
  long duration, inches, cm;
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);

  if (cm <= 20) {
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  } else if (sensorValue > threshold) {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, LOW);
  } else {
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  }
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
