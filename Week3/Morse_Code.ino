const int ledPin = 7;
String input = "";
String morseTable[36] = {
  "SL", "LSSS", "LSLS", "LSS", "S", "SSLS", "LLS", "SSSS", "SS", "SLLL",
  "LSL", "SLSS", "LL", "LS", "LLL", "SLLS", "LLSL", "SLS", "SSS", "L",
  "SSL", "SSSL", "SLL", "LSSL", "LSLL", "LLSS", "SLLLL", "SSLLL", "SSSLL",
  "SSSSL", "SSSSS", "LSSSS", "LLSSS", "LLLSS", "LLLLS", "LLLLL"
};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
  Serial.println("Enter a message to convert to Morse code:"); 
}

void shortBlink() {
  digitalWrite(ledPin, HIGH);
  delay(200);  
  digitalWrite(ledPin, LOW);
  delay(200);  
}

void longBlink() {
  digitalWrite(ledPin, HIGH);
  delay(600);  
  digitalWrite(ledPin, LOW);
  delay(200);  
}

void pause() {
  digitalWrite(ledPin, LOW);
  delay(600);
}

void longPause() {
  digitalWrite(ledPin, LOW);
  delay(1500); 
}


String convertToMorse(String text) {
  
  String morseOutput = "";

  for (int i = 0; i < text.length(); i++) {
    char currentChar = text[i];
    if (currentChar >= 'a' && currentChar <= 'z') {
      int index = currentChar - 'A';
      morseOutput += morseTable[index] + "P"; 
    } else if (currentChar >= '0' && currentChar <= '9') {
      int index = currentChar - '0' + 26; 
      morseOutput += morseTable[index] + "P"; 
    }
    else if (currentChar == ' '){
      morseOutput+= " ";
    }
  }
  Serial.println(morseOutput);
  return morseOutput;
}

void decodeMorse(String morseCode) {
  for (int i = 0; i < morseCode.length(); i++) {
    char currentChar = morseCode[i];
    Serial.println(currentChar);

    if (currentChar == 'S') {
      shortBlink(); 
    } else if (currentChar == 'L') {
      longBlink(); 
    } else if (currentChar == 'P') {
      pause();
    } else if (currentChar == ' ') {
      longPause();
    }
  }
}

void loop() {
  if (Serial.available() >= 1) {
    String input = Serial.readString();
    Serial.println(input);
    String morseCode = convertToMorse(input); 
    //Serial.println(morseCode);
    Serial.println("Morse Code printed");  
    decodeMorse(morseCode); 
    Serial.println("Message sent in Morse code!");
  }
  delay(5000);
}
