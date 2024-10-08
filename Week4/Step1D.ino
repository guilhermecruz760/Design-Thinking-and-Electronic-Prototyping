#include <Servo.h> // Include Servo library

Servo myServo;
int motorPin1 = 6;
int motorPin2 = 7;
int xPin = A0;
int yPin = A1;
int zPin = A2;

float xVal, yVal, zVal = 0;

const int xLeftMin = 300;  
const int xLeftMax = 400;
const int xRightMin = 600;
const int xRightMax = 700;
const int yForwardMin = 300;
const int yForwardMax = 400;
const int yBackwardMin = 600;
const int yBackwardMax = 700;

const float smoothingFactor = 0.2;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);  // Servo in pin 9
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  
  int newXVal = analogRead(xPin);
  int newYVal = analogRead(yPin);
  int newZVal = analogRead(zPin);

  xVal = (smoothingFactor * newXVal) + ((1-smoothingFactor)*xVal);
  yVal = (smoothingFactor * newYVal) + ((1-smoothingFactor)*yVal);
  zVal = (smoothingFactor * newZVal) + ((1-smoothingFactor)*zVal);

  
  if (isDeviceLeft(xVal)) {
    myServo.write(0);  // Servo turns left
    Serial.println("Servo turning left!");
  }
  else if (isDeviceRight(xVal)) {
    myServo.write(180);  // Servo turns right
    Serial.println("Servo turning right!");
  }
  else if (isDeviceForward(yVal)) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    Serial.println("Motor spinning forward!");
  }
  else if (isDeviceBackward(yVal)) {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    Serial.println("Motor spinning backward!");
  }
  else {
    myServo.write(90);  // Servo in neutral position
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);  
  }

  delay(200);
}


bool isDeviceLeft(int x) {
  return (x < xLeftMin && x > xLeftMax);
}

bool isDeviceRight(int x) {
  return (x > xRightMin && x < xRightMax);
}

bool isDeviceForward(int y) {
  return (y > yForwardMin && y < yForwardMax);
}

bool isDeviceBackward(int y) {
  return (y < yBackwardMin && y > yBackwardMax);
}
