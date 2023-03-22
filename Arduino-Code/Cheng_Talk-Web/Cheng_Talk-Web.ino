// Cheng Guo
// HCDE 439 - HW 6

// initialize LED and Joystick
int xJoystick = A0; // set the x-axis input on pin A0
int yJoystick = A2; // set the y-axis input on pin A2
int greenLED = 5; // initialize the green LED on pin 5

// the setup routine runs once when you press reset:
void setup() {
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    pinMode(greenLED, OUTPUT); // initialize the green LED on pin 5
}

// the loop routine runs over and over again forever:
void loop() {
    // record input from the joystick
    Serial.print("["); // print a bracket to the serial monitor
    Serial.print(analogRead(xJoystick)); // print the x value to the serial monitor
    Serial.print(","); // print a comma to the serial monitor
    Serial.print(analogRead(yJoystick)); // print the y value to the serial monitor
    Serial.println("]"); // print a bracket to the serial monitor
    
    // change the brightness of the LED based on keyboard input
    if (Serial.available() > 0) { // if there's serial data 
    int inByte = Serial.read(); // read it
    Serial.write(inByte); // send it back out as raw binary data
    analogWrite(greenLED, inByte); // use it to set the green LED brightness
    } else { // if there is no serial data
    analogWrite(greenLED, 0); // turns off the green LED
    }
}