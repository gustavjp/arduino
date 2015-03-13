const int b[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int buttonPin = 10;
const int bits = 8;
int buttonState = LOW;
int number = 0;
unsigned long time;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < bits; i++) {
    pinMode(b[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  time = millis();
}

void loop() {
  if (millis() - time >= 200) {
    buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
    if (buttonState == HIGH) {
      if (number >= (pow(2, bits) - 1)) {
        number = 0;
      } else {
        number++;
      }
      binary(number);
    }
    time = millis();
  }
}

void binary(int number) {
  for (int i = 0; i < bits; i++){
    if (bitRead(number, i) == 1) {
      digitalWrite(b[i], HIGH); 
    } else {
      digitalWrite(b[i], LOW); 
    }
  }
}
