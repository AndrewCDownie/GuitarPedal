
#ifndef RotaryEnc_h
#define RotaryEnc_h
#include "Arduino.h"


class RotaryEnc
{
	public: 
		RotaryEnc(int input_a,int input_b, int button);
		void setActive(bool state);
		int getCounter();	
		void update();
	private:
		int aState;
		int aLastState;
		int bState;
		int buttonState;
		bool active;
		int inputPinA;
		int inputPinB;
		int buttonPin;
		int counter;
};

#endif
