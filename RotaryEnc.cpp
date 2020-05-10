#include "RotaryEnc.h"
RotaryEnc::RotaryEnc(int inputA, int inputB, int button){
	inputPinA = inputA;
	inputPinB = inputB;
	buttonPin = button;
	counter = 0;
	pinMode(inputPinA,INPUT);
	pinMode(inputPinB,INPUT);
	pinMode(buttonPin,INPUT);
	active = false;
	aLastState = digitalRead(inputPinA);
}

void RotaryEnc::update(){
	if(active){
		aState = digitalRead(inputPinA);
		if(aState != aLastState){
			if(digitalRead(inputPinB) !=aState){
				counter +=1;
			}else{
				counter += -1;
			}
			aLastState = aState;
		}
	}
}
void RotaryEnc::setActive(bool state){
	active = state;

}

int RotaryEnc::getCounter(){
	return counter;
}
