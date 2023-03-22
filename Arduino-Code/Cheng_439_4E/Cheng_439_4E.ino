// Cheng Guo
// HCDE 439 -  Midterm 4E

// the setup routine runs once when you press reset:
void setup() {
  // initialize digital pins as input and outputs.
  pinMode(11, OUTPUT); // initialize red LED on pin 11
  pinMode(10, OUTPUT); // initialize green LED on pin 10
  pinMode(9, OUTPUT); // initialize blue LED on pin 9
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i = 0; i <= 255; i++) { // use a for loop to decrease the value for analogWrite
    int redWrite = i * 4; // make the red fade four times faster than the blue one
    redWrite = constrain(redWrite, 0, 255); // limit the output to the red LED in a valid range
    int greenWrite = i * 2; // make the green fade two times faster than the blue one
    greenWrite = constrain(greenWrite, 0, 255); // limit the output to the green LED in a valid range
    analogWrite(11, redWrite); // fade the red LED
    analogWrite(10, greenWrite); // fade the green LED
    analogWrite(9, i); // fade the blue LED
    delay(10); // wait for a centisecond
  }
  delay(250); // wait for a quarter second
}
