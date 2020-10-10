#give an array input
ip=list(map(int,input().split()))
i,j,summ,maxsum=0,0,0,0

#check for the 1st positive number
while(i<len(ip)-1 and ip[i]<0):
    i=i+1

#add it to sum and traverse through the array
summ=summ+ip[i]
j=i+1

#if encountered element is positive go on adding to sum
#if negative element is encountered store the previous maximum sum
#and start over from the next positive element
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

#print the maximum consecutive sum
print(maxsum)
