#coding:utf-8
import math
import random

def Km(m):
    # Km(∞)~=0.6072529350088812561694
    result=1
    tmp=1 #==2**(-2*k)
    for k in range(m+1):
        result/=math.sqrt(1+tmp)
        tmp/=4
    return result

def alpha_m(m):
    #本函数中alpha按弧度记
    result=[]
    alpha=0
    tmp=1 #==2**(-k)
    for k in range(m+1):
        alpha=math.atan(tmp)
        tmp/=2
        result.append(alpha)
    return result

m=15
print("float Km=",Km(m),";",sep="")
print("float cordic_phase[",m+1,"]={",sep="",end="")
for alpha in alpha_m(m):
    print(alpha,",",sep="",end="")
print("\b};")
print("")

x_list=[]
y_list=[]
theta_list=[]
x__list=[]
y__list=[]
for i in range(10):
    x=random.random()*256-128
    y=random.random()*256-128
    theta=random.random()*2*math.pi-math.pi
    x_list.append(x)
    y_list.append(y)
    theta_list.append(theta)
    x__list.append(x*math.cos(theta)-y*math.sin(theta))
    y__list.append(y*math.cos(theta)+x*math.sin(theta))
for s,l in [("x_list",x_list),
            ("y_list",y_list),
            ("theta_list",theta_list),
            ("x__list",x__list),
            ("y__list",y__list)]:
    print("float ",s,"[",len(l),"]={",sep="",end="")
    for i in range(len(l)):
        print(l[i],",",sep="",end="")
    print("\b};")