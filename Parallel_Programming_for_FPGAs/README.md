# HLS笔记
（待施工）
## ·pragma一览
已知的pragma：<br>
```
#pragma HLS unroll factor=12
```
（不区分大小写，例如unroll和UNROLL是一样的）
## ·分别探索pragma的效果
## ·几个小实验
### 1，手工FIFO
观察它的运行周期，试着理解HLS的底层逻辑，并使用一些简单的UNROLL和PIPELINE来观察优化效果。
### 2，a=b*c，即SimpleMul
变量类型分别改为char, short, int, long, long long.
### 3，手工批量求和
这些小实验应当像游戏关卡一样，不断优化直到最优。另外，每个关卡可以使用的元素我并不完全清楚，这也需要慢慢来。