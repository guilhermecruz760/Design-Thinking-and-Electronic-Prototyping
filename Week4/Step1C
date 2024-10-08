#include <Servo.h> // Include Servo library

Servo myServo;
int motorPin1 = 6;
int motorPin2 = 7;
int zPin = A0;
int yPin = A1;
int xPin = A2;

const int xLeftMin = 200;  
const int xLeftMax = 330;
const int xRightMin = 350;
const int xRightMax = 700;
const int yForwardMin = 345;
const int yForwardMax = 400;
const int yBackwardMin = 200;
const int yBackwardMax = 320;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);  // Servo in pin 9
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  int xVal = 0, yVal = 0, zVal = 0;
  int nAve = 10;

  
  for (int i = 0; i < nAve; i++) {
    xVal += analogRead(xPin);
    
    yVal += analogRead(yPin);
    
    zVal += analogRead(zPin);
    
    delay(200);
  }

  // Calculate averages
  xVal /= nAve;
  yVal /= nAve;
  zVal /= nAve;
  Serial.println(xVal);
  Serial.println(yVal);
  Serial.println(zVal);
  
  
  if (isDeviceLeft(xVal)) {
    myServo.write(0);  // Servo turns left
    Serial.println("Servo turning left!");
    delay(500);
    myServo.write(90); 
  }
  else if (isDeviceRight(xVal)) {
    myServo.write(180);
    delay(500);
    myServo.write(90);  
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

  delay(1000);
}


bool isDeviceLeft(int x) {
  return (x > xLeftMin && x < xLeftMax);
}

bool isDeviceRight(int x) {
  return (x > xRightMin && x < xRightMax);
}

bool isDeviceForward(int y) {
  return (y > yForwardMin && y < yForwardMax);
}

bool isDeviceBackward(int y) {
  return (y > yBackwardMin && y < yBackwardMax);
}
