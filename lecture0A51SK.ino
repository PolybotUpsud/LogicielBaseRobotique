const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot

int32_t interpolate(int32_t x) {
  return -33*x*x*x/67108864 + 34*x*x/65536 - 49*x/256 + 27;
}

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(19200);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  Serial.println(interpolate(sensorValue));

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(1);
}
