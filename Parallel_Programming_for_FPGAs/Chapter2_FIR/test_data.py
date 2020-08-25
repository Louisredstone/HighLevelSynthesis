import random

def print_with_br(x,n=16):
    print("{",end='')
    i=0
    while(i<len(x)):
        print(x[i],end=',')
        if((i+1)%n==0):
            print('')
        i+=1
    print('\b\b}')

Nx=128

x=[]
for i in range(Nx):
    x.append(int(round(random.random()*64,0)))
print_with_br(x,16)
h=[53,0,-91,0,313,500,313,0,-91,0,53]

def conv_1d(x,h):
    x=[0]*(len(h)-1)+x
    result=[]
    for i in range(len(h)-1,len(x)):
        acc=0
        for j in range(len(h)):
            acc+=h[j]*x[i-j]
        result.append(round(acc,2))
    return result

print_with_br(conv_1d(x,h),16)

