#include "ap_int.h"
#define N 8

void fifo(int x,int *y){
    static int pipe[N]={0};
    *y=pipe[N-1];
    Shift:
    for(int i=N-1;i>1;--i){
        pipe[i]=pipe[i-1];
    }
    pipe[0]=x;
}