/*
	Library that generates a message in morse code as a square wave on selected pin
	Created by Tomas Johansson, 27 Feb 2022
*/

#ifndef MorseSWE_h
	#define MorseSWE_h

	#include "Arduino.h"

	class MorseSWE {
		public:
			MorseSWE(byte BuzzPin, unsigned int ToneFrequency, int cpm);
			void Code(String msg);
			
		private:
			void encodeNumber(unsigned int Nr);
			void encodeLetter(unsigned int Nr);
			void encodeSweLetter(unsigned int Nr);
			void encodePunctuation(unsigned int Nr);
			void Dot();
			void Dash();
		
			byte _BuzzPin;
			unsigned int _ToneFrequency;
			int _cpm;
			unsigned long _tunit;
			String _msg;
			String _LetterCode[27];
			String _NumberCode[11];
			String _SweLetterCode[4];
			String _PunctuationCode[6];
	};

#endif