float filterVal = .9;       // this determines smoothness  - .0001 is max  1 is off (no smoothing)

int raw0;           // for raw sensor values
float smoothedVal0;     // this holds the last loop value just use a unique variable for every different sensor that needs smoothing


int raw1;           // for raw sensor values
float smoothedVal1;     // this holds the last loop value just use a unique variable for every different sensor that needs smoothing




int raw2;           // for raw sensor values
float smoothedVal2;     // this holds the last loop value just use a unique variable for every different sensor that needs smoothing




void setup()
{
  Serial.begin(9600);
  Serial.println("start ");
}




void loop()
{
  for (int i = 0; i < 100; i++) {

    int raw0 = analogRead(0);
    int raw1 = analogRead(1);
    int raw2 = analogRead(2);

    smoothedVal0 =  smooth(raw0, filterVal, smoothedVal0);
    smoothedVal1 =  smooth(raw1, filterVal, smoothedVal1);
    smoothedVal2 =  smooth(raw2, filterVal, smoothedVal2);

  }

  Serial.print(int (smoothedVal0));
  Serial.print(" ");
  Serial.print(int (smoothedVal1));
  Serial.print(" ");
  Serial.println(int (smoothedVal2));


}


int smooth(int data, float filterVal, float smoothedVal) {


  if (filterVal > 1) {     // check to make sure param's are within range
    filterVal = .99;
  }
  else if (filterVal <= 0) {
    filterVal = 0;
  }

  smoothedVal = (data * (1 - filterVal)) + (smoothedVal  *  filterVal);

  return (int)smoothedVal;
}

