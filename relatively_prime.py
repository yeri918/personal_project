numbers=input('Numbers: ').split()

a=list(numbers)
b=[int(i) for i in a]
#converts the values in the list to integers 
b.sort()

d=[]
#list for storing the divisors 

#print(min(b))
check=0
for s in b:
    d.clear()
    for i in range(2,int(s)+1):
        if s%i==0: 
            d.append(i)
    #print(d)
    #list of divisors of the min. value 

    f=[1]
    for i in d:
        count=0
        #print(i)
        for j in b:
            if j%i==0:
                #example 12%2==0
                count+=1
        f.append(count)
        #print(f)
        #the number of common divisors 


    #print(max(f))
    #print(len(b))

    if max(f)==len(b):
        print('~')
        break
    elif max(f)==1:
        #print('prp')
        check+=1
        if check==len(b):
            print('prp')
            break
        continue
    else:
        print('mrp')
        break

