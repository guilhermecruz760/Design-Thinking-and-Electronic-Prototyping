#include <RGBLed.h>

const int blueColor = 5;
const int redColor = 6;
const int greenColor = 9;

void setup() {
  pinMode(greenColor, OUTPUT);
  pinMode(redColor, OUTPUT);
  pinMode(blueColor, OUTPUT);
}

void loop() {
  RGBLed led(redColor, greenColor, blueColor, RGBLed::COMMON_CATHODE);
  led.setColor(RGBLed::WHITE);
  delay(2000);

  led.crossFade(RGBLed::WHITE, RGBLed::MAGENTA, 200, 2000);

  delay(5000);  
}
