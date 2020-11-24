#include <Arduino.h>
#include "puente_h.h"
#include "configuration.h"
#include <SabertoothSimplified.h>
#include <SoftwareSerial.h>


//MOTOR 1 y 2

SoftwareSerial SWSerial(NOT_A_PIN, PH1); // RX on no pin (unused), TX on pin 11 (to S1).
SabertoothSimplified ST_1(SWSerial);

//MOTOR 3

SoftwareSerial SWSerial(NOT_A_PIN, PH2); // RX on no pin (unused), TX on pin 11 (to S1).
SabertoothSimplified ST_2(SWSerial);

void MBegin(){
SWSerial.begin(9600);
}


void mover_motor_1(float PWM){
    PWM = constrain(PWM, -127, 127);
    ST_1.motor(1,PWM);
}

void mover_motor_2(float PWM){
    PWM = constrain(PWM, -127, 127);
    ST_1.motor(2,PWM);
}

void mover_motor_3(float PWM){
    PWM = constrain(PWM, -127, 127);
    ST_2.motor(1,PWM);
}