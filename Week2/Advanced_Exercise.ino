#include <RGBLed.h>
const int blueColor = 5;
const int redColor = 6;
const int greenColor = 9;
RGBLed led(redColor, greenColor, blueColor, RGBLed::COMMON_CATHODE);
void setup() {

}

void loop() {
  led.setColor(RGBLed::GREEN);
  delay(2000);
  led.setColor(RGBLed::YELLOW);
  delay(2000);
  led.setColor(RGBLed::RED);
  delay(5000);
}

