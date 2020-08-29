// 循环拆分
#define N 11
#include "ap_int.h"  

typedef int coef_t;
typedef int data_t;
typedef int acc_t;

void fir(data_t *y,data_t x){
    coef_t C[N] = {
        53,0,-91,0,313,500,313,0,-91,0,53
    };
    static
    data_t shift_reg[N];
    acc_t acc;
    int i;
    TDL:
    for(i = N - 1;i > 0;i--){
        #pragma HLS UNROLL skip_exit_check factor=2
        shift_reg[i] = shift_reg[i - 1];
    }
    shift_reg[0] = x;

    acc = 0;
    MAC:
    for(i = N-1;i >= 0;i--){
        #pragma HLS UNROLL skip_exit_check factor=4
        acc += shift_reg[i] * C[i];
    }
    * y = acc;
}