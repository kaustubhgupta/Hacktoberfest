ip=list(map(int,input().split()))
i,j,summ,maxsum=0,0,0,0
while(i<len(ip)-1 and ip[i]<0):
    i=i+1
summ=summ+ip[i]
j=i+1
while( j<len(ip)):
    if(ip[j]>=0):
        summ=summ+ip[j]
        j=j+1
    else:
        if(summ>maxsum):
            maxsum=summ
        i=j
        while(i<len(ip)-1 and ip[i]<0):
            i=i+1
        summ=ip[i]
        j=i+1
if(summ>maxsum):
    maxsum=summ
print(maxsum)
