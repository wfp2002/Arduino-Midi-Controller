/*
   This examples shows how to make a simple seven keys MIDI keyboard with volume control

   Created: 4/10/2015
   Author: Arturo Guadalupi <a.guadalupi@arduino.cc>
   
   http://www.arduino.cc/en/Tutorial/MidiDevice
*/

//#include "MIDIUSB.h"
#include "notes.h"
#define NUM_BUTTONS  7

const uint8_t button1 = 2;
const uint8_t button2 = 3;
const uint8_t button3 = 4;
const uint8_t button4 = 5;
const uint8_t button5 = 6;
const uint8_t button6 = 7;
const uint8_t button7 = 8;

const int intensityPot = 0;  //A0 input

const uint8_t buttons[NUM_BUTTONS] = {button1, button2, button3, button4, button5, button6, button7};
//const byte notePitches[NUM_BUTTONS] = {C3, D3, E3, F3, G3, A3, B3};
const byte notePitches[NUM_BUTTONS] = {60, 61, 62, 63, 64, 65, 66};

uint8_t notesTime[NUM_BUTTONS];
uint8_t pressedButtons = 0x00;
uint8_t previousButtons = 0x00;
uint8_t intensity;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_BUTTONS; i++)
    pinMode(buttons[i], INPUT_PULLUP);
}


void loop() {
  readButtons();
  readIntensity();
  playNotes();
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).


void readButtons()
{
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    if (digitalRead(buttons[i]) == LOW)
    {
      bitWrite(pressedButtons, i, 1);
      delay(50);
    }
    else
      bitWrite(pressedButtons, i, 0);
  }
}

void readIntensity()
{
  int val = analogRead(intensityPot);
  intensity = (uint8_t) (map(val, 0, 1023, 0, 127));
}

void playNotes()
{
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    if (bitRead(pressedButtons, i) != bitRead(previousButtons, i))
    {
      if (bitRead(pressedButtons, i))
      {
        bitWrite(previousButtons, i , 1);
        //noteOn(0x90, notePitches[i], intensity);
        noteOn(0x90, notePitches[i], intensity);
        
      }
      else
      {
        bitWrite(previousButtons, i , 0);
        noteOff(0x80, notePitches[i], intensity);
      }
    }
  }
}

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void noteOff(int cmd, int pitch, int velocity) {
 Serial.write(cmd);
 Serial.write(pitch);
 Serial.write(velocity);
}
