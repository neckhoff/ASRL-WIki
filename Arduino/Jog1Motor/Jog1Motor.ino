// Lines 1-82 are from Chris Annin Code

// Speed | millisecond multiplier | raise number to slow | Default = 220
const int SpeedMult = 220;

// Motor Direction | CW set to 1 | Default = 111011
const int J1rotdir = 1;
const int J2rotdir = 1;
const int J3rotdir = 1;
const int J4rotdir = 0;
const int J5rotdir = 1;
const int J6rotdir = 1;

// Start Positions (Rest) | Default: J1 = 7600, J2 = 2322, J3 = 0, J4 = 7600, J5 = 2287, J6 = 3312
int J1startSteps = 7600;
int J2startSteps = 2322;
int J3startSteps = 0;
int J4startSteps = 7600;
int J5startSteps = 2287;
int J6startSteps = 3312;

#include <AccelStepper.h>

// Step & Direction Pins on Teensy
const int J1stepPin = 0;
const int J1dirPin = 1;
const int J2stepPin = 2;
const int J2dirPin = 3;
const int J3stepPin = 4;
const int J3dirPin = 5;
const int J4stepPin = 7;
const int J4dirPin = 6;
const int J5stepPin = 8;
const int J5dirPin = 9;
const int J6stepPin = 10;
const int J6dirPin = 11;


// Limit Switch Pins on Teensy
const int J1calPin = 26;
const int J2calPin = 27;
const int J3calPin = 28;
const int J4calPin = 29;
const int J5calPin = 30;
const int J6calPin = 31;

////////////////////////
// Main
////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(J1stepPin, OUTPUT);
  pinMode(J1dirPin, OUTPUT);
  pinMode(J2stepPin, OUTPUT);
  pinMode(J2dirPin, OUTPUT);
  pinMode(J3stepPin, OUTPUT);
  pinMode(J3dirPin, OUTPUT);
  pinMode(J4stepPin, OUTPUT);
  pinMode(J4dirPin, OUTPUT);
  pinMode(J5stepPin, OUTPUT);
  pinMode(J5dirPin, OUTPUT);
  pinMode(J6stepPin, OUTPUT);
  pinMode(J6dirPin, OUTPUT);

  pinMode(J1calPin, INPUT_PULLUP);
  pinMode(J2calPin, INPUT_PULLUP);
  pinMode(J3calPin, INPUT_PULLUP);
  pinMode(J4calPin, INPUT_PULLUP);
  pinMode(J5calPin, INPUT_PULLUP);
  pinMode(J6calPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(J1stepPin, HIGH);
  /*digitalWrite(J2stepPin, HIGH);
  digitalWrite(J3stepPin, HIGH);
  digitalWrite(J4stepPin, HIGH);
  digitalWrite(J5stepPin, HIGH);
  digitalWrite(J6stepPin, HIGH);*/
  // Jog Motor 1
  for (int i=0; i < 500; i++){
    digitalWrite(J1dirPin, HIGH);
    delayMicroseconds(10000);
    digitalWrite(J1dirPin, LOW);
    delayMicroseconds(10000);
  }
  delayMicroseconds(10000);
  digitalWrite(J1stepPin, LOW);

  // Jog Motor 2
  for (int i=0; i < 500; i++){
    digitalWrite(J2dirPin, HIGH);
    delayMicroseconds(10000);
    digitalWrite(J2dirPin, LOW);
    delayMicroseconds(10000);
  }
  delayMicroseconds(10000);
  digitalWrite(J2stepPin, LOW);

  // Jog Motor 3
  for (int i=0; i < 500; i++){
    digitalWrite(J3dirPin, HIGH);
    delayMicroseconds(10000);
    digitalWrite(J3dirPin, LOW);
    delayMicroseconds(10000);
  }
  delayMicroseconds(10000);
  digitalWrite(J3stepPin, LOW);

  // Jog Motor 4
  for (int i=0; i < 500; i++){
    digitalWrite(J4dirPin, HIGH);
    delayMicroseconds(10000);
    digitalWrite(J4dirPin, LOW);
    delayMicroseconds(10000);
  }
  delayMicroseconds(10000);
  digitalWrite(J4stepPin, LOW);

  // Jog Motor 5
  for (int i=0; i < 500; i++){
    digitalWrite(J5dirPin, HIGH);
    delayMicroseconds(10000);
    digitalWrite(J5dirPin, LOW);
    delayMicroseconds(10000);
  }
  delayMicroseconds(10000);
  digitalWrite(J5stepPin, LOW);

  // Jog Motor 6
  for (int i=0; i < 500; i++){
    digitalWrite(J6dirPin, HIGH);
    delayMicroseconds(10000);
    digitalWrite(J6dirPin, LOW);
    delayMicroseconds(10000);
  }
  delayMicroseconds(10000);
  digitalWrite(J6stepPin, LOW);
}
