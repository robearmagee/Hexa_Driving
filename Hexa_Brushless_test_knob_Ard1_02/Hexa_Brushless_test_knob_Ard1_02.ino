/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

// ++++++ ARDUINO #1 ++++++

#include <Servo.h>

Servo esc1;  // create servo object to control a servo
Servo esc3;  // 1, 3, 5 are driven by Arduino 1 (2,4,6 by Arduino 2)
Servo esc5;


int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  esc1.attach(1);
  esc3.attach(3);
  esc5.attach(5);  // attaches the servo on pin 5 to the servo object

  esc1.writeMicroseconds(1000);
  esc3.writeMicroseconds(1000); //initialise to 1000
  esc5.writeMicroseconds(1000);

  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);     // scale it to use it with the servo (value between 0 and 180)
  esc1.writeMicroseconds(val);
  esc3.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  esc5.writeMicroseconds(val);

  //delay(15);                           // waits for the servo to get there
}



