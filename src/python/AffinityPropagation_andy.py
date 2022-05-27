import math,statistics
#affinity propagation code
#by andyandy

#decay factor lambda
lmda = 0.5


#select s_input or coor_input
coor_input=True


if coor_input:
    #region input
    input_filename = "ap_3d_test4"
    coordinates = open(input_filename + ".txt",'r')
    coor = []   
    lines = coordinates.readlines()
    coordinates.close()
    for line in lines:
        coor.append(tuple(map(float,line.split())))
    n=coor.pop(0)[0]
    n=int(n+.5)
    #endregion

    if len(coor[0])==3:
        is_3d=True
    elif len(coor[0])==2:
        is_3d=False
    else:
        raise IndexError("Input File Invalid(Length of lines are not 2 or 3)")
    def simil(i,j): # may be changed
        return -math.sqrt((coor[i][0]-coor[j][0])**2+(coor[i][1]-coor[j][1])**2 + (0 if not is_3d else (coor[i][2]-coor[j][2])**2))
    s=[[0]*n for i in range(n)]
    isum=[]
    #if s(i,j)==s(j,i)
    lengths = []
    for i in range(n):
        for j in range(i):
            tmp=simil(i,j)
            s[j][i]=tmp
            s[i][j]=tmp
            lengths.append(tmp)

    for i in range(n):
        s[i][i]=statistics.median(lengths)

else:
    input_filename = "similarity_matrix_1"
    file = open(input_filename+".txt",'r')
    s=[]
    lines = file.readlines()
    file.close()
    for line in lines:
        s.append(list(map(float,line.split())))
    n=s.pop(0)[0]
    n=int(n+.5)

a=[[0]*n for i in range(n)]
r=[[0]*n for i in range(n)]
#iter iterations
iter = 100     
for it in range(iter):
    print(f"{100*it/iter}%")
    #r(i,k)
    for i in range(n):
        twomax = [-math.inf, -math.inf]
        ind_twomax = [-1,-1]
        for kk in range(n):
            tmp=a[i][kk]+s[i][kk]
            if tmp>twomax[0]:
                twomax[1]=twomax[0]
                twomax[0]=tmp 
                ind_twomax[1]=ind_twomax[0]
                ind_twomax[0]=kk
            elif tmp>twomax[1]:
                twomax[1]=tmp
                ind_twomax[1]=kk

        for k in range(n):
            if ind_twomax[0]==k:
                r[i][k]*=lmda
                r[i][k]+=(s[i][k]-twomax[1])*(1-lmda)
            else:
                r[i][k]*=lmda
                r[i][k]+=(s[i][k]-twomax[0])*(1-lmda)

    #a(i,k)
    for k in range(n):
        tmpsum = 0
        for ii in range(n):
            tmpsum += max(0,r[ii][k])
        for i in range(k):
            a[i][k]*=lmda
            a[i][k]+=(min(0,r[k][k]+tmpsum-max(0,r[i][k])-max(0,r[k][k])))*(1-lmda)

        a[k][k]*=lmda
        a[k][k]+=(tmpsum-max(0,r[k][k]))*(1-lmda)

        for i in range(k+1,n):
            a[i][k]*=lmda
            a[i][k]+=(min(0,r[k][k]+tmpsum-max(0,r[i][k])-max(0,r[k][k])))*(1-lmda)

output = []
for i in range(n):
    tmp = -math.inf
    tmpind = -1
    for k in range(n):
        if a[i][k]+r[i][k]>tmp:
            tmpind = k
            tmp=a[i][k]+r[i][k]
    #print(tmpind,end=" ")
    output.append(tmpind)
print(*output)

output_file = open(input_filename+'_output.txt','w')
for x in output:
    output_file.write(str(x)+" ")
output_file.close()
