#include <iostream>
#include <cmath>
using namespace std;

int compare_float_list(float list0[],float list1[],const char *name0,const char *name1,int len,float endurance=1e-2){
    int err_cnt=0;
    float tmp=0;
    for(int i=0;i<len;++i){
        tmp=abs(list0[i]-list1[i]);
        if(tmp>endurance){
            cout<<"Fault : "<<name0<<"["<<i<<"]=="<<list0[i]<<"!="<<list1[i]<<"=="<<name1<<"["<<i<<"]"<<endl;
            ++err_cnt;
        }else{
            cout<<name0<<"["<<i<<"]=="<<list0[i]<<"~="<<list1[i]<<"=="<<name1<<"["<<i<<"]"<<endl;
        }
    }
    if(err_cnt==0){
        cout<<"No fault occurs!"<<endl<<"Test passed."<<endl;
    }else{
        cout<<err_cnt<<"fault(s) occur!"<<endl<<"Test NOT passed!"<<endl;
    }
    return 0;
}