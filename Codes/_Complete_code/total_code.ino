
#include<Stepper.h>
  const int triggerPin = P2_2;
  const int echoPin = P2_3;
  const int Push_button= PUSH2;
  const int Motor = P6_5;
  int buttonState = 0;
  int motorState = 0;
  const int DIRECTION= PUSH1;
  int dirState = 0;
  int no_of_steps;
  int obj_ht;
  int dir;
  int step_length;
  int deg;
  int radius;
  static int n=0;
  int i;
  int state;
  int p=2;
  static int a=0;
  int flag=0;
  
  
const int stepsPerRevolution = 200;
  
Stepper myStepper(stepsPerRevolution,8,9,10,11);
  
void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
   pinMode(triggerPin, OUTPUT); 
   pinMode(RED_LED, OUTPUT); 
   pinMode(GREEN_LED, OUTPUT); 
   pinMode(echoPin, INPUT);
   pinMode(Push_button, INPUT_PULLUP);
   pinMode(Motor, INPUT_PULLUP);
   pinMode(DIRECTION, INPUT_PULLUP);

}

void loop()
{
if(flag==0){
  if(a<=20){
  Serial.println("Choose state : 0 for storage ");
  Serial.println("             : 1 for retrival");

  if (Serial.available() >0){
  state = (Serial.read()-48);
  }
  Serial.print("state =");
  Serial.println(state);
   delay(50);
  Serial.println("input done");
  a=a+1;
}
else{flag=1;}
}
  
  
if(flag==1){

  if(digitalRead(state)== 0)      //storage
  {        
    
  long duration, cm;
  buttonState= digitalRead (Push_button);
  motorState= digitalRead (Motor);
  
   if(n<=25){                                 //IF LOOOP
   digitalWrite(triggerPin, LOW);
   delayMicroseconds(2);
   digitalWrite(triggerPin, HIGH);
   delayMicroseconds(5);
   digitalWrite(triggerPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   
   
   if(buttonState == LOW){
     cm= duration*0.034/2; 
     static int no_of_steps =0;
  
     if(cm<=10) {
     Serial.print(10-cm);
     Serial.print("cm");
     Serial.println();
  }
  else{
     Serial.print("No object found!");
     Serial.println();
  }
   }
   
   
 dirState= digitalRead(DIRECTION);
 
 
 if (dirState== LOW){
    obj_ht=10-cm;
    step_length = 1;
    no_of_steps =((40-(obj_ht+1))/step_length)+1;

    Serial.print("no_of_steps");
    Serial.println(no_of_steps); 

    Serial.println();
    digitalWrite(Motor, LOW);
 
  }
   }
   
   n=n+1;
  if ((dirState== LOW)){
    if((n>25)){
       Serial.print("Stepper started with data(cm, no of steps):- ");
       Serial.println(no_of_steps);
       Serial.print("    ");
       Serial.print(obj_ht);
       Serial.println();
          digitalWrite(RED_LED, HIGH);
  
          motionUp();                                     //calling function to go up
          if (i==0) motionFloat();
          if (p==0) motionDown();
 
    digitalWrite(Motor, HIGH);
    if((n-no_of_steps)>75 ){n=0;}
    }
 }
 
  delay(450);
  }}
   
}


//functions

 void motionUp(){
   
  if(motorState== LOW){
 //motion (1,no_of_steps);
   Serial.println("MOTOR STARTED");
   Serial.println();
   i=no_of_steps;
 }
  if (i>0)      // UP
  {
       // for(int i = no_of_steps; i>=0; i--){
      myStepper.setSpeed(100);
      myStepper.step(200);
      Serial.println(i);

      //}
   i=i-1;
   digitalWrite(RED_LED, LOW);
     
    
  }
 
 }
 
 void motionFloat(){
   if(p>0){
  myStepper.setSpeed(100);
  myStepper.step(200);
  Serial.println("float");
  p=p-1; 
   }
 }
 
 void motionDown(){
   myStepper.setSpeed(100);
      myStepper.step(-200);
      Serial.println("down");
      Serial.println(i);

   
 }
