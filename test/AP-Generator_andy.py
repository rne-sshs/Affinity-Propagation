import random

is_3d = True

n=500
filename = 'ap_3d_test2'
maxcoor = 1000

file = open(filename+'.txt','w')
file.write(str(n)+"\n")

if is_3d:
    for i in range(n):
        r1=random.uniform(0,maxcoor)
        r2=random.uniform(0,maxcoor)
        r3=random.uniform(0,maxcoor)
        file.write(f"{r1} {r2} {r3}\n")
        
else:
    for i in range(n):
        r1=random.uniform(0,maxcoor)
        r2=random.uniform(0,maxcoor)
        file.write(f"{r1} {r2}\n")
    file.close()
