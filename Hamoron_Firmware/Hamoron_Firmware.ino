#include <MIDI.h>

#include <avr/wdt.h>

const int PWMpin = 5;

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

void Initialize() {
  //全てのピンをLOWにする
  PORTB &= ~_BV(0);
  PORTB &= ~_BV(1);
  PORTB &= ~_BV(2);
  PORTB &= ~_BV(3);
  PORTL &= ~_BV(0);
  PORTL &= ~_BV(1);
  PORTL &= ~_BV(2);
  PORTL &= ~_BV(3);
  PORTL &= ~_BV(4);
  PORTL &= ~_BV(5);
  PORTL &= ~_BV(6);
  PORTL &= ~_BV(7);
  PORTG &= ~_BV(0);
  PORTG &= ~_BV(1);
  PORTG &= ~_BV(2);
  PORTD &= ~_BV(7);
  PORTC &= ~_BV(0);
  PORTC &= ~_BV(1);
  PORTC &= ~_BV(2);
  PORTC &= ~_BV(3);
  PORTC &= ~_BV(4);
  PORTC &= ~_BV(5);
  PORTC &= ~_BV(6);
  PORTC &= ~_BV(7);
  PORTA &= ~_BV(7);
  PORTA &= ~_BV(6);
  PORTA &= ~_BV(5);
  PORTA &= ~_BV(4);
  PORTA &= ~_BV(3);
  PORTA &= ~_BV(2);
  PORTA &= ~_BV(1);
  PORTA &= ~_BV(0);

  analogWrite(PWMpin, 0);//送風量を0にする
}

void handleNoteOn(byte channel, byte note, byte velocity) {
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
  } else if (note == 85) {
    analogWrite(PWMpin, velocity * 2);  //風量調節。LPFを通してドライバにつなぐ。
  } else {
  }
}

void handleNoteOff(byte channel, byte note, byte velocity) {
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

void handleControlChange(byte channel, byte number, byte value) {
  if (number == 120 || number == 123) {
    Initialize();
  }
}

void setup() {
  pinMode(53, OUTPUT);//F3
  pinMode(52, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);

  pinMode(46, OUTPUT);//C4
  pinMode(45, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(35, OUTPUT);

  pinMode(34, OUTPUT);//C5
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(23, OUTPUT);

  pinMode(22, OUTPUT);//C6

  //PWM
  TCCR3B = TCCR3B & 0b11111000 | 0x01;
  pinMode(PWMpin, OUTPUT);

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleControlChange);

  Initialize();

  MIDI.begin(1);
  wdt_enable(WDTO_30MS);
}


void loop() {

  MIDI.read();
  wdt_reset();

}
