# HLS笔记
## ·pragma一览
已知的pragma：<br>
```
#pragma HLS unroll factor=12
```
（不区分大小写，例如unroll和UNROLL是一样的）
## ·分别探索pragma的效果
## ·几个小实验
### 1，手工FIFO
### 2，手工批量求和
这些小实验应当像游戏关卡一样，不断优化直到最优。另外，每个关卡可以使用的元素我并不完全清楚，这也需要慢慢来。