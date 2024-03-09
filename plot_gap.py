import matplotlib.pyplot as plt
import numpy as np
import sys

file = sys.argv[1]
data = ""
with open(file,"r") as f:
    data = f.read()
data = data.split('\n')
a = int(data[0])

X=[]
Y=[]
for i in range(1,a):
    Yi = list(map(int,data[i].split(", ")[:-1]))
    Xi = [i]*len(Yi)
    X = X+Xi
    Y = Y+Yi
plt.plot(X,Y,"ob")
for i in range(len(X)):
    plt.text(X[i]+0.05,Y[i]+0.05,str(Y[i]))
plt.xlim((0,a))
plt.show()