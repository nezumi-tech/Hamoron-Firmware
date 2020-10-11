#include <MIDI.h>

#include <avr/wdt.h>

const uint8_t PWMpin = 5;

int8_t NoteCount = 0;

uint8_t Expression = 60;

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void Initialize() {
  //全てのピンをLOWにする
  PORTB &= ~B00001111;
  PORTL &= ~B11111111;
  PORTG &= ~B10000111;
  PORTC &= ~B11111111;
  PORTA &= ~B11111111;

  NoteCount = 0;

  analogWrite(PWMpin, 120);//送風量を60にする

}


void VolumeChange() {
  if (NoteCount < 0) {
    NoteCount = 0;
  }
  int vel = Expression + 4 * NoteCount;
  analogWrite(PWMpin, constrain(vel + vel, 0, 255)); //vel+vel(2倍)
  Serial.print(NoteCount);
  Serial.print(' ');
  Serial.println(vel);
}


uint8_t AdjustNote (uint8_t note) {
  if (note > 84) {
    note = note - 12;
    if (note <= 84) {
      return note;
    }
    note = note - 12;
    if (note <= 84) {
      return note;
    }
    note = note - 12;
    if (note <= 84) {
      return note;
    }
    note = note - 12;

  } else if (note < 53) {
    note = note + 12;
    if (note >= 53) {
      return note;
    }
    note = note + 12;
    if (note >= 53) {
      return note;
    }
    note = note + 12;
    if (note >= 53) {
      return note;
    }
    note = note + 12;
    if (note >= 53) {
      return note;
    }
    note = note + 12;
  }
  return note;
}

void handleNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  (void) channel;//Wunused-parameter警告を回避
  (void) velocity;
  note = AdjustNote(note);
  NoteCount += 1;
  VolumeChange();

  if (note == 53) {
    PORTB |= _BV(0);
  } else if (note == 54) {
    PORTB |= _BV(1);
  } else if (note == 55) {
    PORTB |= _BV(2);
  } else if (note == 56) {
    PORTB |= _BV(3);
  } else if (note == 57) {
    PORTL |= _BV(0);
  } else if (note == 58) {
    PORTL |= _BV(1);
  } else if (note == 59) {
    PORTL |= _BV(2);
  } else if (note == 60) {
    PORTL |= _BV(3);
  } else if (note == 61) {
    PORTL |= _BV(4);
  } else if (note == 62) {
    PORTL |= _BV(5);
  } else if (note == 63) {
    PORTL |= _BV(6);
  } else if (note == 64) {
    PORTL |= _BV(7);
  } else if (note == 65) {
    PORTG |= _BV(0);
  } else if (note == 66) {
    PORTG |= _BV(1);
  } else if (note == 67) {
    PORTG |= _BV(2);
  } else if (note == 68) {
    PORTD |= _BV(7);
  } else if (note == 69) {
    PORTC |= _BV(0);
  } else if (note == 70) {
    PORTC |= _BV(1);
  } else if (note == 71) {
    PORTC |= _BV(2);
  } else if (note == 72) {
    PORTC |= _BV(3);
  } else if (note == 73) {
    PORTC |= _BV(4);
  } else if (note == 74) {
    PORTC |= _BV(5);
  } else if (note == 75) {
    PORTC |= _BV(6);
  } else if (note == 76) {
    PORTC |= _BV(7);
  } else if (note == 77) {
    PORTA |= _BV(7);
  } else if (note == 78) {
    PORTA |= _BV(6);
  } else if (note == 79) {
    PORTA |= _BV(5);
  } else if (note == 80) {
    PORTA |= _BV(4);
  } else if (note == 81) {
    PORTA |= _BV(3);
  } else if (note == 82) {
    PORTA |= _BV(2);
  } else if (note == 83) {
    PORTA |= _BV(1);
  } else if (note == 84) {
    PORTA |= _BV(0);
  } else {
  }
}

void handleNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
  (void) channel;
  (void) velocity;
  note = AdjustNote(note);
  NoteCount -= 1;
  VolumeChange();

  if (note == 53) {
    PORTB &= ~_BV(0);
  } else if (note == 54) {
    PORTB &= ~_BV(1);
  } else if (note == 55) {
    PORTB &= ~_BV(2);
  } else if (note == 56) {
    PORTB &= ~_BV(3);
  } else if (note == 57) {
    PORTL &= ~_BV(0);
  } else if (note == 58) {
    PORTL &= ~_BV(1);
  } else if (note == 59) {
    PORTL &= ~_BV(2);
  } else if (note == 60) {
    PORTL &= ~_BV(3);
  } else if (note == 61) {
    PORTL &= ~_BV(4);
  } else if (note == 62) {
    PORTL &= ~_BV(5);
  } else if (note == 63) {
    PORTL &= ~_BV(6);
  } else if (note == 64) {
    PORTL &= ~_BV(7);
  } else if (note == 65) {
    PORTG &= ~_BV(0);
  } else if (note == 66) {
    PORTG &= ~_BV(1);
  } else if (note == 67) {
    PORTG &= ~_BV(2);
  } else if (note == 68) {
    PORTD &= ~_BV(7);
  } else if (note == 69) {
    PORTC &= ~_BV(0);
  } else if (note == 70) {
    PORTC &= ~_BV(1);
  } else if (note == 71) {
    PORTC &= ~_BV(2);
  } else if (note == 72) {
    PORTC &= ~_BV(3);
  } else if (note == 73) {
    PORTC &= ~_BV(4);
  } else if (note == 74) {
    PORTC &= ~_BV(5);
  } else if (note == 75) {
    PORTC &= ~_BV(6);
  } else if (note == 76) {
    PORTC &= ~_BV(7);
  } else if (note == 77) {
    PORTA &= ~_BV(7);
  } else if (note == 78) {
    PORTA &= ~_BV(6);
  } else if (note == 79) {
    PORTA &= ~_BV(5);
  } else if (note == 80) {
    PORTA &= ~_BV(4);
  } else if (note == 81) {
    PORTA &= ~_BV(3);
  } else if (note == 82) {
    PORTA &= ~_BV(2);
  } else if (note == 83) {
    PORTA &= ~_BV(1);
  } else if (note == 84) {
    PORTA &= ~_BV(0);
  } else {
  }
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value) {
  (void) channel;
  if (number == 120 || number == 121 || number == 123) { //AllSoundsOff, ResetAllControler, AllNoteOff
    Initialize();
  } else if (number == 11) { //Expression
    Expression = value;
    VolumeChange();
  } else {
  }
}

void setup() {
  DDRB |= B00001111;
  DDRL |= B11111111;
  DDRG |= B10000111;
  DDRC |= B11111111;
  DDRA |= B11111111;

  //PWM
  TCCR3B = (TCCR3B & 0b11111000) | 0x01;
  pinMode(PWMpin, OUTPUT);

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleControlChange);

  MIDI.turnThruOff();//THRUの実行を停止

  Initialize();

  Serial.begin(115200);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  //MIDI.begin(1);
  wdt_enable(WDTO_30MS);
}


void loop() {

  MIDI.read();
  wdt_reset();

}
