#include <Arduino.h>
#include "configuration.h"
#include "encoder.h"
#include "puente_h.h"
#include "bluetooth.h"


//Variables Control
float ref_1 = 0;
float kp_1 = 0;
float kd_1 = 0;
float ki_1 = 0;
float PWM_1 = 0;
long error_1 = 0;
long error_ant_1 = 0;
long error_acum_1 = 0;

float ref_2 = 0;
float kp_2 = 0;
float kd_2 = 0;
float ki_2 = 0;
float PWM_2 = 0;
long error_2 = 0;
long error_ant_2 = 0;
long error_acum_2 = 0;

float ref_3 = 0;
float kp_3 = 0;
float kd_3 = 0;
float ki_3 = 0;
float PWM_3 = 0;
long error_3 = 0;
long error_ant_3 = 0;
long error_acum_3 = 0;


// Variables tiempo
unsigned long time;
unsigned long time_ant = 0;


// Variables encoder

long enc_act1 = 0;
long enc_ant1 = 0;
long enc_act2 = 0;
long enc_ant2 = 0;
long enc_act3 = 0;
long enc_ant3 = 0;

float pasos = 500;
float red = 43;



void setup(){
  Serial.begin(115200);           //Inicializar el puerto serial (Monitor Serial)
  Serial.println("Comenzando...");
  MBegin();
  EnBegin();
}

void loop() {
  // put your main code here, to run repeatedly:
  enc_act1 = contador_1();
  enc_act2 = contador_2();
  enc_act3 = contador_3();
  time = micros();

  float posicion_m1 = (enc_act1 - enc_ant1)/(pasos * red) * 360;
  float posicion_m2 = (enc_act2 - enc_ant2)/(pasos * red) * 360;
  float posicion_m3 = (enc_act3 - enc_ant3)/(pasos * red) * 360;

  enc_ant1 = enc_act1;
  enc_ant2 = enc_act2;
  enc_ant3 = enc_act3;
  
  // Control motor 1
  error_1 = ref_1 - posicion_m1;
  PWM_1 = kp_1 * error_1 + ki_1 * error_acum_1 * (time - time_ant) + kd_1 * (error_1 - error_ant_1)/(time - time_ant);
  mover_motor_1(PWM_1);
  error_ant_1 = error_1;
  error_acum_1 += error_1;

  // Control motor 2
  error_2 = ref_2 - posicion_m2;
  PWM_2 = kp_2 * error_2 + ki_2 * error_acum_2 * (time - time_ant) + kd_2 * (error_2 - error_ant_2)/(time - time_ant);
  mover_motor_2(PWM_2);
  error_ant_2 = error_2;
  error_acum_2 += error_2;

  // Control motor 3
  error_3 = ref_3 - posicion_m3;
  PWM_3 = kp_3 * error_3 + ki_3 * error_acum_3 * (time - time_ant) + kd_3 * (error_3 - error_ant_3)/(time - time_ant);
  mover_motor_3(PWM_3);
  error_ant_3 = error_3;
  error_acum_3 += error_3;
  
  Serial.println(posicion_m2);
}