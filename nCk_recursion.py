def choose(n,k):
    if k==0 or n==k:
        print(str(n)+'C'+str(k),'=',1)
        return 1
    elif n<k:
        return 0
    else:
        print(str(n)+'C'+str(k),'=',str(n-1)+'C'+str(k-1),'+',str(n-1)+'C'+str(k))
    x=choose(n-1,k-1)+choose(n-1,k)
    print(str(n)+'C'+str(k),'=',x)
    return x

n=int(input())
k=int(input())
choose(n,k)
