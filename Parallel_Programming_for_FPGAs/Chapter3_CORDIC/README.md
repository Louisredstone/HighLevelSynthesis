# CORDIC

关于cordic数学原理的一些推算。

$对于x,y,\theta\in\mathbb{R},$

$\omega=x+iy,p(\theta)=\cos(\theta)+i\sin(\theta)$

$\omega'=\omega\cdot p(\theta)=(x\cdot \cos(\theta)-y\cdot \sin(\theta))+i\cdot (x\cdot \sin(\theta)+y\cdot \cos(\theta))$

对复数$\omega$乘以模为1的标准复数p，恰好可以表示$\omega$逆时针旋转角度$\theta$后得到的点。

CORDIC算法的思路是，由于$\cos(\theta)$和$\sin(\theta)$在硬件上不易实现，因此设计一个$\theta_n$序列和一个计算过程，使得整个计算在硬件实现中更为容易。

令
$$p(\theta)=\prod_{n=0}^{\infty}p(\theta_n)\tag{1}$$
于是
$$\theta=\sum_{n=0}^{\infty}\theta_n\tag{2}$$
$$\omega'=\omega\cdot p(\theta)=\omega\cdot \prod_{n=0}^{\infty}p(\theta_n)\tag{3}$$
我们希望每次的$“\cdot p(\theta_n)”$的操作更易实现，于是利用二进制位移操作，以及公式
$$\cos(\theta_n)=\cfrac{1}{\sqrt{1+\tan^2(\theta_n)}}\tag{4}$$
$$\sin(\theta_n)=\cfrac{\tan(\theta_n)}{\sqrt{1+\tan^2(\theta_n)}}\tag{5}$$
那么就有
$$p(\theta_n)=\cfrac{1}{\sqrt{1+\tan^2(\theta_n)}}\cdot(1+i\cdot\tan(\theta_n))\tag{6}$$
记$t_n=\tan(\theta_n)$，则整体可重写为
$$\omega_{-1}=\omega, \omega_{n+1}=\omega_n\cdot p_{n+1}, \omega'=\lim_{n\rightarrow\infty}\omega_n\tag{7}$$
$$p_n=\cfrac{1+i\cdot t_n}{\sqrt{1+t_n^2}}\tag{8}$$
$$\theta_{acc,n}=\sum_{k=0}^{n}\arctan(t_k)\tag{9}$$
$$\theta=\sum_{k=0}^{\infty}\arctan(t_k)\tag{10}$$
注意其中$t_n$可以是负数，表示顺时针旋转。

根据式（7）、（8）可进一步导出
$$\omega_n=\omega\cdot(\prod_{k=0}^{n}\cfrac{1}{\sqrt{1+t_k^2}})\cdot(\prod_{k=0}^{n}(1+i\cdot t_k))\tag{11}$$
$$\omega'=\omega\cdot(\prod_{k=0}^{\infty}\cfrac{1}{\sqrt{1+t_k^2}})\cdot(\prod_{k=0}^{\infty}(1+i\cdot t_k))\tag{12}$$

而为了方便位移运算，不妨令$t_n=\sigma_n\cdot2^{-n}, \sigma_n=\pm1$，于是有
$$\theta_n=\arctan(\cfrac{\sigma_n}{2^n})=\sigma_n\cdot\arctan(2^{-n})=\sigma_n\cdot \alpha_n\tag{13}$$
$$\omega_n=\omega\cdot(\prod_{k=0}^{n}\cfrac{1}{\sqrt{1+2^{-2k}}})\cdot(\prod_{k=0}^{n}(1+i\cdot \sigma_k\cdot2^{-k}))\tag{14}$$
$$\omega'=\omega\cdot(\prod_{k=0}^{\infty}\cfrac{1}{\sqrt{1+2^{-2k}}})\cdot(\prod_{k=0}^{\infty}(1+i\cdot \sigma_k\cdot2^{-k}))\tag{15}$$
当已知目标迭代次数m时，可修改$\omega_n$的定义为
$$\omega_n=\omega\cdot(\prod_{k=0}^{m}\cfrac{1}{\sqrt{1+2^{-2k}}})\cdot(\prod_{k=0}^{n}(1+i\cdot \sigma_k\cdot2^{-k}))\tag{16}$$
也可写作递推形式：
$$\omega_{-1}=\omega\cdot K_m, \omega_{n+1}=\omega_n\cdot(1+i\cdot\sigma_n\cdot2^{-n})\tag{17}$$
另外，有
$$
\sigma_{n+1}=
\begin{cases}
1,\quad \theta_{acc,n}\leq \theta\\
-1, \quad \theta_{acc,n}>\theta
\end{cases}
\tag{18}
$$
递推形式将实部虚部分别写出，可表示为
$$x_{-1}+iy_{-1}=\omega\cdot K_m, \\
x_{n+1}=x_n-\sigma_n\cdot y\cdot2^{-k}\\
y_{n+1}=y_n+\sigma_n\cdot x\cdot2^{-k}$$

至此，可以得出以下数学公式形式的伪代码：<br>
$const\quad\mathbb{R}\quad K_m\leftarrow\prod_{k=0}^{m}\cfrac{1}{\sqrt{1+2^{-2k}}}$<br>
$const\quad\mathbb{R}\quad \{\alpha_m\}, \alpha_k\leftarrow\arctan(2^{-k})$<br>
$param\quad\mathbb{C}\quad\omega$<br>
$param\quad\mathbb{R}\quad\theta$<br>
$\mathbb{R}\quad\sigma_{var}$<br>
$\mathbb{C}\quad\omega_{iter}\leftarrow\omega\cdot K_m$<br>
$(\omega_{iter}=x_{iter}+iy_{iter})$<br>
$\mathbb{R}\quad\theta_{iter}\leftarrow0$<br>
$for(int\quad k\leftarrow0;k\le m;++k)\{$<br>
$\quad if(\theta_{iter}\le \theta)\quad\{$<br>
$\quad\quad \sigma_{var}\leftarrow1$<br>
$\quad\}$<br>
$\quad else\{$<br>
$\quad\quad \sigma_{var}\leftarrow-1$<br>
$\quad\}$<br>
$\quad \theta_{iter}+=\sigma_{var}\cdot\alpha_k$<br>
$\quad\omega_{iter}\leftarrow\omega_{iter}\cdot(1+i\cdot\sigma_{var}\cdot2^{-k})$<br>
$\quad (x_{iter}\leftarrow x_{iter}-\sigma_{var}(y_{iter}\gg k))$<br>
$\quad (y_{iter}\leftarrow y_{iter}+\sigma_{var}(x_{iter}\gg k))$<br>
$\}$<br>
$return\quad\omega_{iter}$<br>
其中“$\gg$”表示二进制右移。

$K_m$和$\{\alpha_m\}$为恒量，在给定m的情况下可在计算机上一次性计算得出，无需在FPGA上多做运算。

哪些数据类型可以在FPGA上使用二进制位移操作？至少float是不支持位移操作的。