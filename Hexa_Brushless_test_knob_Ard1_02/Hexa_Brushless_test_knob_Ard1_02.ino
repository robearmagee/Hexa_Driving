/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo esc2;
Servo esc3;  // create servo object to control a servo
Servo esc4;
Servo esc5;


int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  esc2.attach(2);
  esc3.attach(3);
  esc4.attach(4);  // attaches the servo on pin 4 to the servo object
  esc5.attach(5);

  esc2.writeMicroseconds(1000);
  esc3.writeMicroseconds(1000); //initialise to 1000
  esc4.writeMicroseconds(1000);
  esc5.writeMicroseconds(1000);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);     // scale it to use it with the servo (value between 0 and 180)
  esc2.writeMicroseconds(val);
  esc3.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  esc4.writeMicroseconds(val);
  esc5.writeMicroseconds(val);
  //delay(15);                           // waits for the servo to get there
}

