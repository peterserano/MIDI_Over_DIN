// Simple MIDI over DIN Example Code for Arduino
// Peter Serano - March 15, 2019 - www.rocknrepair.com

// Include files for your specific microcontroller hardware:
#include <Adafruit_CircuitPlayground.h>


void setup() {

  //Initialize MIDI OVER DIN: where 'Serial1' is your UART
  Serial1.begin(31250);  
  
}

// Functions:

// NoteOn
void noteOnDIN(int channel, int pitch, int velocity) {
  Serial1.write(0x90 | channel);
  Serial1.write(pitch);
  Serial1.write(velocity);
}

// NoteOff
void noteOffDIN(int channel, int pitch, int velocity) {
  Serial1.write(0x80 | channel);
  Serial1.write(pitch);
  Serial1.write(velocity);
}

// Control Change
void controlChangeDIN(int channel, int control, int value) {
  Serial1.write(0xB0 | channel);
  Serial1.write(control);
  Serial1.write(value);
}

// Pitch Bend ('value' ranges from -8192 to 8192)
void pitchBendChangeDIN(byte channel, int value) {
  byte lowValue = value & 0x7F;
  byte highValue = value >> 7;
  Serial1.write(0xE0 | channel);
  Serial1.write(lowValue);
  Serial1.write(highValue);

}


// Init Variables:
int note = 60; // Middle C
int vol = 127; // Volume set at max (ranges from 0 to 127)
int channel = 0; // MIDI Channel 1


// Main Code: Play Middle C, Wait, Turn Off Note, Wait, Repeat
void loop() { 

    noteOnDIN(channel,note,vol);
    delay(150);
    noteOffDIN(channel,note,vol);
    delay(150); 
    
}
