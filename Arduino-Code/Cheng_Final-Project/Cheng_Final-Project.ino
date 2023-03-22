// Cheng Guo
// HCDE 439 - Final Project
// Reference 1: https://docs.arduino.cc/learn/electronics/lcd-displays

#include <LiquidCrystal.h> // include the LED code

// initialize Photoresistor, Joystick, and Ultrasonic Sensor
int photoResistor = A0; // set photo resistor input on pin A0
int median = 600; // set the median read from the photoResistor to 600
int xJoystick = A2; // set the x-axis input on pin A2
int yJoystick = A4; // set the y-axis input on pin A4

// initialize the library by associating any needed LCD interface pin
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// with the arduino pin number it is connected to
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// the setup routine runs once when you press reset:
void setup() {
  // initialize digital pins as input and outputs.
  pinMode(photoResistor, INPUT); // set photo resistor input on pin A0
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.print("I am here!"); // print the state on LCD
}

// the loop routine runs over and over again forever:
void loop() {
  // Adjust the trig pin before receiving pulse
    digitalWrite(trig, LOW); // adjust the trig pin before receiving pulse
    delay(2);  // wait for 2 milliseconds
    digitalWrite(trig, HIGH); // adjust the trig pin before receiving pulse
    delay(10);  // wait for 10 milliseconds
    digitalWrite(trig, LOW); // adjust the trig pin before receiving pulse

  // petting on the top of the robot
  int photoInput = analogRead(photoResistor); // read the input from the photo resistor
  if (photoInput < median) { // if the light input is small, then the owner is petting
    lcd.clear(); // clean the LCD for display
    lcd.setCursor(0, 0); // set the cursor to (0,0)
    lcd.print("I Love You!"); // print the state on LCD
    delay(1000); // delay for 1 second
  } else { // if the light input is big, return to normal face
    lcd.clear(); // clean the LCD for display
    lcd.setCursor(0, 0); // set the cursor to (0,0)
    lcd.print("I am here!"); // print the state on LCD
    delay(1000); // delay for 1 second
  }

  // change the face output on LCD based on joystick inputs
  int xInput = analogRead(xJoystick); // record input from x-axis
  int yInput = analogRead(yJoystick); // record input from y-axis
  if (xInput < 200 && yInput < 200) { // if the joystick is on the top-left
    lcd.clear(); // clean the LCD for display
    lcd.setCursor(0, 0); // set the cursor to (0,0)
    lcd.print("Lift me up!"); // print the state on LCD
    delay(1000); // delay for 1 second
  } else if (xInput < 200 && yInput > 823) { // if the joystick is on the bottom-left
    lcd.clear(); // clean the LCD for display
    lcd.setCursor(0, 0); // set the cursor to (0,0)
    lcd.print("Turn left!"); // print the state on LCD
    delay(1000); // delay for 1 second
  } else if (xInput > 823 && yInput < 200) { // if the joystick is on the top-right
    lcd.clear(); // clean the LCD for display
    lcd.setCursor(0, 0); // set the cursor to (0,0)
    lcd.print("Turn right!"); // print the state on LCD
    delay(1000); // delay for 1 second
  } else if (xInput > 823 && yInput > 823) { // if the joystick is on the bottom-right
    lcd.clear(); // clean the LCD for display
    lcd.setCursor(0, 0); // set the cursor to (0,0)
    lcd.print("Put me down!"); // print the state on LCD
    delay(1000); // delay for 1 second
  }
}
