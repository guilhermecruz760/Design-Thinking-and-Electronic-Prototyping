#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
#define LED_PIN 13 // LED pin (either onboard or external)

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass the oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Start the temperature sensor library
  sensors.begin();
  
  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Request temperature from sensors
  sensors.requestTemperatures();
  
  // Fetch the temperature in Celsius
  float temperatureC = sensors.getTempCByIndex(0); // 0 stand for the index of the sensor we want to collect data. If we had more sensors connected to the same bus wire, we had to put like 1 for the second sensor
  
  // Print temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  // If the temperature is above 27 degrees, turn on the LED
  if (temperatureC > 27.0) {
    digitalWrite(LED_PIN, HIGH); // Turn on LED
    Serial.println("Warning: High temperature!");
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
  }
  
  // Wait before the next reading
  delay(1000);
}
