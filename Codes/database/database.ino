#include <Servo.h> 
Servo myservo; 

int array_ht[15]={0};
int array_loc[15]={0};
String array_name[15];
int i=0;
int covered=0;
int num=0;
int flag=1;
int count=0;
int pos = 0;    // variable to store the servo position 
int tray=0; 

void setup()
{
  Serial.begin(9600);
  delay(100);  // Let serial start up...
  myservo.attach(5);

}

void loop()
{  if(flag==1){
  Serial.println("\nPlease enter Object name: ");
  while(Serial.available() == 0) {              // Wait for user input
  }
  array_name[i] = Serial.readString();
    
  Serial.println("Hieght: ");
  while(Serial.available() == 0) {
  }
  array_ht[i] = Serial.parseInt();
  covered += array_ht[i];
  array_loc[i] = 40-covered;
  count++;
  Serial.println();
  Serial.println("------------------------------------------------------------");
  Serial.print("Object name: ");         Serial.print(array_name[i]);
  Serial.print("with hieght: ");         Serial.print(array_ht[i]);  
  Serial.print("Location of the object is: ");       Serial.print(array_loc[i]); 
  Serial.println();
  
  i++;}
  if (flag==0)
  {
    Serial.println("\nPlease enter Object no: ");
  while(Serial.available() == 0) {              // Wait for user input
  }
  num = Serial.parseInt()-1;
  Serial.println();
  Serial.println("------------------------------------------------------------");
  Serial.print("Object Name: ");         Serial.print(array_name[num]);
    Serial.print("with hieght: ");         Serial.print(array_ht[num]);  
  Serial.print("Location of the object is: ");       Serial.print(array_loc[num]); 
  Serial.println();
  array_name[num]="/0";
  array_ht[num]=0;
  
  array_loc[num]=0;  
  count--;
  Serial.println("Object Retrieved!");
  }
  
  while (flag<4){
    
   Serial.println();
   Serial.println("  No. of object in shelf:");
   Serial.print(count);
  Serial.println("-----------------------Enter the choice {1. to store the data 0.Retrive the data 2.Remain idle3.To get list of the objects present}---------------------");
  while(Serial.available() == 0) {              // Wait for user input
  }
  flag = Serial.parseInt();
  if(flag>3){Serial.println("Enter the valid input");}}
  if(flag==3){
    for (int j=0;j<=i;j++)
    {
      Serial.print("Object name: ");         Serial.println(array_name[j]);
      Serial.print("with hieght: ");         Serial.println(array_ht[j]);  
      Serial.print("Location of the object is: ");       Serial.print(array_loc[j]); 
      delay(100);
    }
  }
  
  
  if(tray==0)
  {
  for(pos = 0; pos < 143; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  tray=1;
  }
 else{ 
  for(pos = 143; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
 tray=0; 
 }
delay(500);
}
