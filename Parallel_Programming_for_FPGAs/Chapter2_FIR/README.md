# FIR
------
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

------
### experiment2 SimpleAdd
|char|short|int|long|
|-|-|-|-|
|<img src="../resources/2.4.png" style="zoom:30%" />|<img src="../resources/2.5.png" style="zoom:30%" />|<img src="../resources/2.6.png" style="zoom:30%" />|<img src="../resources/2.7.png" style="zoom:30%" />|

|long long|float|double|
|-|-|-|
|<img src="../resources/2.8.png" style="zoom:30%" />|<img src="../resources/2.14.png" style="zoom:50%" />|<img src="../resources/2.15.png" style="zoom:50%" />|
不难发现：<br>
- 此处使用的int类型即long类型
- 有些类型切换只影响组合逻辑的耗时，不影响时钟周期的消耗。而改为float和double就会产生周期延时。

------
### experiment3 SimpleMul
|char|short|int|long|
|-|-|-|-|
|<img src="../resources/2.9.png" style="zoom:50%" />|<img src="../resources/2.10.png" style="zoom:50%" />|<img src="../resources/2.11.png" style="zoom:50%" />|<img src="../resources/2.12.png" style="zoom:50%" />|

|long long|float|double|
|-|-|-|
|<img src="../resources/2.13.png" style="zoom:50%" />|<img src="../resources/2.16.png" style="zoom:50%" />|<img src="../resources/2.17.png" style="zoom:50%" />|

当数据类型为long long时出现了意外。此前的latency和interval都是0，而到了long long这里就变成了4，可见由于DSP乘法位宽的限制，系统切分了long long数据，从而形成了4个周期的延时。
float和double的情况和加法一致。

------
### version1/2/3
|version1|version2|version3|
|-|-|-|
|<img src="../resources/2.1.png" style="zoom:40%" />|<img src="../resources/2.18.png" style="zoom:67%" />|<img src="../resources/2.19.png" style="zoom:67%" />|
|<img src="../resources/2.20.png" style="zoom:67%" />|<img src="../resources/2.21.png" style="zoom:67%" />|<img src="../resources/2.22.png" style="zoom:67%" />|
（coef_t、data_t、acc_t均为int）
虽然没有使用任何HLS指令，但version3的优化效果已经十分可观。相较前两个设计，延时大大降低，增加了两个BRAM的用量，减少了2个DSP的用量，并且缩减了大量触发器（FF）和少量查找表（LUT）。
但这一切是怎么完成的？如果不理解其中原理，自己进行独立设计的时候并不能熟练使用相应的技巧。