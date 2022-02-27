/* This is an example of how to use the MorseSWE library 
Tomas Johansson 2022-02-27
*/

#include <MorseSWE.h>

String Message="Flygande bäckasiner söka hvila på mjuka tufvor qxz 0123456789 . ? /";

byte BuzzerPin=11; // The Arduino pin you connect the piezo speaker to
unsigned int ToneFrequency=2200; // Hz. Depending on your piezo speaker you might have to tweak this to get best output level.
int CharPmin=80; // Speed in characters per minute

MorseSWE Morse(BuzzerPin, ToneFrequency, CharPmin);

void setup() {
 
}

void loop() {
	Morse.Code(Message);
	while (1){}
}
