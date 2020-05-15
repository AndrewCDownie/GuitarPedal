
#include <Adafruit_ZeroFFT.h>
#include "musical_notes.h"
#include <arduinoFFT.h>

#define SAMPLES 256


arduinoFFT FFT = arduinoFFT();
int16_t SamplingFrequency = 1000;
unsigned int sampling_period_us;
unsigned long microseconds;
int16_t signal_samples[SAMPLES];

int data = 0;





void setup(){
  pinMode(A0,INPUT);
  Serial.begin(9600);
  sampling_period_us = round(1000000*(1.0/SamplingFrequency));
  musical_notes note_generator;
  int n = 10;
  String note_names[12*n];
  float freqs[12*n];
  musical_notes notes_generator;
  
  get_notes_names(n,note_names);
  get_frequencies(n,freqs);
  for(int k = 0; k < 4*12;k++){
    Serial.println(note_names[k]);
    Serial.println(freqs[k]);
    delay(100);
  }
}

void loop(){
    /*sampling the the signal */
  /*
    bool go = false;
    while(!go){
      if(Serial.available()){
        go = Serial.read();
      }
    }
    */
    /*
    char** notes =  note_generator.get_notes_names(4);
    for(int i = 0; i<4*12;i++){
      Serial.println(notes[i]);
    }
    /*
    bool go = false;
    int data =0;
    while(!go){
        data = analogRead(A0)-510;
        if(data >100){
          go = true;
        }
      
    }
    for(int i =0; i<SAMPLES;i++){
      microseconds = micros();
      signal_samples[i] = analogRead(A0)-510;
      //Serial.println(vReal[i]);
      while(micros() <(microseconds + sampling_period_us)){
        //DO NOTHING
      }
    }
   /* FFT STUFF*/
   /*
    ZeroFFT(signal_samples,SAMPLES);
    int max_freq_index = 0;
    for(int i = 1; i<SAMPLES/2;i++){
      if (signal_samples[i] >signal_samples[max_freq_index]){
        max_freq_index = i;
      }
    }
    Serial.print(FFT_BIN(max_freq_index,SamplingFrequency,SAMPLES));
    Serial.println(" Hz");
    /*
    for (int i = 0; i<SAMPLES/2;i ++){
      //Serial.println(FFT_BIN(i,SamplingFrequency,SAMPLES));
      Serial.println(signal_samples[i]);
    }
   */
   
}
