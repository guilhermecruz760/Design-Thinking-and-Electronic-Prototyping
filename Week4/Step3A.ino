const int sensorPin = A0;  // Pin connected to the sensor's analog output
float scalingFactor = 1.43;  // Calculated scaling factor from empirical testing

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Read the analog input (ADC value)
  float distance = sensorValue * scalingFactor;  // Convert ADC value to cm

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" - Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // Small delay for readability
}
