#include "RotaryEnc.h"
#include "arduino.h"


/*
 * 
 * Copy this into the file to use the encoders
int state = 0;
void counter_interupt(){
  if(digitalRead(3) == 0){
    for(int i = 0; i<3; i++){
      encoders[i]->tickUp();
    }
  }else{
    for(int i = 0; i<3; i++){
      encoders[i]->tickDown();
    }
  }
} 
 */


RotaryEnc::RotaryEnc(char * title_,int Lb_,int Ub_,int diff_){
	title = title_;
	Lb = Lb_;
	Ub = Ub_;
	active = true;
  counter = 0;
  diff = diff_;
}

void RotaryEnc::tickUp(){
	if(active){
		if(counter >= Ub){
				counter = Ub;
		}else{
			counter +=diff;
		}
	}
}

void RotaryEnc::tickDown(){
	if(active){
		if(counter <= Lb){
				counter = Lb;
		}else{
			counter -=diff;
		}
}
}


void RotaryEnc::setActive(bool state){
	active = state;

}

int RotaryEnc::getCounter(){
	return counter;
}
