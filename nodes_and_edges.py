node={} #Global variable with key as node ID (an integer), value as name of the node.
edge={} #Global variable with key as the node ID (an integer), value as a set of neighbor node ID(s) 

def InsertNode(id,name):
    count=0
    if id not in node:
        node[id]=name
    else:
        count+=1
    if count>0:
        print('ID exists.')
    
    return

def InsertEdge(id1,id2):
    count=0
    #print(id1,id2)
    #print(node)
    #print(id1 in node)
    #print(id2 in node)
    a=id1 in node
    b=id2 in node
    if a==True and b==True:
        if int(id1) not in edge:
            edge[int(id1)]=[]
            edge[int(id1)].append(int(id2))
            #print('*')
        else: 
            if id2 not in edge[id1]:
                edge[int(id1)].append(int(id2))
            else:
                print('Edge exists.')
                #print('**')
    else:
        count+=1
    if count>0:
        print('No such node.')
    return

def CommonNeighbor(id1,id2):
    if (id1 in node) and (id2 in node):
        if (id1 not in edge) or (id2 not in edge):
            print('No common neighbor.')
        else:
            e=edge[id1]
            count=0
            for i in range(len(e)):
                if e[i] in edge[id2]:
                    print(e[i],node[e[i]])
                    count+=1
            if count==0:
                print('No common neighbor.')
                
    else:
        print('No such node.')
    return

def ShortestPath(src,des):
    count = 0
    if src==des:
        print(src,node[src])
    else:
        if (src not in edge) or (des not in edge):
            print('No path found.')
        else:
            if len(edge[src]) != 0:
                for i in edge:
                    for j in edge[i]:
                        if j == des:
                            count += 1
            if count == 0:
                print('No path found.')
            else:
                q=[] #for remembering the node to search
                visited={} #for remembering if a node is visited or not
                previous={} #for remembering the previous node in a path
                q.append(src)
                for i in range(len(node)+1):
                    visited[i]=False
                visited[src]=True
                dust=1
                while (visited[des]==False and len(q)!=0):
                    current=q.pop(0)
                    #print(current)
                    for n in edge[current]:
                        if visited[n]==False:
                            q.append(n)
                            visited[n]=True
                            dust+=1
                            previous[n]=current
                if len(q)==0:
                    print('No path found.')
                else:
                    s=[]
                    track=des
                    s.append(str(des))
                    while track!=src:
                        s.append(str(previous[track]))
                        track=previous[track]
                    yeseo=s[::-1]
                    for i in yeseo:
                        print(int(i),node[int(i)])
    return

def main():
    
    command=input().split()
    while(command[0]!="END"):
        if (command[0]=="InsertNode"):
            InsertNode(int(command[1]),command[2])
            #print(node)
        elif (command[0]=="InsertEdge"):
            InsertEdge(int(command[1]),int(command[2]))
            #print(edge)
        elif (command[0]=="CommonNeighbor"):
            CommonNeighbor(int(command[1]),int(command[2]))
        elif (command[0]=="ShortestPath"):
            ShortestPath(int(command[1]),int(command[2]))
        command=input().split()
    return

main()
