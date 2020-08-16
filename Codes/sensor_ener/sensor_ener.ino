#include <Stepper.h>

const int pingPin = P2_2; //trigger
const int pingReceive = P2_3; //Echo
const int Push_button= P2_1; // to start object detection
int no_of_steps;
int obj_ht;
int dir;
int step_length;
int deg;
int radius;



const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
                                     // for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

int stepCount = 0;         // number of steps the motor has taken
void setup() {
 // initialize serial communication:
 Serial.begin(9600);   
}

void loop()
{
 // establish variables for duration of the ping, 
 // and the distance result in inches and centimeters:
 long duration, obj_ht, cm;
 pinMode(Push_button,INPUT);

 // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 if (Push_button == HIGH){
  pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(5);
   digitalWrite(pingPin, LOW);

 // The same pin is used to read the signal from the PING))): a HIGH
 // pulse whose duration is the time (in microseconds) from the sending
 // of the ping to the reception of its echo off of an object.
 pinMode(pingReceive, INPUT);
 duration = pulseIn(pingReceive, HIGH);

 // convert the time into a distance
 cm = microsecondsToCentimeters(duration);
 }
 obj_ht = 26 -ceil(cm);
 Serial.print("object hieght, ");
 Serial.print(obj_ht);
  Serial.print(cm);
 Serial.print("cm");
 Serial.println();
 

 
 step_length = deg*2*3.14*radius/360; // 1.8 deg for general stepper motor
 no_of_steps = ceil(obj_ht/step_length)+1;
 Serial.print("no_of_steps");
 Serial.print(no_of_steps); 


 motion (dir,no_of_steps);

 delay(100);
}

 void motion(int dir, int no_of_steps){
  if (dir == 1)      // UP
  {
    for(int i = no_of_steps; i>=0; i--){
     myStepper.step(1);
  }
  }
  if (dir == 0)      // DOWN
  {
    for(int i = no_of_steps; i>=0; i--){
     myStepper.step(-1);
  }
  }
 }

// https://forum.43oh.com/topic/9207-serial-reading-strings/ serial input


long microsecondsToCentimeters(long microseconds)
{
 // The speed of sound is 340 m/s or 29 microseconds per centimeter.
 // The ping travels out and back, so to find the distance of the
 // object we take half of the distance travelled.
 return microseconds / 29 / 2;
}
