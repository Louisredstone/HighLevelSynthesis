//#include "fir.cpp"
#include <iostream>
using namespace std;
void main(int argc,char* argv[]){
    const int L=128;
    int x[L]={54,56,23,3,26,0,4,22,27,27,16,29,45,56,38,10,  
                37,25,33,4,13,55,38,62,11,9,13,35,56,23,50,2,   
                35,18,17,7,9,25,46,24,15,52,28,29,14,49,51,17,
                3,25,37,45,51,16,23,20,60,32,34,57,38,39,25,50,
                9,27,58,35,52,7,35,8,16,56,45,38,2,23,27,5,
                52,62,60,13,45,36,41,13,24,48,45,47,52,25,23,49,
                57,24,35,43,49,47,3,23,43,59,64,0,13,20,48,58,
                1,59,2,58,50,3,43,31,44,4,19,17,20,34,48,7,
                };
    int y[L]={2862,2968,-3695,-4937,16187,44255,49947,31133,12990,8272,8550,10661,20485,29325,25892,18960,
                29851,48229,52336,36387,22914,28447,34168,25916,12170,18057,42109,57618,48688,20964,6797,15558,
                37415,49393,41794,28850,22128,24210,25313,16359,7712,13556,30142,35459,29369,29342,37179,34936,
                24237,27732,44780,46385,24948,8477,17699,41064,53561,43095,24296,20107,32219,44085,43899,42986,
                44997,44077,41560,36264,31464,25259,31333,45710,50099,41579,26859,17359,14316,27011,47913,49737,
                34409,18252,15778,16821,26355,47617,61783,51652,33605,33821,42415,36063,24591,25554,40738,53282,
                54778,41670,29820,33024,46605,50143,37159,32279,45830,54117,39091,15400,18159,46228,66676,52119,
                16032,6459,25563,49246,49014,30182,24489,34773,46148,39189,27483,30528,37618,36011,21180,10688,
                };
    int y_[L]={0};
    int* py_=y_;
    for(int i=0;i<L;++i){
        fir(py_,x[i]);
        ++py_;
    }
    int err_cnt=0;
    for(int i=0;i<L;++i){
        if(y[i]!=y_[i]){
            cout<<"Fault at y["<<i<<"]: "<<y[i]<<"!="<<y_[i]<<endl;
            ++err_cnt;
        }else{
            cout<<"y["<<i<<"]=="<<y[i]<<endl;
        }
    }
    if(err_cnt==0){
        cout<<"No fault occurs!"<<endl<<"Test passed."<<endl;
    }else{
        cout<<err_cnt<<"fault(s) occur!"<<endl<<"Test NOT passed!"<<endl;
    }
}
