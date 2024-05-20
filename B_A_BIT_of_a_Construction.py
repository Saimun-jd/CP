def bi(binary_list):
    decimal_number = 0
    for i, bit in enumerate(binary_list[::-1]):
        decimal_number += bit * (2 ** i)
    return decimal_number

def con(decimal):
    binary_list = [int(bit) for bit in bin(decimal)[2:]]
    return binary_list
for _ in range(int(input())):
    n,k = map(int, input().split())
    l=con(k)
    
    lent = len(l[l.index(0):]) if 0 in l else 0
    if len(l)-lent==1:
        ans=[1]*lent
    else:
        ans=[1]*len(l)
        ans[len(l)-lent-1]=0
    m=bi(ans)
    ans2=[0]*n
    ans2[0]=m
    for i in range(1,n):
        if k-(m+i)>0:
            if i==n:
                ans2[i]=k-(m+i)
            else:
                ans2[i]=1
    print(*ans2)