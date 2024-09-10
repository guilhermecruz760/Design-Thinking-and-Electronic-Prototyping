const int button = 13;
const int ledPin1 = 3;
const int ledPin2 = 4;
int state;
void setup() {
  pinMode(button, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  if (digitalRead(button) == 1){
    if (state == 2){
      state = 0;
      delay(250);
    }
    else{
      state +=1;
      delay(250);
    }
  }
  Serial.println(digitalRead(button));
  switch (state) {
  case 0:
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2,0);
  break;
  case 1:
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2,0);
  break;
  case 2:
    digitalWrite(ledPin1, 1);
    digitalWrite(ledPin2,1);
  break;
  }
}
