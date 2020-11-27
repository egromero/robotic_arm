#include <Arduino.h>
#include "HCSR04_sensor.h"
#include <HCSR04.h>
#include "configuration.h"

UltraSonicDistanceSensor distanceSensor(PROX_TRIGGER, PROX_ECHO);

float medir_distancia(){
    return distanceSensor.measureDistanceCm();
}
