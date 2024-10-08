#include <SoftwareSerial.h>


const int RX_PIN = 10;
const int TX_PIN = 11;


SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX


const String MESSAGE_A = "Ping";
const String EXPECTED_B = "Pong";

void setup() {

  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println("Board A: Starting communication...");


  mySerial.begin(9600);
  delay(1000); 

  sendMessageA();
}

void loop() {

  if (mySerial.available()) {
    String incoming = mySerial.readStringUntil('\n');
    incoming.trim(); // Remove any trailing newline or carriage return
    Serial.print("Board A: Received -> ");
    Serial.println(incoming);

    if (incoming.equals(EXPECTED_B)) {
      
      delay(1000); // 1-second delay before responding
      sendMessageA();
    } else {
      Serial.println("Board A: Unexpected message received.");
    }
  }
}


void sendMessageA() {
  mySerial.println(MESSAGE_A);
  Serial.print("Board A: Sent -> ");
  Serial.println(MESSAGE_A);
}
