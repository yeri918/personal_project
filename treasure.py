treasure=[]
map=[]
tinput=input()
y=[]
count=0
for i in tinput:
    y.append(int(i))
treasure.append(y)
while len(tinput)==len(treasure[0]):
    tinput=input()
    y=[]
    for i in tinput:
        y.append(int(i))
    if len(tinput)==len(treasure[0]):
        treasure.append(y)
    else:
        map.append(y)
        count+=1
        
while count!=len(map[0]):
    tinput=input()
    y=[]
    for i in tinput:
        y.append(int(i))
    map.append(y)
    count+=1

def rotation(item,k):
    rotated=[]
    d=len(item)-1
    if k%4==1:
        for i in range(len(item)):
            x=[]
            for j in range(len(item[i])):
                x.append(item[d-j][i])
            rotated.append(x)
    if k%4==2:
        for i in range(len(item)-1,-1,-1):
            x=[]
            for j in range(len(item)-1,-1,-1):
                x.append(item[i][j])
            rotated.append(x)
    if k%4==3:
        for i in range(len(item)-1,-1,-1):
            x=[]
            for j in range(len(item)):
                x.append(item[j][i])
            rotated.append(x)
    if k%4==0:
        for i in range(len(item)):
            x=[]
            for j in range(len(item)):
                x.append(item[i][j])
            rotated.append(x)
    return rotated

a=rotation(treasure,1)
b=rotation(treasure,2)
c=rotation(treasure,3)
d=rotation(treasure,4)

#print('a: ',a)
#print('b: ',b)
#print('c: ',c)
#print('d: ',d)


s1=len(treasure)
s2=len(treasure)

while s1<=len(map):
    possible=[]
    for i in range(s1-len(treasure),s1):
        n=[]
        for j in range(s2-len(treasure),s2):
            n.append(map[i][j])
        possible.append(n)
        
    if possible==a or possible==b or possible==c or possible==d:
        print(s2-len(treasure),s1-len(treasure))
        break
    else:
        s2+=1
    if s2>len(map):
        s1+=1
        s2=len(treasure)


#print(treasure,'***')
    
