/*
   TUTORIAL PASSIVE BUZZER PADA ARDUINO
   D3 -> Passive Buzzer +


*/
#include "nada.h"
#define PIN_BUZZER 3

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4, 0,
  NOTE_C5, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, 0, NOTE_B4, NOTE_C5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4, 4,
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
}

void loop() {
  mainkanMusik();
  delay(3000);
}

void mainkanMusik() {
  for (int thisNote = 0; thisNote < 17; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIN_BUZZER, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN_BUZZER);
  }
}
