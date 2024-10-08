#include <SoftwareSerial.h>


const int RX_PIN = 10;
const int TX_PIN = 11;


SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX


const String EXPECTED_A = "Ping";
const String MESSAGE_B = "Pong";

void setup() {

  Serial.begin(9600);
  while (!Serial) {
 
  }
  Serial.println("Board B: Waiting for messages...");

  
  mySerial.begin(9600);
}

void loop() {
 
  if (mySerial.available()) {
    String incoming = mySerial.readStringUntil('\n');
    incoming.trim(); // Remove any trailing newline or carriage return
    Serial.print("Board B: Received -> ");
    Serial.println(incoming);

    if (incoming.equals(EXPECTED_A)) {
      // Verified message A
      delay(1000); // 1-second delay before responding
      sendMessageB();
    } else {
      Serial.println("Board B: Unexpected message received.");
    }
  }
}


void sendMessageB() {
  mySerial.println(MESSAGE_B);
  Serial.print("Board B: Sent -> ");
  Serial.println(MESSAGE_B);
}
