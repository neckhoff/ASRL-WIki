int PUL1 = 1;
int DIR1 = 0;
int PUL2 = 3;
int DIR2 = 2;
int PUL3 = 5;
int DIR3 = 4;
int PUL4 = 7;
int DIR4 = 6;
int PUL5 = 9;
int DIR5 = 8;
int PUL6 = 11;
int DIR6 = 10;

int LIM1 = 26;
int LIM2 = 27;
int LIM3 = 28;
int LIM4 = 29;
int LIM5 = 30;
int LIM6 = 32;


int motors[6][3] = {{PUL1, DIR1, LIM1}, {PUL2, DIR2, LIM2}, {PUL3, DIR3, LIM3}, {PUL4, DIR4, LIM4}, {PUL5, DIR5, LIM5}, {PUL6, DIR6, LIM6}};

//steps per degree
double motorSpeedConstants[6] = {1,1,1,1,1,1};

//100 ticks per second (10000 microseconds per sample period)
const double globaltickrate = 1;

//motor speed = degrees/second change (now steps/second)
//0.09 deg/step = 11.111 steps per degree
void drive(int motor, int direction, double s1, double s2){
  
  double speed1 = s1 * motorSpeedConstants[motor-1];
  double speed2 = s2 * motorSpeedConstants[motor-1];

  double motor_period = (1/globaltickrate);

  double avgspeed = (speed1 + speed2)/2;
  double stepsavg =  motor_period * avgspeed;
  double steps1 = motor_period * speed1;
  double steps2 = motor_period * speed2;

  double startdelay = motor_period/steps1;
  double stopdelay = motor_period/steps2;

  double speedgradient = (stopdelay - startdelay)/stepsavg;


  for(double i = 0; i < stepsavg; i++){

      if(digitalRead(motors[motor-1][2]) == LOW){
      
      //Serial.print(startdelay, 20);
      //Serial.print("\n");
      //Serial.print(speedgradient, 20);
      //Serial.print("\n");

      double delay = (startdelay + (speedgradient * i)) * 1000000;
      
      digitalWrite(motors[motor-1][1], direction);
      digitalWrite(motors[motor-1][0], HIGH);
      delayMicroseconds(delay - 1000);
      digitalWrite(motors[motor-1][0], LOW);
      delayMicroseconds(1000);

      }
  }
}

void setup() {

  Serial.begin(9600);
  
pinMode(PUL1, OUTPUT);
pinMode(DIR1, OUTPUT);
pinMode(LIM1, INPUT_PULLUP);

pinMode(PUL2, OUTPUT);
pinMode(DIR2, OUTPUT);
pinMode(LIM2, INPUT_PULLUP);

pinMode(PUL3, OUTPUT);
pinMode(DIR3, OUTPUT);
pinMode(LIM3, INPUT_PULLUP);

pinMode(PUL4, OUTPUT);
pinMode(DIR4, OUTPUT);
pinMode(LIM4, INPUT_PULLUP);

pinMode(PUL5, OUTPUT);
pinMode(DIR5, OUTPUT);
pinMode(LIM5, INPUT_PULLUP); 

pinMode(PUL6, OUTPUT);
pinMode(DIR6, OUTPUT);
pinMode(LIM6, INPUT_PULLUP);

}

void loop() {
    // read incoming serial data:
    //drive(1, HIGH, 10, 200);

    if(Serial.available()){
    char inChar = Serial.read();

    if(inChar > 0){
  //motor 1
      if(inChar == 'q'){
        drive(1, HIGH, 200, 200);
      }
      if(inChar == 'a'){
        drive(1, LOW, 200, 200);
      }
  //motor 2
      if(inChar == 'w'){
        drive(2, HIGH, 200, 200);
      }
      if(inChar == 's'){
        drive(2, LOW, 200, 200);
      }
  //motor 3
      if(inChar == 'e'){
        drive(3, HIGH, 200, 200);
      }
      if(inChar == 'd'){
        drive(3, LOW, 200, 200);
      }
  //motor 4
      if(inChar == 'r'){
        drive(4, HIGH, 200, 200);
      }
      if(inChar == 'f'){
        drive(4, LOW, 200, 200);
      }
  //motor 5
      if(inChar == 't'){
        drive(5, HIGH, 200, 200);
      }
      if(inChar == 'g'){
        drive(5, LOW, 200, 200);
      }
  //motor 6
      if(inChar == 'y'){
        drive(6, HIGH, 100, 100);
      }
      if(inChar == 'h'){
        drive(6, LOW, 100, 100);
      }
    }
}

}
