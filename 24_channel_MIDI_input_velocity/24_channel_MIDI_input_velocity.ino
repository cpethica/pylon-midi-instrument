
//
// MIDI Input Firmware for 24 note MOSFET driver
// 

#include <MIDI.h>  // Midi Library
#include "ShiftRegisterPWM.h"   // shift register control

// USER SETTINGS:
//
const int playtime = 10000;     // set maximum note on time (ms) - auto off safety feature.
const int midi_offset = 60;      // set which note corresponds to the first MOSFET channel
const int lower = 160;          // set lowest power PWM signal sent to MOSFET - so a velocity of 1 can move the solenoid
//
//

#define srCount 3
#define resolution 128
#define ledPin 8

// create a global shift register object 
// (D6 = Serial, D5 = Clock, D7 = Latch)
ShiftRegisterPWM sr(srCount, resolution);

// Create instance for external MIDI input
MIDI_CREATE_DEFAULT_INSTANCE();

//note timers
// store note on or off and note on times
bool notes[24];       // state machine to check if note is on/off
long times[24];       // store last ON time of note

// MIDI input LED
void MIDI_indicator()
{
  digitalWrite(ledPin, LOW);
}

void setup() {
  
  // External MIDI input handlers
  MIDI.setHandleNoteOn(MIDINoteOn); // call Note On function - this does MIDI to DMX conversion
  MIDI.setHandleNoteOff(MIDINoteOff); // call Note Off function - could ditch and replace with timer on MEGA???
  MIDI.begin(MIDI_CHANNEL_OMNI); // Set MIDI channel, MIDI_CHANNEL_OMNI = all, number = channel 

  pinMode(ledPin, OUTPUT);
  pinMode(2, OUTPUT); // sr data pin
  pinMode(3, OUTPUT); // sr clock pin
  pinMode(4, OUTPUT); // sr latch pin
  
  sr.interrupt(ShiftRegisterPWM::UpdateFrequency::Medium);

// start by turning all notes off
  for (int i=0; i < 24; i++) {
     sr.set(i, LOW);    
  }
}

void loop() { // Main loop
  
  // process MIDI from external sources - may need to be called elsewhere to avoid MIDI data being blocked by other functions
  MIDI.read();
  // check notes haven't been on too long
  timers();

} 

// function to prevent note remaining on for longer than max specified
void timers()
{
  // note off timers - switch off note after defined time
  long current = millis();
  for (int i=0; i < 24; i++) {
    // check if note is on first and then how long its been on for
    if (notes[i] == true && current - times[i] > playtime) {
     // turn note off
     sr.set(i, LOW);
     // reset state of note
     notes[i] = false; 
    }
  }
}

