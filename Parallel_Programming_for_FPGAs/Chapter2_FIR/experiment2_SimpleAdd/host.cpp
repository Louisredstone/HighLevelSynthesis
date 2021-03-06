#include <iostream>
#include "head.h"

using namespace std;
void main(int argc,char* argv[]){
    T a[15]={171, 106, 190, 108, 159, 223, 214, 127, 129, 107, 61, 225, 82, 83, 76};
    T b[15]={122, 83, 84, 76, 113, 105, 99, 113, 100, 62, 55, 99, 61, 14, 22};
    T c[15]={49, 23, 106, 32, 46, 118, 115, 14, 29, 45, 6, 126, 21, 69, 54};
    T a_[15]={0};
    T *pa_=a_;
    for(int i=0;i<15;++i){
        simpleAdd(pa_,b[i],c[i]);
        ++pa_;
    }
    int err_cnt=0;
    for(int i=0;i<15;++i){
        if(a[i]==a_[i]){
            cout<<"a["<<i<<"]=="<<a[i]<<endl;
        }else{
            cout<<"Fault occurred: a["<<i<<"]=="<<a[i]<<"!=a_["<<i<<"]=="<<a_[i]<<endl;
            err_cnt+=1;
        }
    }
    if(err_cnt==0){
        cout<<"No fault occurs!"<<endl<<"Test passed."<<endl;
    }else{
        cout<<err_cnt<<" fault(s) occur!"<<endl<<"Test NOT passed!"<<endl;
    }
}