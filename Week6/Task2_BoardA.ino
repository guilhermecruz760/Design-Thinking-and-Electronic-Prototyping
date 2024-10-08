#include <SoftwareSerial.h>


SoftwareSerial mySerial(10, 11); // RX (pin 11), TX (pin 10) -- TX only is used on Board A

void setup() {

  mySerial.begin(9600);
  

  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  Serial.println("Board A: Ready to send commands ('on'/'off').");
}

void loop() {

  if (Serial.available()) {
    String userInput = Serial.readStringUntil('\n');
    userInput.trim(); // Remove any trailing newline or carriage return
    Serial.print("Board A: Received input -> ");
    Serial.println(userInput);

    // Validate input
    if (userInput.equalsIgnoreCase("on") || userInput.equalsIgnoreCase("off")) {
      mySerial.println(userInput);  // Send data through TX pin 10
      Serial.print("Board A: Sent command -> ");
      Serial.println(userInput);
      delay(1000); // 1-second delay after sending
    } else {
      Serial.println("Board A: Invalid command. Please enter 'on' or 'off'.");
    }
  }
}