void MIDINoteOn(byte channel, byte pitch, byte velocity) { 
  
  digitalWrite(ledPin, HIGH);
  int vel = map(velocity, 1, 127, lower, 255);
  
switch (pitch) {
    case midi_offset:
    times[0] = millis();
    notes[0] = true;
    sr.set(0, vel);   
      break;
    case midi_offset+1:
    times[1] = millis();
    notes[1] = true; 
    sr.set(1, vel);
      break;
    case midi_offset+2:
    times[2] = millis();
    notes[2] = true;
    sr.set(2, vel);
      break;
    case midi_offset+3:
    times[3] = millis();
    notes[3] = true;
    sr.set(3, vel); 
      break;
    case midi_offset+4:
    times[4] = millis();
    notes[4] = true;
    sr.set(4, vel); 
      break;
    case midi_offset+5:
    times[5] = millis();
    notes[5] = true;
    sr.set(5, vel);  
      break;
    case midi_offset+6:
    times[6] = millis();
    notes[6] = true;
    sr.set(6, vel);   // midi values are 0-127 so multiply by 2 to get DMX value (0-255)
      break;
    case midi_offset+7:
    times[7] = millis();
    notes[7] = true;
    sr.set(7, vel);
      break;
    case midi_offset+8:
    times[8] = millis();
    notes[8] = true;
    sr.set(8, vel); 
      break;
    case midi_offset+9:
    times[9] = millis();
    notes[9] = true;
    sr.set(9, vel); 
      break;
    case midi_offset+10:
    times[10] = millis();
    notes[10] = true;
    sr.set(10, vel); 
      break;
    case midi_offset+11:
    times[11] = millis();
    notes[11] = true;
    sr.set(11, vel); 
      break;
    case midi_offset+12:
    times[12] = millis();
    notes[12] = true;
    sr.set(12, vel);
      break;
    case midi_offset+13:
    times[13] = millis();
    notes[13] = true;
    sr.set(13, vel);
      break;
    case midi_offset+14:
    times[14] = millis();
    notes[14] = true;
    sr.set(14, vel);
      break;
    case midi_offset+15:
    times[15] = millis();
    notes[15] = true;
    sr.set(15, vel); 
      break;
    case midi_offset+16:
    times[16] = millis();
    notes[16] = true;
    sr.set(16, vel); 
      break;
    case midi_offset+17:
    times[17] = millis();
    notes[17] = true;
    sr.set(17, vel);
      break;
    case midi_offset+18:
    times[18] = millis();
    notes[18] = true;
    sr.set(18, vel);
      break;
    case midi_offset+19:
    times[19] = millis();
    notes[19] = true; 
    sr.set(19, vel);
      break;
    case midi_offset+20:
    times[20] = millis();
    notes[20] = true;
    sr.set(20, vel);
      break;
    case midi_offset+21:
    times[21] = millis();
    notes[21] = true;
    sr.set(21, vel); 
      break;
    case midi_offset+22:
    times[22] = millis();
    notes[22] = true;
    sr.set(22, vel); 
      break;
    case midi_offset+23:
    times[23] = millis();
    notes[23] = true;
    sr.set(23, vel);
      break;         
  }
} // void MIDINoteOn


void MIDINoteOff(byte channel, byte pitch, byte velocity) { 

    digitalWrite(ledPin, LOW);

switch (pitch) {
    case midi_offset:
    sr.set(0, LOW);   
      break;
    case midi_offset+1:  
    sr.set(1, LOW);
      break;
    case midi_offset+2:
    sr.set(2, LOW);
      break;
    case midi_offset+3:
    sr.set(3, LOW); 
      break;
    case midi_offset+4:
    sr.set(4, LOW); 
      break;
    case midi_offset+5:
    sr.set(5, LOW);  
      break;
    case midi_offset+6:
    sr.set(6, LOW);
      break;
    case midi_offset+7:
    sr.set(7, LOW);
      break;
    case midi_offset+8:
    sr.set(8, LOW); 
      break;
    case midi_offset+9:
    sr.set(9, LOW); 
      break;
    case midi_offset+10:
    sr.set(10, LOW); 
      break;
    case midi_offset+11:
    sr.set(11, LOW); 
      break;
    case midi_offset+12:
    sr.set(12, LOW);
      break;
    case midi_offset+13:
    sr.set(13, LOW);
      break;
    case midi_offset+14:
    sr.set(14, LOW);
      break;
    case midi_offset+15:
    sr.set(15, LOW); 
      break;
    case midi_offset+16:
    sr.set(16, LOW); 
      break;
    case midi_offset+17:
    sr.set(17, LOW);
      break;
    case midi_offset+18:
    sr.set(18, LOW);
      break;
    case midi_offset+19:
    sr.set(19, LOW);
      break;
    case midi_offset+20:
    sr.set(20, LOW);
      break;
    case midi_offset+21:
    sr.set(21, LOW); 
      break;
    case midi_offset+22:
    sr.set(22, LOW); 
      break;
    case midi_offset+23:
    sr.set(23, LOW);
      break;           
  }  
} // void MIDINoteOff
