#include "ap_int.h"
#define M 15

void cordic_spin(float *x_,float *y_,float x,float y,float theta){
    const float Km=0.6072529351031393;
    const float cordic_phase[M+1]={0.7853981633974483,0.4636476090008061,0.24497866312686414,0.12435499454676144,0.06241880999595735,0.031239833430268277,0.015623728620476831,0.007812341060101111,0.0039062301319669718,0.0019531225164788188,0.0009765621895593195,0.0004882812111948983,0.00024414062014936177,0.00012207031189367021,6.103515617420877e-05,3.0517578115526096e-05};
    ap_int<2> sigma=0;
    float x_iter=x;
    float y_iter=y;
    float theta_iter=0;
    for(int k=0;k<=M;++k){
        if(theta_iter<=theta){
            sigma=1;
        }else{
            sigma=-1;
        }
        theta_iter+=cordic_phase[k]*sigma;
        x_iter=x_iter-sigma*(y_iter>>k);
        y_iter=y_iter+sigma*(x_iter>>k);
    }
    *x_=x_iter;
    *y_=y_iter;
}