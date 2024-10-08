#include <SoftwareSerial.h>


SoftwareSerial mySerial(11, 10); // RX (pin 11), TX (pin 10) -- RX only is used on Board B


const int LED_PIN = 9;

void setup() {

  mySerial.begin(9600);


  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  Serial.println("Board B: Waiting for commands...");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); 
}

void loop() {

  if (mySerial.available()) {
    String command = mySerial.readStringUntil('\n');
    command.trim(); // Remove any trailing newline or carriage return
    Serial.print("Board B: Received command -> ");
    Serial.println(command);

   
    if (command.equalsIgnoreCase("on")) {
      digitalWrite(LED_PIN, HIGH); // Turn LED on
      Serial.println("Board B: LED turned ON.");
    }
    else if (command.equalsIgnoreCase("off")) {
      digitalWrite(LED_PIN, LOW); // Turn LED off
      Serial.println("Board B: LED turned OFF.");
    }
    else {
      Serial.println("Board B: Unknown command received.");
    }

    delay(1000); // 1-second delay after processing
  }
}
