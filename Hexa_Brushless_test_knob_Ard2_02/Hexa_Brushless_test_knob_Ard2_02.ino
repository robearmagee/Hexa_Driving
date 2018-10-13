/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

// ++++++ ARDUINO #2 ++++++ NANO +++++++

#include <Servo.h>
//#include <ESC.h>

#define LED_PIN (13)
#define POT_PIN (A0) //Analog pin used to connect the potentiometer

Servo esc2;  // create servo object to control a servo
Servo esc4;  // 2, 4, 6 are driven by Arduino 2 (1,3,5 by Arduino 1)
Servo esc6;

//ESC myESC_2 (9, 1000, 2000, 500); // ESC_Name (PIN, Minimum Value, Maximum Value, Arm Value)
//ESC myESC_4 (10, 1000, 2000, 500);
//ESC myESC_6 (11, 1000, 2000, 500);

// int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int escPin2 = 9;
int escPin4 = 10;
int escPin6 = 11;
int minPulseRate = 1000;
int maxPulseRate = 2000;
int throttleChangeDelay = 50;

void setup() { // attaches the servo on pin 11 to the servo object
  initEscs();
  //esc2.attach(9);   // 2 = Green
  //esc4.attach(10);  // 4 = Green stripe
  //esc6.attach(11);  // 6 = Orange stripe

  //esc2.writeMicroseconds(1000);
  //esc4.writeMicroseconds(1000); //initialise to 1000
  //esc6.writeMicroseconds(1000);
  
  //Serial.begin(9600);
  //pinMode(LED_PIN, OUTPUT);             // LED Visual Output
  //myESC_2.arm();                          // Send the Arm value
  //myESC_4.arm();
  //myESC_6.arm();
  //digitalWrite(LED_PIN, HIGH);          // LED High Once Armed
  delay(5000);                          // Wait for a while
}

void loop() {
  val = analogRead( POT_PIN );            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);     // scale it to use it with the servo (value between 0 and 180)
  
  writeTo3Escs(val);
  //myESC_2.speed(val);
  //myESC_4.speed(val);
  //myESC_6.speed(val);
  
  delay(15);
  
  //esc2.writeMicroseconds(val);
  //esc4.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  //esc6.writeMicroseconds(val);

  //delay(15);                           // waits for the servo to get there
}


//Change velocity of the 4 escs at the same time
void writeTo3Escs(int throttle) {
  esc2.write(throttle);
  esc4.write(throttle);
  esc6.write(throttle);
}


//Init escs
void initEscs() {
  esc2.attach(escPin2, minPulseRate, maxPulseRate);
  esc4.attach(escPin4, minPulseRate, maxPulseRate);
  esc6.attach(escPin6, minPulseRate, maxPulseRate);
  
  //Init motors with 0 value
  writeTo3Escs(0);
}

//Start the motors
void startUpMotors() {
  writeTo3Escs(50);
}

// Ensure the throttle value is between 0 - 180
int normalizeThrottle(int value) {
  if(value < 0) {
    return 0;
    
  } else if(value > 180) {
    return 180;
  }
  
  return value;
}








