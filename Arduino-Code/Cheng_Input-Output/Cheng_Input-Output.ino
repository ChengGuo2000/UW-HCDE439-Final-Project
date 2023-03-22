// Cheng Guo
// HCDE 439 - HW 3
// Reference 1: https://docs.arduino.cc/learn/electronics/servo-motors
// Reference 2: https://www.arduino.cc/reference/en/libraries/servo/ 

#include <Servo.h>

// initialize pins, brightness, and fade amount
Servo hw3Servo; /// initialize a servo for HW 3
int photoResistor = A0; // set photo resistor on pin A0
int redLED = 3; // set the red LED on pin 3
int servo = 6; // set the servo on pin 6
int min = 400; // set the minimum read from the photoResistor to 400
int max = 800; // set the minimum read from the photoResistor to 800
int middle = (min + max) / 2; // set the middle value between min and max
int delayTime = 250; // wait for a quarter second for servo to respond

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pins as input and outputs.
  pinMode(photoResistor, INPUT); // intialize the photo resistor on pin A0
  pinMode(redLED, OUTPUT); // initialize red LED on pin 3
  hw3Servo.attach(servo); // attach the servo on pin 6
}

// the loop routine runs over and over again forever:
void loop() {
  int photoInput = analogRead(photoResistor); // read the input from the photo resistor
  Serial.println(photoInput); // show the output on the serial monitor
  int mapped = map(photoInput, min, max, 255, 0); // map the output to the range of LED
  int constrained = constrain(mapped, 10, 245); // constrain the output in the middle between 10 and 245
  analogWrite(redLED, constrained); // write the output to the red LED
  if (photoInput > middle) { // if the input is large, keep the servo at 0 degree
    hw3Servo.write(0); // keep the servo at 0 degree
    delay(delayTime); // wait for a quarter second for servo to respond
  } else { // if the input is small, turn the servo to 180 degree
    hw3Servo.write(180); //  turn the servo to 180 degree
    delay(delayTime); // wait for a quarter second for servo to respond
  }
}
