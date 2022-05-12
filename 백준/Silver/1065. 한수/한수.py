N=int(input())
x=[]

if N<100:
    print(N)
elif (N>=100 and N<1001):
    for i in range(100,N+1):
        a=list(str(i))
        a=list(map(int,a))
        T=a[0]-a[1]
        if(a[1]-a[2])==T:
            x.append(i)
    print(len(x)+99)