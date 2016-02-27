#define NUMSENSOR 3
#define OVERSAMPLING 100

int raw[NUMSENSOR];                // initialize a array for raw values 
float smoothedVal[NUMSENSOR];      // initialize a float array for smooth values
int cooked[NUMSENSOR];             // initialize a array for ready to serve values 
int lastCooked[NUMSENSOR];         // initialize a array for last ready to serve values 
int minimum [] = {90,  90,  90, }; // set minimum per sensor 
int maximum [] = {512, 512, 512,}; // set maximum per sensor

float filterVal = .9;       // this determines smoothness  - .0001 is max  1 is off (no smoothing)

void setup(){

}

void loop()

// ADC Oversampling and Smoothing
{ 
  for (int i = 0; i < OVERSAMPLING; i++){  
    for (int j = 0; j < NUMSENSOR; j++){
      smoothedVal[j] = smooth( analogRead(j), filterVal, smoothedVal[j]);
    }
  }

  // Constrain and map value to midi spectrum

  for (int j = 0; j < NUMSENSOR; j++){
    cooked[j] = (int (constrain (map ( smoothedVal[j], minimum[j], maximum[j], 0, 127), 0, 127 )));

    if (cooked[j] != lastCooked[j]) {
      controlChange(0, j, cooked[j]);  
      lastCooked[j] = cooked[j];
    }
  }
  MIDIUSB.flush();
  delay(1);
}


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

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
  MIDIEvent event = {
    0x0B, 0xB0 | channel, control, value  };
  MIDIUSB.write(event);
}


