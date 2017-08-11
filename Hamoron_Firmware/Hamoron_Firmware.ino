#include <MIDI.h>//MIDIライブラリ

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

#define LED 13

const int bitPin[8] = {54, 55, 56, 57, 58, 59, 60, 61};

//120, 120, 112, 104, 96, 88, 80, 72, 64, 56, 48, 40, 32, 24, 16, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
const byte numvsvelo[33] = {135, 135, 143, 151, 159, 167, 175, 183, 191, 199, 207, 215, 223, 231, 239, 247, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

int num = 0;

void setup()//セットアップ
{
  //ピンモード設定

  pinMode(LED, OUTPUT);

  pinMode(20, OUTPUT);

  pinMode(21, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);

  pinMode(46, OUTPUT);
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

  pinMode(34, OUTPUT);
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

  pinMode(22, OUTPUT);

  for (int i = 0; i <= 7; i++) {
    pinMode(bitPin[i], OUTPUT);
    digitalWrite(bitPin[i], HIGH);
  }

  //ピンモード設定ここまで

  MIDI.begin(1);//MIDIモード開始。チャンネルは1

}//セットアップここまで


void loop()//メイン
{

  byte data1, data2;//8bitデータ変数定義　data1とdata2

  if (MIDI.read()) {

    MIDI.setInputChannel(1);//MIDIのチャンネル１を読み込む

    if (MIDI.getType() == midi::NoteOn) {

      data1 = MIDI.getData1();    // ノートNo.
      data2 = MIDI.getData2();    //  ベロシティ

      if (data2 == 0) {
        num--;
      } else {
        if (data1 == 53) {
          PORTD |= _BV(0);
        } else if (data1 == 54) {
          PORTB |= _BV(1);
        } else if (data1 == 55) {
          PORTB |= _BV(2);
        } else if (data1 == 56) {
          PORTB |= _BV(3);
        } else if (data1 == 57) {
          PORTL |= _BV(0);
        } else if (data1 == 58) {
          PORTL |= _BV(1);
        } else if (data1 == 59) {
          PORTL |= _BV(2);
        } else if (data1 == 60) {
          PORTL |= _BV(3);
        } else if (data1 == 61) {
          PORTL |= _BV(4);
        } else if (data1 == 62) {
          PORTL |= _BV(5);
        } else if (data1 == 63) {
          PORTL |= _BV(6);
        } else if (data1 == 64) {
          PORTL |= _BV(7);
        } else if (data1 == 65) {
          PORTG |= _BV(0);
        } else if (data1 == 66) {
          PORTG |= _BV(1);
        } else if (data1 == 67) {
          PORTG |= _BV(2);
        } else if (data1 == 68) {
          PORTD |= _BV(7);
        } else if (data1 == 69) {
          PORTC |= _BV(0);
        } else if (data1 == 70) {
          PORTC |= _BV(1);
        } else if (data1 == 71) {
          PORTC |= _BV(2);
        } else if (data1 == 72) {
          PORTC |= _BV(3);
        } else if (data1 == 73) {
          PORTC |= _BV(4);
        } else if (data1 == 74) {
          PORTC |= _BV(5);
        } else if (data1 == 75) {
          PORTC |= _BV(6);
        } else if (data1 == 76) {
          PORTC |= _BV(7);
        } else if (data1 == 77) {
          PORTA |= _BV(7);
        } else if (data1 == 78) {
          PORTA |= _BV(6);
        } else if (data1 == 79) {
          PORTA |= _BV(5);
        } else if (data1 == 80) {
          PORTA |= _BV(4);
        } else if (data1 == 81) {
          PORTA |= _BV(3);
        } else if (data1 == 82) {
          PORTA |= _BV(2);
        } else if (data1 == 83) {
          PORTA |= _BV(1);
        } else if (data1 == 84) {
          PORTA |= _BV(0);
        }
        num++;
      }
      
    } else if (MIDI.getType() == midi::NoteOff) {
      data1 = MIDI.getData1();
      if (data1 == 53) {
        PORTD &= ~_BV(0);
      } else if (data1 == 54) {
        PORTB &= ~_BV(1);
      } else if (data1 == 55) {
        PORTB &= ~_BV(2);
      } else if (data1 == 56) {
        PORTB &= ~_BV(3);
      } else if (data1 == 57) {
        PORTL &= ~_BV(0);
      } else if (data1 == 58) {
        PORTL &= ~_BV(1);
      } else if (data1 == 59) {
        PORTL &= ~_BV(2);
      } else if (data1 == 60) {
        PORTL &= ~_BV(3);
      } else if (data1 == 61) {
        PORTL &= ~_BV(4);
      } else if (data1 == 62) {
        PORTL &= ~_BV(5);
      } else if (data1 == 63) {
        PORTL &= ~_BV(6);
      } else if (data1 == 64) {
        PORTL &= ~_BV(7);
      } else if (data1 == 65) {
        PORTG &= ~_BV(0);
      } else if (data1 == 66) {
        PORTG &= ~_BV(1);
      } else if (data1 == 67) {
        PORTG &= ~_BV(2);
      } else if (data1 == 68) {
        PORTD &= ~_BV(7);
      } else if (data1 == 69) {
        PORTC &= ~_BV(0);
      } else if (data1 == 70) {
        PORTC &= ~_BV(1);
      } else if (data1 == 71) {
        PORTC &= ~_BV(2);
      } else if (data1 == 72) {
        PORTC &= ~_BV(3);
      } else if (data1 == 73) {
        PORTC &= ~_BV(4);
      } else if (data1 == 74) {
        PORTC &= ~_BV(5);
      } else if (data1 == 75) {
        PORTC &= ~_BV(6);
      } else if (data1 == 76) {
        PORTC &= ~_BV(7);
      } else if (data1 == 77) {
        PORTA &= ~_BV(7);
      } else if (data1 == 78) {
        PORTA &= ~_BV(6);
      } else if (data1 == 79) {
        PORTA &= ~_BV(5);
      } else if (data1 == 80) {
        PORTA &= ~_BV(4);
      } else if (data1 == 81) {
        PORTA &= ~_BV(3);
      } else if (data1 == 82) {
        PORTA &= ~_BV(2);
      } else if (data1 == 83) {
        PORTA &= ~_BV(1);
      } else if (data1 == 84) {
        PORTA &= ~_BV(0);
      }
      num--;
    }
    num = constrain(num, 0, 32);
     PORTF = numvsvelo[num];
  }
}
