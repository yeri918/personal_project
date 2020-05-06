size=int(input('Size--> '))
l=[]
a=size**2
for i in range(a):
    l.append(i)

#board
count=0
for i in l:
    if count!=size-1:
        if i<=9:
            print(' '+str(i),end=' ')
        else: 
            print(i,end=' ')
        count+=1
    elif count==size-1:
        if i<=9:
            print(' '+str(i))
        else: 
            print(i)
        count=0
        

#s1->column 
def s1():
    wow=0
    for i in range(size):
        count=0
        for j in range(i,a-size,size):
            if l[j]==l[j+size]:
                count+=1
        if count==size-1:
            wow+=1
    if wow>0:
        return True
    else:
        return False
#s2->row     
def s2():
    wow=0
    for i in range(0,a,size):
        count=0
        for j in range(i,i+size-1,1):
            if l[j]==l[j+1]:
                count+=1
        if count==size-1:
            wow+=1
    if wow>0:
        return True
    else:
        return False
        
def s3():
    wow=0
    count=0
    for i in range(0,a-size,size+1):
        #print('***',i,end=' ')
        if l[i]==l[i+size+1]:
            count+=1
    if count==size-1:
        wow+=1
    if wow>0:
        return True
    else:
        return False
def s4():
    wow=0
    count=0
    for i in range(size-1,a-size,size-1):
        if l[i]==l[i+size-1]:
            count+=1
    if count==size-1:
        wow+=1
    if wow>0:
        return True
    else:
        return False

v=0
times=0
while s1()==False and s2()==False and s3()==False and s4()==False:
    if times==a:
        print('Winner: None')
        v=2
        break
    times+=1
    if v==0:
        x=int(input('X--> '))
        for i in range(a):
            if l[i]==x:
                l[i]='X'
        v=1
    elif v==1:
        o=int(input('O--> '))
        for i in range(a):
            if l[i]==o:
                l[i]='O'
        v=0
    #printing the board again
    count=0
    for i in l:
        if count!=size-1:
            if len(str(i))==1:
                print(' '+str(i),end=' ')
            else:
                print(str(i),end=' ')
            count+=1
        elif count==size-1:
            if len(str(i))==1:
                print(' '+str(i))
            else:
                print(str(i))
            count=0

if v==0:
    print('Winner: O')
elif v==1:
    print('Winner: X')
