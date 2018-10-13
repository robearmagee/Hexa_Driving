/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

// ++++++ ARDUINO #1 ++++++ UNO ++++++

#include <Servo.h>
//#include <ESC.h>

#define LED_PIN (13)
#define POT_PIN (A0) //Analog pin used to connect the potentiometer

//Create the 4 esc objects
Servo esc1;  // create servo object to control a servo
Servo esc3;  // 1, 3, 5 are driven by Arduino 1 (2,4,6 by Arduino 2)
Servo esc5;


//ESC myESC_1 (3, 1000, 2000, 500); // ESC_Name (PIN, Minimum Value, Maximum Value, Arm Value)
//ESC myESC_3 (5, 1000, 2000, 500);
//ESC myESC_5 (6, 1000, 2000, 500);

//int potpin = 0;  // analog pin used to connect the potentiometer
int escPin1 = 3;
int escPin3 = 5;
int escPin5 = 6;
int minPulseRate = 1000;
int maxPulseRate = 2000;
int throttleChangeDelay = 50;

int val;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500);

  initEscs();
  //esc1.attach(3);
  //esc3.attach(5);
  //esc5.attach(6);  // attaches the servo on pin 6 to the servo object

  //esc1.writeMicroseconds(1000);
  //esc3.writeMicroseconds(1000); //initialise to 1000
  //esc5.writeMicroseconds(1000);

  //pinMode(LED_PIN, OUTPUT);             // LED Visual Output
  //myESC_1.arm();                          // Send the Arm value
  //myESC_3.arm();
  //myESC_5.arm();
  //digitalWrite(LED_PIN, HIGH);          // LED High Once Armed
  delay(5000);                          // Wait for a while
  
}

void loop() {
  val = analogRead(POT_PIN);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);     // scale it to use it with the servo (value between 0 and 180)
  
  //int throttle = normaliseThrottle(val);
  //changeThrottle(throttle);
  writeTo3Escs(val);
  
  //esc1.writeMicroseconds(val);
  //esc3.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  //esc5.writeMicroseconds(val);

  //myESC_1.speed(val);
  //myESC_3.speed(val);
  //myESC_5.speed(val);
  //delay(5);

  delay(15);                           // waits for the servo to get there
}



//Change throttle value
//void changeThrottle(int throttle) {
 // int currentThrottle = readThrottle();
  
 // int step = 1;
  //if(throttle < currentThrottle) {
 //   step = -1;
 // }
  
  // Slowly move to the new throttle value 
 // while(currentThrottle != throttle) {
 //   writeTo4Escs(currentThrottle + step);
    
 //   currentThrottle = readThrottle();
  //  delay(throttleChangeDelay);
 // }
//}


//Change velocity of the 4 escs at the same time
void writeTo3Escs(int throttle) {
  esc1.write(throttle);
  esc3.write(throttle);
  esc5.write(throttle);
}


//Init escs
void initEscs() {
  esc1.attach(escPin1, minPulseRate, maxPulseRate);
  esc3.attach(escPin3, minPulseRate, maxPulseRate);
  esc5.attach(escPin5, minPulseRate, maxPulseRate);
  
  
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

