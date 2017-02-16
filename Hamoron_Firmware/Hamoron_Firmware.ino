//Arduino MegaのSerial1を使うようにしました。

#include <MIDI.h>//MIDIライブラリ

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

#define LED 13

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

  //ピンモード設定ここまで

  MIDI.begin(1);//MIDIモード開始。チャンネルは1

}//セットアップここまで


void loop()//メイン
{

  byte data1, data2;//8bitデータ変数定義　data1とdata2

  if (MIDI.read())//もしMIDIでなにか読み込んだら
  {

    MIDI.setInputChannel(1);//MIDIのチャンネル１を読み込む

    switch (MIDI.getType()) {//何か情報を得たら

      case midi::NoteOn://それがNoteOnだった場合
        data1 = MIDI.getData1();    // ノートNo.
        data2 = MIDI.getData2();    //  ベロシティ

        if (data2 == 0) { }//ベロシティが0だったら何もしない
        else {//それ以外の時は
          switch (data1)  //NoteOnの数値が
          {
            //NoteOnに対応したデジタルピンをHIGHにする

            case 53: PORTD |= _BV(0); break;//53だったらPD1(21)をHIGHにする。PB0にするとD53
            case 54: PORTB |= _BV(1); break;
            case 55: PORTB |= _BV(2); break;
            case 56: PORTB |= _BV(3); break;
            case 57: PORTL |= _BV(0); break;
            case 58: PORTL |= _BV(1); break;
            case 59: PORTL |= _BV(2); break;

            case 60: PORTL |= _BV(3); break;
            case 61: PORTL |= _BV(4); break;
            case 62: PORTL |= _BV(5); break;
            case 63: PORTL |= _BV(6); break;
            case 64: PORTL |= _BV(7); break;
            case 65: PORTG |= _BV(0); break;
            case 66: PORTG |= _BV(1); break;
            case 67: PORTG |= _BV(2); break;
            case 68: PORTD |= _BV(7); break;
            case 69: PORTC |= _BV(0); break;
            case 70: PORTC |= _BV(1); break;
            case 71: PORTC |= _BV(2); break;

            case 72: PORTC |= _BV(3); break;
            case 73: PORTC |= _BV(4); break;
            case 74: PORTC |= _BV(5); break;
            case 75: PORTC |= _BV(6); break;
            case 76: PORTC |= _BV(7); break;
            case 77: PORTA |= _BV(7); break;
            case 78: PORTA |= _BV(6); break;
            case 79: PORTA |= _BV(5); break;
            case 80: PORTA |= _BV(4); break;
            case 81: PORTA |= _BV(3); break;
            case 82: PORTA |= _BV(2); break;
            case 83: PORTA |= _BV(1); break;

            case 84: PORTA |= _BV(0); break;

            default: break;//これら以外だったら抜ける
          }
          digitalWrite(LED, HIGH);
        }
        break;

      case midi::NoteOff:
        data1 = MIDI.getData1(); // note off
        switch (data1) {//階層4
          //note off に対応したデジタルピンをLOWにする

          case 53: PORTD &= ~_BV(0); break;//53だったらPD1(21)をLOWにする。PB0にするとD53
          case 54: PORTB &= ~_BV(1); break;
          case 55: PORTB &= ~_BV(2); break;
          case 56: PORTB &= ~_BV(3); break;
          case 57: PORTL &= ~_BV(0); break;
          case 58: PORTL &= ~_BV(1); break;
          case 59: PORTL &= ~_BV(2); break;

          case 60: PORTL &= ~_BV(3); break;
          case 61: PORTL &= ~_BV(4); break;
          case 62: PORTL &= ~_BV(5); break;
          case 63: PORTL &= ~_BV(6); break;
          case 64: PORTL &= ~_BV(7); break;
          case 65: PORTG &= ~_BV(0); break;
          case 66: PORTG &= ~_BV(1); break;
          case 67: PORTG &= ~_BV(2); break;
          case 68: PORTD &= ~_BV(7); break;
          case 69: PORTC &= ~_BV(0); break;
          case 70: PORTC &= ~_BV(1); break;
          case 71: PORTC &= ~_BV(2); break;

          case 72: PORTC &= ~_BV(3); break;
          case 73: PORTC &= ~_BV(4); break;
          case 74: PORTC &= ~_BV(5); break;
          case 75: PORTC &= ~_BV(6); break;
          case 76: PORTC &= ~_BV(7); break;
          case 77: PORTA &= ~_BV(7); break;
          case 78: PORTA &= ~_BV(6); break;
          case 79: PORTA &= ~_BV(5); break;
          case 80: PORTA &= ~_BV(4); break;
          case 81: PORTA &= ~_BV(3); break;
          case 82: PORTA &= ~_BV(2); break;
          case 83: PORTA &= ~_BV(1); break;

          case 84: PORTA &= ~_BV(0); break;


          default: break;
        }
        digitalWrite(LED, LOW);
        break;
      default: break;
    }

  }

}

