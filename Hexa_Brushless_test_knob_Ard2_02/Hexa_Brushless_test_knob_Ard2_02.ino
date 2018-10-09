/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

// ++++++ ARDUINO #2 ++++++

#include <Servo.h>

Servo esc2;  // create servo object to control a servo
Servo esc4;  // 2, 4, 6 are driven by Arduino 2 (1,3,5 by Arduino 1)
Servo esc6;


int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  esc2.attach(2);
  esc4.attach(4);
  esc6.attach(6);  // attaches the servo on pin 4 to the servo object

  esc2.writeMicroseconds(1000);
  esc4.writeMicroseconds(1000); //initialise to 1000
  esc6.writeMicroseconds(1000);
  
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);     // scale it to use it with the servo (value between 0 and 180)
  esc2.writeMicroseconds(val);
  esc4.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  esc6.writeMicroseconds(val);

  //delay(15);                           // waits for the servo to get there
}

