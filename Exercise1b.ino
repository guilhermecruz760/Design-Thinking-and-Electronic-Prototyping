const int led[] = {3, 4, 5, 6, 7, 8}; 
const int button = 13;    

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }
  pinMode(button, INPUT);
  randomSeed(analogRead(0)); 
}

void loop() {
  if (digitalRead(button) == 1) {
    int num = random(1, 7);         
    lightUpLeds(num);    
    delay(2000);                      
    turnOffLeds();                   
  }
}

void lightUpLeds(int num) {
  int selectedLeds[6] = {0, 0, 0, 0, 0, 0};  
  for (int i = 0; i < num; i++) {
    int ledIndex;
    do {
      ledIndex = random(0, 6);              
    } while (selectedLeds[ledIndex] == 1);   
    selectedLeds[ledIndex] = 1;              
    digitalWrite(led[ledIndex], HIGH);      
  }
}

void turnOffLeds() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(led[i], LOW);               
  }
}
