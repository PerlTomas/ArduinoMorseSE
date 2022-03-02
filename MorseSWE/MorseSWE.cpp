/*
	Library that generates a message in morse code as a square wave on selected pin
	Created by Tomas Johansson, 27 Feb 2022
*/
#include "Arduino.h"
#include "MorseSWE.h"

MorseSWE::MorseSWE(byte BuzzPin, unsigned int ToneFrequency, int cpm) {
	pinMode(BuzzPin, OUTPUT);
	_BuzzPin=BuzzPin;
	_ToneFrequency=ToneFrequency;
	_cpm=cpm;
	_tunit=6000/cpm; // milliseconds
	_LetterCode[0]={".-"};
	 _LetterCode[1]={"-..."};
	 _LetterCode[2]={"-.-."};
	 _LetterCode[3]={"-.."};
	 _LetterCode[4]={"."};
	 _LetterCode[5]={"..-."};
	 _LetterCode[6]={"--."};
	 _LetterCode[7]={"...."};
	 _LetterCode[8]={".."};
	 _LetterCode[9]={".---"};
	 _LetterCode[10]={"-.-"};
	 _LetterCode[11]={".-.."};
	 _LetterCode[12]={"--"};
	 _LetterCode[13]={"-."};
	 _LetterCode[14]={"---"};
	 _LetterCode[15]={".--."};
	 _LetterCode[16]={"--.-"};
	 _LetterCode[17]={".-."};
	 _LetterCode[18]={"..."};
	 _LetterCode[19]={"-"};
	 _LetterCode[20]={"..-"};
	 _LetterCode[21]={"...-"};
	 _LetterCode[22]={".--"};
	 _LetterCode[23]={"-..-"};
	 _LetterCode[24]={"-.--"};
	 _LetterCode[25]={"--.."};

	_NumberCode[0]={"-----"};
	_NumberCode[1]={".----"};
	_NumberCode[2]={"..---"};
	_NumberCode[3]={"...--"};
	_NumberCode[4]={"....-"};
	_NumberCode[5]={"....."};
	_NumberCode[6]={"-...."};
	_NumberCode[7]={"--..."};
	_NumberCode[8]={"---.."};
	_NumberCode[9]={"----."};

	_SweLetterCode[0]={".--.-"};
	_SweLetterCode[1]={".-.-"};
	_SweLetterCode[2]={"---."};
	
	_PunctuationCode[0]={".-.-.-"};
	_PunctuationCode[1]={"-..-."};
	_PunctuationCode[2]={"..--.."};
	_PunctuationCode[3]={"--..--"};
	_PunctuationCode[4]={"-...-"};
}

void MorseSWE::Code(String msg) {
  _msg=msg;
  _msg.toUpperCase();
  for (unsigned int i=0; i<_msg.length(); i++) {
    char Character=_msg.charAt(i);
	unsigned int Number = (unsigned int)Character;
	if (Number >= 48 && Number <=57) { // Number
		encodeNumber(Number-48);
	}
	if (Number >= 65 && Number <=90) { // Character
		encodeLetter(Number-65);
	}
	if (Number==32) { // Space
		delay(7*_tunit);
	}
	if (Number==65445 || Number==65413) { // å & Å
		encodeSweLetter(0);
	}
	if (Number==65444 || Number==65412) { // ä & Ä
		encodeSweLetter(1);
	}
	if (Number==65462 || Number==65430) { // ö & Ö
		encodeSweLetter(2);
	}
	if (Number==46) { // .
		encodePunctuation(0);
	}
	if (Number==47) { // /
		encodePunctuation(1);
	}
	if (Number==63) { // ?
		encodePunctuation(2);
	}
	if (Number==44) { // ,
		encodePunctuation(3);
	}
	if (Number==61) { // =
		encodePunctuation(4);
	}
  }
}

void MorseSWE::Dash() {
  tone(_BuzzPin, _ToneFrequency);
  delay(3*_tunit);
  noTone(_BuzzPin);
  delay(_tunit);
}

void MorseSWE::Dot() {
  tone(_BuzzPin, _ToneFrequency);
  delay(_tunit);
  noTone(_BuzzPin);
  delay(_tunit);
}

void MorseSWE::encodeSweLetter(unsigned int Nr) {
	for (unsigned int i=0; i<_SweLetterCode[Nr].length(); i++) {
		char c=_SweLetterCode[Nr].charAt(i);
		if (c == '-') {
			Dash();
		}
		if (c=='.') {
			Dot();
		}
	}
	delay(3*_tunit);
}

void MorseSWE::encodeLetter(unsigned int Nr) {
	for (unsigned int i=0; i<_LetterCode[Nr].length(); i++) {
		char c=_LetterCode[Nr].charAt(i);
		if (c == '-') {
			Dash();
		}
		if (c=='.') {
			Dot();
		}
	}
	delay(3*_tunit);
}

void MorseSWE::encodeNumber(unsigned int Nr) {
	for (unsigned int i=0; i<_NumberCode[Nr].length(); i++) {
		char c=_NumberCode[Nr].charAt(i);
		if (c == '-') {
			Dash();
		}
		if (c=='.') {
			Dot();
		}
	}
	delay(3*_tunit);
}

void MorseSWE::encodePunctuation(unsigned int Nr) {
	for (unsigned int i=0; i<_PunctuationCode[Nr].length(); i++) {
		char c=_PunctuationCode[Nr].charAt(i);
		if (c == '-') {
			Dash();
		}
		if (c=='.') {
			Dot();
		}
	}
	delay(3*_tunit);
}
