# Secretary Optimization

import random
import math
import matplotlib.pyplot as plt
from numpy import max, arange
from numpy import random as rand
from scipy.optimize import curve_fit
from matplotlib.ticker import MaxNLocator

# candidates and weights

candidate = list()
for i in range(100):
    candidate.append(random.randint(2,100))

# probability formula

def arg(j):
    return 1/(j-1)

def secretary(r, n):
    terms = list()
    for i in range(r, n):
        terms.append(arg(i))
    return ((r-1)/n)*(sum(terms))

n=len(candidate)
x = arange(2,100,1,dtype=int)
y = list()
for i in range(len(x)):
    y.append(secretary(x[i],n))
y_noised = (y + rand.uniform(0.0, 0.01, len(x)))*100

maxpair = list()
for i in range(len(x)):
    if y_noised[i]==max(y_noised):
        maxpair.append(x[i])
        maxpair.append(y_noised[i])
    else:
        i=i+1

# graph

plt.figure(figsize=(12,8), dpi= 80)
plt.plot(x , y_noised, color = 'tab:red', linewidth=3, zorder=1)

# dotted lines for max pair
plt.plot((0,maxpair[0]), (maxpair[1], maxpair[1]), color = 'black', linestyle='--', alpha=0.4) # horizontal
plt.plot((maxpair[0],maxpair[0]), (0,maxpair[1]), color = 'black', linestyle='--',alpha=0.4) # vertical

# axes
plt.xlabel('Percentage of suitors rejected', fontsize=17, fontweight=550); plt.xticks(fontsize=15)
plt.ylabel('Chance of Success (%)', fontsize=17, fontweight=550); plt.yticks(fontsize=15)
plt.xlim(xmin=0)
plt.ylim(ymin=0)

# grid
plt.grid(axis='both', alpha=.3)
plt.gca().spines["top"].set_alpha(0.0)    
plt.gca().spines["bottom"].set_alpha(0.3)
plt.gca().spines["right"].set_alpha(0.0)    
plt.gca().spines["left"].set_alpha(0.3) 

plt.show()