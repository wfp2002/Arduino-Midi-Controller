# Arduino-Midi-Controller


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
const byte notePitches[NUM_BUTTONS] = {50, 51, 52, 53, 54, 55, 56};
