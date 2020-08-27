# FIR

### experiment1 FIFO:
<img src="../resources/2.2.png"/>
<img src="../resources/2.3.png"/>

```
#include "ap_int.h"
#define N 8

void fifo(int x,int *y){
    static int pipe[N]={0};
    *y=pipe[N-1];//在2个周期内完成，其中pipe_load(read)耗时最长
    Shift:
    for(int i=N-1;i>0;--i){//重复7次
        pipe[i]=pipe[i-1];//在2个周期内完成，其中pipe_load_1(read)耗时最长
    }
    pipe[0]=x;//在1个周期内完成
}
```
pipe_load(read)耗时较长的原因可能是和它是和内存进行通信的，而不是DDR、BRAM这种存储设备。

### experiment2 SimpleAdd
数据类型为char时：
<img src="../resources/2.4.png" style="zoom:50%" />
数据类型为int时：


### version1:
<!-- ![Picture](../resources/chapter2-version1.png){:height="50%" width="50%"} -->
<img src="../resources/2.1.png" style="zoom:50%" />

### version2: