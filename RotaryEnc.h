
#ifndef RotaryEnc_h
#define RotaryEnc_h
#include "Arduino.h"


class RotaryEnc
{
	public:
		RotaryEnc(char * title_,int Lb_, int Ub_,int diff_);
		void setActive(bool state);
		int getCounter();
		void tickUp();
		void tickDown();
    char * title;
	private:
		bool active;
		int counter;
		int Ub;
		int Lb;
    int diff;
};

#endif
