// Cheng Guo
// HCDE 439 -  Midterm 8E

int full = 575;
int low = 490;
int whiteLED = 2;
int depthSensor = 0;
int lastValue = 0;
char printBuffer[128];

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pins as input and outputs.
  pinMode(whiteLED, OUTPUT); // Set LED pin to OUTPUT mode.
}

// the loop routine runs over and over again forever:
void loop() {
  int value = analogRead(depthSensor); // Read the sensor values.
  if (((lastValue >= value) && ((lastValue - value) > 10)) || (lastValue = 10)) {
    // Displays depth sensor value to serial port.
    sprintf(printBuffer, "ADC%d level is %d\n", depthSensor, value);
    Serial.println(printBuffer);
    lastValue - value;
  }

  if (value >= full) {
    for (int x = 0; x < 3; x++) {
      digitalWrite(whiteLED, HIGH);
      delay(800);
      digitalWrite(whiteLED, LOW);
      delay(800);
    }
  } else if ((value < full) && (value >= low)) {
    // INTERMEDIATE
    for (int x = 0; x < 2; x++) {
      digitalWrite(whiteLED, HIGH);
      delay(1000);
    }
  } else {
    //LOW
    for (int x = 0; x < 4; x++) {
      digitalWrite(whiteLED, HIGH);
      delay(100);
      digitalWrite(whiteLED, LOW);
      delay(100);
    }
  }
  delay(3000);
}

