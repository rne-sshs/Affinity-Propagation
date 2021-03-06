Affinity-Propagation
========
2022 SSHS R&E 

* 김선웅(seonu)
* 이지후(numbering)
* 박세진(exabyte)
* 정현우(andy)


내용
--------

### Affinity Propagation
> __Clustering by Passing Messages Between Data Points__  
  Brendan J. Frey and Delbert Dueck (January 11, 2007)
 _Science_ __315__ (5814), 972-976. [doi: 10.1126/science.1136800] [Link](http://utstat.toronto.edu/reid/sta414/frey-affinity.pdf)

> __Beyond Affinity Propagagion: Message Passing Algorithms for Clustering__  
  Givoni, I. Ella (August 21, 2012)
  [Link](https://hdl.handle.net/1807/32721)


위 논문들을 참고하여 AP의 구현체 코드 작성 (C++, Python, JavaScript)

- - -



### How to use
> 필요한 데이터를 넣을 수도 있고, 없다면 랜덤 데이터를 생성할 수도 있다. (2차원 혹은 3차원) 
1. s 행렬을 넣기 (coor_input=False 인 경우)
>input 데이터 형식:  
```    
n  
s11 s12 s13 ... s1n
s21 s22 s23 ... s2n 
...  
sn1 sn2 sn3 ... snn
```
2. 좌표로 넣기 (coor_input=True 인 경우)
>랜덤 데이터: [Random Data Generator](https://github.com/rne-sshs/Affinity-Propagation/blob/main/test/AP-Generator_andy.py) 를 n, filename, maxcoor, is_3d를 정하고 실행하면 해당 디렉토리에 "{filename}.txt" 의 이름으로 랜덤 테이터가 생긴다.
>    > n: number of data points  
filename: name of file  
maxcoor: each coordinate is selected randomly from [0,maxcoor)  
is_3d: determines whether points are on 2d plane or 3d space  



>input 데이터 형식:  
(is_3d = False)
```    
n  
x1 y1  
x2 y2  
x3 y3  
...  
xn yn
```
> (is_3d = True)
```    
n  
x1 y1 z1  
x2 y2 z2  
x3 y3 z3  
...  
xn yn zn  
```

### Clustering

#### [Affinity Propagation code](https://github.com/rne-sshs/Affinity-Propagation/blob/main/src/python/AffinityPropagation_andy.py) 를 같은 디렉토리에서 실행하면 "{filename}_output.txt" 가 생성된다.  
(coor_input, simil 등 조절)

>출력 데이터 형식:  
```    
e1 e2 e3 ... en
```
(e _i_ = index of exemplar of _i_-th point)
### Visualization

#### is_3d = False 인 경우
[Visualization code(2D)](https://github.com/rne-sshs/Affinity-Propagation/blob/main/src/python/VisualAffinityPropagation_andy.py) 를 같은 디렉토리에서 실행하면 "{filename}.png" 가 생성된다.
#### is_3d = True 인 경우
[Visualization code(3D)](https://github.com/rne-sshs/Affinity-Propagation/blob/main/src/python/VisualAffinityPropagation3D_andy.py) 를 같은 디렉토리에서 실행하면 "{filename}.png" 가 생성된다.
 - - -

## Results (visualized with matplotlib)

### 2D Results
![ap_test6](https://user-images.githubusercontent.com/89206053/170421893-2c4a8747-5aec-4850-a9ff-caab929c888d.png)

![ap_test5](https://user-images.githubusercontent.com/89206053/170421632-f709bcc7-3aa3-4d2c-ba5b-fe9166cffd93.png)

![ap_test4](https://user-images.githubusercontent.com/89206053/170420856-b8dab248-9d7c-4ac3-8356-f416f82c19c0.png)

- - -
### 3D Results 
![ap_3d_test1](https://user-images.githubusercontent.com/89206053/170478790-81ce0a07-73b3-4fac-9d15-d08cc15be26d.png)  

![ap_3d_test3](https://user-images.githubusercontent.com/89206053/170483712-9bf1f657-26f1-43e0-8f9a-bae6b222166b.png)

![ap_3d_test2](https://user-images.githubusercontent.com/89206053/170478445-b28facf7-7780-4fa6-9768-419370620f03.png)