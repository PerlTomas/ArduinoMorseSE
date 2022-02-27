#include <MorseSWE.h>

String Message="Flygande bäckasiner söka hvila på mjuka tufvor qxz 0123456789 . ? /";

byte BuzzerPin=11;
unsigned int ToneFrequency=2200; // Hz
int CharPmin=80;

MorseSWE Morse(BuzzerPin, ToneFrequency, CharPmin);

void setup() {
 
}

void loop() {
	Morse.Code(Message);
	while (1){}
}