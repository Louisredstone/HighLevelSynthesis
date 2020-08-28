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
<img src="../resources/2.4.png" style="zoom:30%" />

数据类型为short时：
<img src="../resources/2.5.png" style="zoom:30%" />

数据类型为int时：
<img src="../resources/2.6.png" style="zoom:30%" />

数据类型为long时：
<img src="../resources/2.7.png" style="zoom:30%" />

数据类型为long long时：
<img src="../resources/2.8.png" style="zoom:30%" />

数据类型为float时：
<img src="../resources/2.14.png" style="zoom:50%" />

数据类型为double时：
<img src="../resources/2.15.png" style="zoom:50%" />

不难发现：<br>
- 此处使用的int类型即long类型
- 有些类型切换只影响组合逻辑的耗时，不影响时钟周期的消耗。而改为float和double就会产生周期延时。

### experiment3 SimpleMul
数据类型为char时：
<img src="../resources/2.9.png" style="zoom:50%" />

数据类型为short时：
<img src="../resources/2.10.png" style="zoom:50%" />

数据类型为int时：
<img src="../resources/2.11.png" style="zoom:50%" />

数据类型为long时：
<img src="../resources/2.12.png" style="zoom:50%" />

数据类型为long long时：
<img src="../resources/2.13.png" style="zoom:50%" />

数据类型为float时：
<img src="../resources/2.16.png" style="zoom:50%" />

数据类型为double时：
<img src="../resources/2.17.png" style="zoom:50%" />

当数据类型为long long时出现了意外。此前的latency和interval都是0，而到了long long这里就变成了4，可见由于DSP乘法位宽的限制，系统切分了long long数据，从而形成了4个周期的延时。
float和double的情况和加法一致。

### version1:
<img src="../resources/2.1.png" style="zoom:30%" />

### version2:
<img src="../resources/2.18.png" style="zoom:50%" />