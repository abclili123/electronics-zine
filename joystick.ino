// set up pins and variable
int redLed = 11;
int blueLed = 9;
int greenLed = 10;
int VrX = A0;
int VrY = A1;
int xPos;
int yPos;
int redVal;
int blueVal;
int led = 3;

void setup() {                // this block runs once to configure pins
  pinMode(redLed, OUTPUT);    // led pins send output
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(VrX, INPUT);        // joystick pins receive input
  pinMode(VrY, INPUT);
  analogReference(INTERNAL);
}

void loop() {                         // this block runs continually
  xPos = analogRead(VrX);             // read x position from joystick
  xPos = map(xPos, 0, 1023, 0, 255);  // convert x position to led value
  redVal = xPos;                      // assign led value
  
  yPos = analogRead(VrY);             // do the same for y
  yPos = map(yPos, 0, 1023, 0, 255);
  blueVal = yPos;
  
  analogWrite(redLed, redVal);        // write led value to led
  analogWrite(blueLed, blueVal);
  analogWrite(greenLed, 0);
  analogWrite(led, 255);
}
