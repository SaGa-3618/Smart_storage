int array_ht[15]=0;
int array_loc[15]=0;
String array_name[15];
int i=0;
int covered=0;
int num=0;
int flag=1;

void setup()
{
  Serial.begin(9600);
  delay(100);                                   // Let serial start up...
}

void loop()
{  if(flag==1){
  Serial.println("\nPlease enter Object name: ");
  while(Serial.available() == 0) {              // Wait for user input
  }
  array_name[i] = Serial.readString();
    
  Serial.println("What is ht? ");
  while(Serial.available() == 0) {
  }
  array_ht[i] = Serial.parseInt();
  covered += array_ht[i];
  array_loc[i] = 40-covered;
 
  Serial.println();
  Serial.println("------------------------------------------------------------");
  Serial.print("Hello ");         Serial.println(array_name[i]);
    Serial.print("with hieght: ");         Serial.println(array_ht[i]);  
  Serial.print("Location of the object is:- ");       Serial.print(array_loc[i]); 
  
  i++;}
  if (flag==0)
  {
    Serial.println("\nPlease enter Object no: ");
  while(Serial.available() == 0) {              // Wait for user input
  }
  num = Serial.readString()-1;
  Serial.println();
  Serial.println("------------------------------------------------------------");
  Serial.print("Hello ");         Serial.println(array_name[num]);
    Serial.print("with hieght: ");         Serial.println(array_ht[num]);  
  Serial.print("Location of the object is:- ");       Serial.print(array_loc[num]); 
  
  }
  while (flag<3){
   Serial.println();
  Serial.println("-----------------------Enter the choice {1. to store the data 0.Retrive the data 2.Remain idle}---------------------");
  while(Serial.available() == 0) {              // Wait for user input
  }
  flag = Serial.parseInt();
  if(flag>2){Serial.println("Enter the valid input");}}
}
