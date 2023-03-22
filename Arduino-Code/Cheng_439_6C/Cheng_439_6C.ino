// Cheng Guo
// HCDE 439 -  Midterm 6E

int count = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pins as input and outputs.
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  if (digitalRead(8) == HIGH) {
    count++;
    delay(500);
  }
  if (count % 2 == 0) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
  Serial.print(count);
  Serial.println(" times pressed");
}


