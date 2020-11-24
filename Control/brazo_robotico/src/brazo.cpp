#include <Arduino.h>
#include "configuration.h"
#include "brazo.h"
#include <tuple>
#include <cmath>
using namespace std; 
Brazo::Brazo(){
    float L1 = 0;
    float L2 = 0;
    float L3 = 0;

}

tuple <float, float, float> Brazo::pos_motores(tuple <float, float, float> pos_obj){
    float px = get<0>(pos_obj);
    float py = get<1>(pos_obj);
    float pz = get<2>(pos_obj);
    tuple<float, float, float> pos;

    float theta_1 = atan(py/px);
    float a = px * cos(theta_1) + py * sin(theta_1);
    float b = pz - L1; 
    float c = (pow(a, 2) + pow(b,2) + (pow(L2,2)-pow(L3,2)))/(2 * pow(L2,2));
    float theta_2 = 2 * atan((b - pow(pow(b,2) + pow(a,2) - pow(c,2),0.5))/(a + c));
    float theta_3 = atan((b * cos(theta_2) - a * sin(theta_2))/(a * cos(theta_2) + b * sin(theta_2) - L2));
    pos = make_tuple(theta_1,theta_2,theta_3);
    return pos;

}