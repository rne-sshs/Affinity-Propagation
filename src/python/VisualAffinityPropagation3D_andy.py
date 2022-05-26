from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import random
import numpy as np

def randcolor():
    return "#"+''.join([random.choice('ABCDEF0123456789') for i in range(6)])

#region input
input_filename = "ap_3d_test1"
coordinates = open(input_filename + ".txt",'r')
coor = []
lines = coordinates.readlines()
for line in lines:
    coor.append(tuple(map(float,line.split())))
n=coor.pop(0)[0]
n=int(n+.5)
exemplars = []
exem = open(input_filename + '_output.txt','r')
line = exem.readline()
exemplars = list(map(int,line.split()))
#endregion

colordict = {}

for exemplar in set(exemplars):
    colordict[exemplar]=randcolor()


fig = plt.figure(figsize=(9,6))
ax = fig.add_subplot(111, projection = '3d')


for i in range(n):
    if i==exemplars[i]:
        ax.scatter(np.array([coor[i][0]]),np.array([coor[i][1]]),np.array([coor[i][2]]), color = colordict[exemplars[i]], alpha = 1)
        #plt.plot([coor[i][0]],[coor[i][1]],color = colordict[exemplars[i]], marker = 'D')
    else:
        ax.plot(np.array([coor[i][0],coor[exemplars[i]][0]]),np.array([coor[i][1],coor[exemplars[i]][1]]),np.array([coor[i][2],coor[exemplars[i]][2]]),color = 'black')
        ax.scatter(np.array([coor[i][0]]),np.array([coor[i][1]]),np.array([coor[i][2]]), color = colordict[exemplars[i]], alpha = 0.7)
        
        # plt.plot([coor[i][0]],[coor[i][1]],color = colordict[exemplars[i]], marker = 'o')
        # plt.plot([coor[i][0],coor[exemplars[i]][0]],[coor[i][1],coor[exemplars[i]][1]],color = 'black')
plt.title('Clustering Points by Affinity Propagation ('+r'$n=$'+str(n)+'), 3D', size = 14)

plt.savefig(input_filename+".png", dpi = 800)
plt.show()