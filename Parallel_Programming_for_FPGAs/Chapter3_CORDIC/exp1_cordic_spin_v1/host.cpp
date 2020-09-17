#include <iostream>
#include "host_head.h"
#include "head.h"
#define L 10


int main(int argc,char *argv[]){
    float x_list[10]={65.89205348625,127.1985965124037,0.3687731641276457,-29.034412420678734,34.66627773694813,10.889587336526631,-26.54099981573833,85.64420158090167,38.91260690196569,-95.67145052160728};
    float y_list[10]={-77.9902818014005,62.30719773048338,8.684218320845474,-29.387113757050344,-23.136592735784575,20.132510526487778,-12.189474752073835,-1.2739084790828201,-101.93705541019702,-109.50794323698463};
    float theta_list[10]={-2.1177511919217418,1.5229538388279042,-0.20408181728443875,-2.0167684784385793,0.895720406886106,-2.1339931322762675,1.7758424774268775,-1.3676451783559662,2.078975760388687,-1.5073492797176984};
    float x__list[10]={-100.88216895121492,-56.15272767526571,2.1211343707299832,-13.989249463360066,39.7267196608751,11.20923490414736,17.33819980554694,16.031577895496074,70.12106520101989,-115.35360283808448};
    float y__list[10]={-15.71733933575345,130.03284592124515,8.429260375145427,38.87030304790228,12.603193267701066,-19.956305903714416,-23.50308050986933,-84.14000604601736,83.59659357104692,88.53565603290274};
    float x___list[L]={0};
    float y___list[L]={0};
    float *px__=x___list;
    float *py__=y___list;
    for(int i=0;i<L;++i){
        cordic_spin(px__,py__,x_list[i],y_list[i],theta_list[i]);
        ++px__;
        ++py__;
    }
    compare_float_list(x__list,x___list,"x_sw","x_hw",L);
    compare_float_list(y__list,y___list,"y_sw","y_hw",L);
    return 0;
}