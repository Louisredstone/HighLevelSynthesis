首先检查是否已经生成ssh-key
```
>ssh -T git@github.com
```
若结果为
```
Hi Louisredstone! You've successfully authenticated, but GitHub does not provide shell access.
```
则已生成ssh-key<br>
如未生成，使用如下命令以生成：
```
ssh-keygen -t rsa -C "zzy2900920898@163.com"
```
默认路径是"C:\\Users\\\<yourname\>\\.ssh\\id_rsa"
生成后打开该文件，并将该串字符加入到你的库中。详见<a>https://www.runoob.com/git/git-remote-repo.html<a>
```
>git remote add origin "https://github.com/Louisredstone/HighLevelSynthesis"
```