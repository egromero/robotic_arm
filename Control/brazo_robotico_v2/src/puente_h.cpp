#include <Arduino.h>
#include "puente_h.h"
#include "configuration.h"

#include <iostream>
#include <string>  
#include <sstream> // stringstream

int PWM1 = 0;
int PWM2 = 0;
int PWM3 = 0;

void MBegin(){
//Serial.begin(9600);
//Serial.begin(9600);
}


void mover_motor_1(float PWM){
    PWM1 = constrain(PWM, -2047, 2047);
    std::stringstream strs;
    strs << PWM1;
    std::string temp_str = strs.str();
    char const* pwm = temp_str.c_str(); 
    
    Serial.write("M1: ");
    Serial.write(pwm);
    Serial.write("\r\n");
}

void mover_motor_2(float PWM){
    std::ostringstream ss;
    PWM2 = constrain(PWM, -2047, 2047);
    ss << PWM2;
    std::string s(ss.str());
    const char* c = s.c_str();
    char result[100];
    strcat(result, "Q1: ");
    strcat(result,c);
    strcat(result,"\r\n");
    //Serial1.write(result);
}

void mover_motor_3(float PWM){
    std::ostringstream ss;
    PWM3 = constrain(PWM, -2047, 2047);
    ss << PWM3;
    std::string s(ss.str());
    const char* c = s.c_str();
    char result[100];
    strcat(result, "M1: ");
    strcat(result,c);
    strcat(result,"\r\n");
    //Serial1.write(result);
}