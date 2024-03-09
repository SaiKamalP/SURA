import matplotlib.pyplot as plt
import numpy as np
import sys

file = sys.argv[1]
data = ""
print(file)
with open(file,"r") as f:
    data = f.read()
data = data.split('\n')
a = int(data[0])
c = int(data[a])
s = int(data[2*a])

X1=[]
Y1=[]
for i in range(1,a):
    Yi = list(map(int,data[i].split(", ")[:-1]))
    Xi = [i]*len(Yi)
    X1 = X1+Xi
    Y1 = Y1+Yi
X2=[]
Y2=[]
for i in range(1,a):
    Yi = list(map(int,data[a+i].split(", ")[:-1]))
    Xi = [i]*len(Yi)
    X2 = X2+Xi
    Y2 = Y2+Yi
plt.plot(X1,Y1,"or")
plt.plot(X2,Y2,"ob")
plt.plot(s,c,"og")
for i in range(len(X1)):
    plt.text(X1[i]+0.05,Y1[i]+0.05,str(Y1[i]))
plt.xlim((0,a))
plt.show()