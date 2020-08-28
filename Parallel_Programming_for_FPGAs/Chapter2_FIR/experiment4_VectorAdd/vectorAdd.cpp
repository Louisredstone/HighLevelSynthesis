#include "ap_int.h"

#include "head.h"

void vectorAdd(T *a,T *b,T *c){
    for(int i=N-1;i>=0;--i){
        *a=*b+*c;
        ++a;
        ++b;
        ++c;
    }
}