#include <Arduino.h>
#include "configuration.h"
#include "encoder.h"


volatile long contador1 = 0;
volatile long contador2 = 0;
volatile long contador3 = 0;

void Encoder1A(){
  if (digitalRead(encoder1PinA) == digitalRead(encoder1PinB)) {
    contador1++;
  } 
  else {
    contador1--;
  }
}

void Encoder1B(){
  if (digitalRead(encoder1PinA) == digitalRead(encoder1PinB)) {
    contador1--;
  } 
  else {
    contador1++;
  }
}

void Encoder2A(){
  if (digitalRead(encoder2PinA) == digitalRead(encoder2PinB)) {
    contador2++;
  } 
  else {
    contador2--;
  }
}

void Encoder2B(){
  if (digitalRead(encoder2PinA) == digitalRead(encoder2PinB)) {
    contador2--;
  } 
  else {
    contador2++;
  }
}

void Encoder3A(){
  if (digitalRead(encoder3PinA) == digitalRead(encoder3PinB)) {
    contador3++;
  } 
  else {
    contador3--;
  }
}

void Encoder3B(){
  if (digitalRead(encoder3PinA) == digitalRead(encoder3PinB)) {
    contador3--;
  } 
  else {
    contador3++;
  }
}

volatile long contador_1(){
  return contador1;
}

volatile long contador_2(){
  return contador2;
}

volatile long contador_3(){
  return contador3;
}

void EnBegin(){
  pinMode(encoder1PinA, INPUT_PULLUP);
  pinMode(encoder1PinB, INPUT_PULLUP);
  pinMode(encoder2PinA, INPUT_PULLUP);
  pinMode(encoder2PinB, INPUT_PULLUP);
  pinMode(encoder3PinA, INPUT_PULLUP);
  pinMode(encoder3PinB, INPUT_PULLUP);

  
  attachInterrupt(digitalPinToInterrupt(encoder1PinA), Encoder1A, CHANGE);  // encoder 1 PIN A
  attachInterrupt(digitalPinToInterrupt(encoder1PinB), Encoder1B, CHANGE);  // encoder 1 PIN B
  attachInterrupt(digitalPinToInterrupt(encoder2PinA), Encoder2A, CHANGE);  // encoder 2 PIN A
  attachInterrupt(digitalPinToInterrupt(encoder2PinB), Encoder2B, CHANGE);  // encoder 2 PIN B
  attachInterrupt(digitalPinToInterrupt(encoder3PinA), Encoder3A, CHANGE);  // encoder 3 PIN A
  attachInterrupt(digitalPinToInterrupt(encoder3PinB), Encoder3B, CHANGE);  // encoder 3 PIN B
}