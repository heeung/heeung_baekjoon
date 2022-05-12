x=[]
for i in range(0,10000):
    T=list(str(i))
    T=list(map(int,T))
    d=i+sum(T)
    x.append(d)
for j in range(0,10000):
    if j not in x:
        print(j)