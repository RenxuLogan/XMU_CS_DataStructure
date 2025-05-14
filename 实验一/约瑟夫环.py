inputs=input().split()
n=int(inputs[0])
p=int(inputs[-1])
a=[]
for i in range(n):
    a.append(i+1)
i=0
while(len(a)>1):
    count = 1
    while(count != p ):
        count+=1
        i=(i+1)%len(a)
    print(a.pop(i),end=" ")
    if(i==len(a)):
        i=0
    else:
        continue
print(a.pop())
