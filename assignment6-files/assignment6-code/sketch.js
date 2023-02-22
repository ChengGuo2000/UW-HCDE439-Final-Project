var serial; // variable to hold an instance of the serialport library
var portName = '/dev/tty.usbmodem14201'; //rename to the name of your port
var xPos = 0; // initialize a placeholder for x-position
var xInput; // initialize a placeholder for x-axis input
var yInput; // initialize a placeholder for y-axis input

function setup() {
  serial = new p5.SerialPort();       // make a new instance of the serialport library
  serial.on('list', printList);       // set a callback function for the serialport list event
  serial.on('connected', serverConnected); // callback for connecting to the server
  serial.on('open', portOpen);        // callback for the port opening
  serial.on('data', serialEvent);     // callback for when new data arrives
  serial.on('error', serialError);    // callback for errors
  serial.on('close', portClose);      // callback for the port closing

  serial.list();                      // list the serial ports
  serial.open(portName);              // open a serial port
  createCanvas(600, 600);             // make a 600 * 600 pixels canvas
}

// get the list of ports:
function printList(portList) {
 // portList is an array of serial port names
 for (var i = 0; i < portList.length; i++) {
 // Display the list the console:
   print(i + " " + portList[i]);
 }
}

function serverConnected() {
  print('connected to server.');
}

function portOpen() {
  print('the serial port opened.')
}

function serialError(err) {
  //print('Something went wrong with the serial port. ' + err);
  print(err);
}

function portClose() {
  print('The serial port closed.');
}

function serialEvent() {
  if (serial.available()) {
    var datastring = serial.readLine(); // read in some serial
	  var maybeArray; // initialize a placeholder for array input
    try {
        maybeArray = JSON.parse(datastring); // can we parse the serial?
        xInput = maybeArray[0]; // record the x-axis input
        yInput = maybeArray[1]; // record the y-axis input
        console.log("got back " + xInput + " and " + yInput); // print the output to the console
      } catch(err) {
      // got something that's not a json
    }
  }
}

function keyPressed() { // function for P5 communicates to Arduino
	console.log("writing key"); // check the console if a key is pressed
	serial.write(key); // write the key to the Arduino
}


function graphData(newData) {
  // map the range of the input to the window height:
  var yPos = map(newData, 0, 255, 0, height);
  // draw the line in a pretty color:
  stroke(255, 0, 80);
  line(xPos, height, xPos, height - yPos);
  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    // clear the screen by resetting the background:
    background(0x08, 0x16, 0x40);
  } else {
    // increment the horizontal position for the next reading:
    xPos++;
  }
}

function draw() { // function for Arduino communicates to P5
  background(0); // initialize the background color
  fill(255); // initialize the fill color

  if (xInput < 200 && yInput < 200) { // if the joystick is on the top-left
    text("Move up", 300,300); // write "Move up" in the middle of the screen
  } else if (xInput < 200 && yInput > 823) { // if the joystick is on the bottom-left
    text("Move to the left", 300,300); // write "Move to the left" in the middle of the screen
  } else if (xInput > 823 && yInput < 200) { // if the joystick is on the top-right
    text("Move to the right", 300,300); // write "Move to the right" in the middle of the screen
  } else if (xInput > 823 && yInput > 823) { // if the joystick is on the bottom-right
    text("Move down", 300,300); // write "Move down" in the middle of the screen
  } else { // if the joystick remains on the original position
    text("No motion", 300,300) // write "No motion" in the middle of the screen
  }
}