
  int timer;
  int capacity =10;
  int array[10];
  int i=0;
  int overload=0;
  
void setup()
{
  // put your setup code here, to run once:
    Serial.begin(9600);
      delay(100);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (overload==0){
    array[i]=i*3;
    delay(timer);
    capacity=capacity-1;
    i++;
  }
  
  if (capacity==0){
  overload=1;
  
  }
  if (overload==1){
    
    Serial.print(array[capacity]);
    capacity=capacity+1;
    Serial.println();
    if(capacity==11)
    {
      overload=0;
    }
    
  }
  
  
}
