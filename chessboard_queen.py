n,m=input().split()
location=[]
for i in range(int(m)):
    position=input().split()
    location.append(position)
    #print(location)

#board with x and y
board={}
for i in range(1,int(n)+1):
    board[i]=[]
    for j in range(int(n)):
        board[i].append('o')
#print(board)

def changingtox(gameboard,row,column):
    if gameboard[row][column]!='x':
        gameboard[row][column]='x'
    return

def diagonal(x, y):
    # from left to diagonally across the board
    if x >= y:
        d = x - y
        for i in range(1 + d, len(board) + 1):
            changingtox(board, i, i - (d + 1))
    elif x < y:
        d = y - x
        # from left to diagonally across the board
        for i in range(1, len(board) - d + 1):
            changingtox(board, i, i + (d - 1))
    
    #from right to diagonally across the board
    if (y-1)>(len(board)-x):
        d=len(board)-x
        p=len(board)
        q=y-d-1
        while q<=(len(board)-1):
            changingtox(board,p,q)
            p-=1
            q+=1
    elif (y-1)<=(len(board)-x):
        d=x-1
        p=1
        q=y+d-1
        while q>=0:
            changingtox(board,p,q)
            p+=1
            q-=1
            #print('*',p,q)
    return board

def row(x,y):
    for i in range(len(board)):
        changingtox(board,x,i)
    return board

def column(x,y):
    for i in range(1,len(board)+1):
        changingtox(board,i,y-1)
    return board

def complete(x,y):
    diagonal(x,y)
    row(x,y)
    column(x,y)
    return board

def main():
    for i in range(len(location)):
        a=int(location[i][0])
        b=int(location[i][1])
        complete(a,b)
    count=0
    for i in range(1,len(board)+1):
        for j in range(len(board)):
            if board[i][j]=='o':
                count+=1
    print(count)
    return 
    
main()
