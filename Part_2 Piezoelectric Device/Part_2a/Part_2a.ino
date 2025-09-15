const int sensorPin=A0;
const int ledPin= 13;
int sensorValue = 0;
const int threshold = 800;

void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if (sensorValue > threshold)
  {
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}