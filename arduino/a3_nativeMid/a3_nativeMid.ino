// Native Midi require the installation of arcore 
// download the library and follow the instruction
// https://github.com/rkistner/arcore

float filterVal = .9;       // this determines smoothness  - .0001 is max  1 is off (no smoothing)

int raw0;             // for raw sensor values 
float smoothedVal0;   // this holds the last loop value just use a unique variable for every different sensor that needs smoothing
int cooked0;          // Ready to serve data
int lastCooked0;      // hold the lastest ready to serve data
int minimum0 = 70;    // data minimum for that particular sensor
int maximum0 = 512;   // data maximum for that particular sensor

int raw1;    // for raw sensor values 
int cooked1;
int lastCooked1;
float smoothedVal1;     // this holds the last loop value just use a unique variable for every different sensor that needs smoothing
int minimum1 = 70;
int maximum1 = 512;



int raw2;           // for raw sensor values 
float smoothedVal2;     // this holds the last loop value just use a unique variable for every different sensor that needs smoothing
int cooked2;
int lastCooked2;
int minimum2 = 70;
int maximum2 = 512;




void setup(){

}



void loop()
// oversampling loop
{ 
  for (int i = 0; i < 100; i++){
  
      int raw0 = analogRead(0); 
      int raw1 = analogRead(1); 
      int raw2 = analogRead(2); 

      smoothedVal0 =  smooth(raw0, filterVal, smoothedVal0);   
      smoothedVal1 =  smooth(raw1, filterVal, smoothedVal1);   
      smoothedVal2 =  smooth(raw2, filterVal, smoothedVal2);   

  }
  
  // constrain and map the data
  cooked0 = (int (constrain (map (smoothedVal0, minimum0, maximum0, 0, 127), 0, 127 )));
  cooked1 = (int (constrain (map (smoothedVal1, minimum1, maximum1, 0, 127), 0, 127 )));
  cooked2 = (int (constrain (map (smoothedVal2, minimum2, maximum2, 0, 127), 0, 127 )));
  
  
  // send values to controller only if it has changed 
 
  if (cooked0 != lastCooked0) {
  controlChange(0, 0, cooked0);  
  lastCooked0 = cooked0;
}
 

  if (cooked1 != lastCooked1) {
  controlChange(0, 1, cooked1);  
  lastCooked1 = cooked1;
}
  

  if (cooked2 != lastCooked2) {
  controlChange(0, 2, cooked2);  
  lastCooked2 = cooked2;
}

// Clear midi 

  MIDIUSB.flush();
  
// wait a little 
  delay(1);
  
  
  
}

// smooth function
int smooth(int data, float filterVal, float smoothedVal){


  if (filterVal > 1){      // check to make sure param's are within range
    filterVal = .99;
  }
  else if (filterVal <= 0){
    filterVal = 0;
  }

  smoothedVal = (data * (1 - filterVal)) + (smoothedVal  *  filterVal);

  return (int)smoothedVal;
}




// controlChange function
// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
  MIDIEvent event = {0x0B, 0xB0 | channel, control, value};
  MIDIUSB.write(event);
}

