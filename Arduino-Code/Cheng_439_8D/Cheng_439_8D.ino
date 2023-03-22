// Cheng Guo
// HCDE 439 -  Midterm 8D

int trig = 9;
int echo = 10;
float duration;
float distance;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pins as input and outputs.
  pinMode(trig, INPUT);
  pinMode(echo, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(trigPin, LOW); 
  delay(5); 
  digitalWrite(trigPin, HIGH);
  delay(5); 
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH); 
  distance = (duration*.0343)/2; 
  Serial.print("Distance: "); 
  Serial.println(distance); 
  delay(1000);
}


