#include <iostream>
// #include "fifo.cpp"
using namespace std;

#define N 8
#define M 10
void main(int argc,char *argv[]){
    int x[M+N]={87,8,15,56,51,41,72,28,54,10,0,0,0,0,0,0,0,0};
    int y[N+M]={0,0,0,0,0,0,0,0,87,8,15,56,51,41,72,28,54,10};
    int y_[N+M]={0};
    int *py_=y_;
    for(int i=0;i<M+N;++i){
        fifo(x[i],py_);
        ++py_;
    }
    int err_cnt=0;
    for(int i=0;i<N+M;++i){
        if(y[i]==y_[i]){
            cout<<"y["<<i<<"]=="<<y[i]<<endl;
        }else{
            cout<<"Fault occurred: y["<<i<<"]=="<<y[i]<<"!=y_["<<i<<"]=="<<y_[i]<<endl;
            err_cnt+=1;
        }
    }
    if(err_cnt==0){
        cout<<"No fault occurs!"<<endl<<"Test passed."<<endl;
    }else{
        cout<<err_cnt<<" fault(s) occur!"<<endl<<"Test NOT passed!"<<endl;
    }
}
