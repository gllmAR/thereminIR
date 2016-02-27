int raw0;           // for raw sensor values 
int raw1;  
int raw2;  

void setup()
{
  Serial.begin(9600);
  Serial.println("start ");
}




void loop()
{ 
  
   raw0 = analogRead(0); 
   raw1 = analogRead(1);
   raw2 = analogRead(2);  

      Serial.print(raw0);
      Serial.print(" ");
      Serial.print(raw1);
      Serial.print(" ");
      Serial.println(raw2);
      delay(30); 

}



