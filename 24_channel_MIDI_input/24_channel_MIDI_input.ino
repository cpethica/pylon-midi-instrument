// HIVE - 24 note solenoid gamelan
//

// MIDI Input Firmware
// 

#include <MIDI.h>  // Midi Library
//#include "ShiftRegisterPWM.h"   // shift register control
#include <ShiftRegister74HC595.h>

#define srCount 3
#define resolution 128
#define ledPin 8

// create a global shift register object 
// (D6 = Serial, D5 = Clock, D7 = Latch)
//ShiftRegisterPWM sr(srCount, resolution);
ShiftRegister74HC595 sr (3, 2, 3, 4);

// Create instance for external MIDI input
MIDI_CREATE_DEFAULT_INSTANCE();

// note timers - set maximum on time to prevent solenoid/transistor damage
const long safety = 1500;     // maximum on time for any output is 1.5 seconds
unsigned long note[26];


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
}

void loop() { // Main loop
  
  // process MIDI from external sources - may need to be called elsewhere to avoid MIDI data being blocked by other functions
  MIDI.read();
  //check for MIDI// note off timers - safety feature to stop solenoids getting stuck on
//  unsigned long current = millis();
//  for (int i=0; i <= 25; i++) {
//    if (current - note[i] >= safety) {
//     // save the last time note was on 
//     note[i] = current;
//     // set note off
//     sr.set(i, 0);   
//     }
//  }
} 

void MIDINoteOn(byte channel, byte pitch, byte velocity) { 
//void MIDINoteOn(byte channel, byte pitch, byte velocity) { 
  
  digitalWrite(ledPin, HIGH);
  
switch (pitch) {
    case 60:
    note[pitch] = millis();
    sr.set(0, HIGH);   
      break;
    case 61:
    note[pitch] = millis();    
    sr.set(1, HIGH);
      break;
    case 62:
    note[pitch] = millis(); 
    sr.set(2, HIGH);
      break;
    case 63:
    note[pitch] = millis(); 
    sr.set(3, HIGH); 
      break;
    case 64:
    note[pitch] = millis(); 
    sr.set(4, HIGH); 
      break;
    case 65:
    note[pitch] = millis(); 
    sr.set(5, HIGH);  
      break;
    case 66:
    note[pitch] = millis(); 
    sr.set(6, HIGH);   // midi values are 0-127 so multiply by 2 to get DMX value (0-255)
      break;
    case 67:
    note[pitch] = millis(); 
    sr.set(7, HIGH);
      break;
    case 68:
    note[pitch] = millis(); 
    sr.set(8, HIGH); 
      break;
    case 69:
    note[pitch] = millis(); 
    sr.set(9, HIGH); 
      break;
    case 70:
    note[pitch] = millis(); 
    sr.set(10, HIGH); 
      break;
    case 71:
    note[pitch] = millis(); 
    sr.set(11, HIGH); 
      break;
    case 72:
    note[pitch] = millis(); 
    sr.set(12, HIGH);
      break;
    case 73:
    note[pitch] = millis(); 
    sr.set(13, HIGH);
      break;
    case 74:
    note[pitch] = millis(); 
    sr.set(14, HIGH);
      break;
    case 75:
    note[pitch] = millis(); 
    sr.set(15, HIGH); 
      break;
    case 76:
    note[pitch] = millis(); 
    sr.set(16, HIGH); 
      break;
    case 77:
    note[pitch] = millis(); 
    sr.set(17, HIGH);
      break;
    case 78:
    note[pitch] = millis(); 
    sr.set(18, HIGH);
      break;
    case 79:
    note[pitch] = millis(); 
    sr.set(19, HIGH);
      break;
    case 80:
    note[pitch] = millis(); 
    sr.set(20, HIGH);
      break;
    case 81:
    note[pitch] = millis(); 
    sr.set(21, HIGH); 
      break;
    case 82:
    note[pitch] = millis(); 
    sr.set(22, HIGH); 
      break;
    case 83:
    note[pitch] = millis(); 
    sr.set(23, HIGH);
      break;         
  }


} // void MIDINoteOn


void MIDINoteOff(byte channel, byte pitch, byte velocity) { 

switch (pitch) {
    case 60:
    note[pitch] = millis();
    sr.set(0, LOW);   
      break;
    case 61:
    note[pitch] = millis();    
    sr.set(1, LOW);
      break;
    case 62:
    note[pitch] = millis(); 
    sr.set(2, LOW);
      break;
    case 63:
    note[pitch] = millis(); 
    sr.set(3, LOW); 
      break;
    case 64:
    note[pitch] = millis(); 
    sr.set(4, LOW); 
      break;
    case 65:
    note[pitch] = millis(); 
    sr.set(5, LOW);  
      break;
    case 66:
    note[pitch] = millis(); 
    sr.set(6, LOW);   // midi values are 0-127 so multiply by 2 to get DMX value (0-255)
      break;
    case 67:
    note[pitch] = millis(); 
    sr.set(7, LOW);
      break;
    case 68:
    note[pitch] = millis(); 
    sr.set(8, LOW); 
      break;
    case 69:
    note[pitch] = millis(); 
    sr.set(9, LOW); 
      break;
    case 70:
    note[pitch] = millis(); 
    sr.set(10, LOW); 
      break;
    case 71:
    note[pitch] = millis(); 
    sr.set(11, LOW); 
      break;
    case 72:
    note[pitch] = millis(); 
    sr.set(12, LOW);
      break;
    case 73:
    note[pitch] = millis(); 
    sr.set(13, LOW);
      break;
    case 74:
    note[pitch] = millis(); 
    sr.set(14, LOW);
      break;
    case 75:
    note[pitch] = millis(); 
    sr.set(15, LOW); 
      break;
    case 76:
    note[pitch] = millis(); 
    sr.set(16, LOW); 
      break;
    case 77:
    note[pitch] = millis(); 
    sr.set(17, LOW);
      break;
    case 78:
    note[pitch] = millis(); 
    sr.set(18, LOW);
      break;
    case 79:
    note[pitch] = millis(); 
    sr.set(19, LOW);
      break;
    case 80:
    note[pitch] = millis(); 
    sr.set(20, LOW);
      break;
    case 81:
    note[pitch] = millis(); 
    sr.set(21, LOW); 
      break;
    case 82:
    note[pitch] = millis(); 
    sr.set(22, LOW); 
      break;
    case 83:
    note[pitch] = millis(); 
    sr.set(23, LOW);
      break;           
  }
  
      
} // void MIDINoteOff
