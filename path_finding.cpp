#include <iostream>
using namespace std;

struct Coordinates{
  int y,x;
};
struct arrStruct{
  int arr[5][2];
};
Coordinates findone(int **arr, int h, int w){
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      if (arr[i][j]==1){
        Coordinates one={i,j};
        return one;
      }
    }
  }
  Coordinates none={-1,-1};
  return none;
}
arrStruct findzero(int **arr, int h, int w,Coordinates pos){
  arrStruct zero;
  int xc=pos.x, yc=pos.y;
  int tracker=1;
  if ((yc-1)>=0 && (yc+1<h)){
    if(yc+1<h){
      if(arr[yc+1][xc]==0){
        zero.arr[tracker][0]=yc+1;
        zero.arr[tracker][1]=xc;
        tracker+=1;
      }else if (arr[yc+1][xc]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
    if(xc-1>=0){
      if (arr[yc][xc-1]==0){
        zero.arr[tracker][0]=yc;
        zero.arr[tracker][1]=xc-1;
        tracker+=1;
      }else if (arr[yc][xc-1]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
    if (xc+1<w){
      if (arr[yc][xc+1]==0){
        zero.arr[tracker][0]=yc;
        zero.arr[tracker][1]=xc+1;
        tracker+=1;
      }else if (arr[yc][xc+1]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
    if (yc-1>=0){
      if (arr[yc-1][xc]==0){
        zero.arr[tracker][0]=yc-1;
        zero.arr[tracker][1]=xc;
        tracker+=1;
      }else if (arr[yc-1][xc]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
  }else if((yc-1<0) && yc+1<h){
    if(yc+1<h){
      if(arr[yc+1][xc]==0){
        zero.arr[tracker][0]=yc+1;
        zero.arr[tracker][1]=xc;
        tracker+=1;
      }else if (arr[yc+1][xc]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
    if(xc-1>=0){
      if (arr[yc][xc-1]==0){
        zero.arr[tracker][0]=yc;
        zero.arr[tracker][1]=xc-1;
        tracker+=1;
      }else if (arr[yc][xc-1]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
    if (xc+1<w){
      if (arr[yc][xc+1]==0){
        zero.arr[tracker][0]=yc;
        zero.arr[tracker][1]=xc+1;
        tracker+=1;
      }else if (arr[yc][xc+1]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
  }else if((yc-1>=0)&& (yc+1==h)){
    if(xc-1>=0){
      if (arr[yc][xc-1]==0){
        zero.arr[tracker][0]=yc;
        zero.arr[tracker][1]=xc-1;
        tracker+=1;
      }else if (arr[yc][xc-1]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
    if (xc+1<w){
      if (arr[yc][xc+1]==0){
        zero.arr[tracker][0]=yc;
        zero.arr[tracker][1]=xc+1;
        tracker+=1;
      }else if (arr[yc][xc+1]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
    if (yc-1>=0){
      if (arr[yc-1][xc]==0){
        zero.arr[tracker][0]=yc-1;
        zero.arr[tracker][1]=xc;
        tracker+=1;
      }else if (arr[yc-1][xc]==-2){
        zero.arr[0][0]=-2;
        return zero;
      }
    }
  }
  zero.arr[0][0]=tracker-1;
  return zero;
}
//main function
int main(){
  int height, width;
  cin >> height >> width;

  int **map = new int*[height];
  for (int i=0;i<height;i++){
    map[i]= new int[width];     //array size of height x width
  }

  int input;
  for (int i=0;i<height;i++){
    for (int j=0;j<width;j++){
      cin >> map[i][j];
    }
  }                             //map formed

  Coordinates one=findone(map,height,width);      //one.y, one.x

  //from here solve the problems.
  int wait1[20][2], wait2[20][2],k=1;
  wait1[0][0]=1;
  wait2[0][0]=0;
  wait1[1][0]=one.y;
  wait1[1][1]=one.x;
  arrStruct zero_lists;
  int found=0;
  int output=1;
  while(true){
    k=1;
    wait2[0][0]=0;
    for (int i=1;i<wait1[0][0]+1;i++){
      Coordinates pos={wait1[i][0],wait1[i][1]};
      zero_lists=findzero(map,height,width,pos);
      if (zero_lists.arr[0][0]==-2){
        found=1;
        break;
      }else{
        wait2[0][0]+=zero_lists.arr[0][0];
        if (zero_lists.arr[0][0]==0){
          continue;
        }else{
          for (int j=1;j<zero_lists.arr[0][0]+1;j++){
            wait2[k][0]=zero_lists.arr[j][0];
            wait2[k][1]=zero_lists.arr[j][1];
            map[zero_lists.arr[j][0]][zero_lists.arr[j][1]]=output;
            k+=1;
          }
        }
      }
    }
    output+=1;
    if (found==1){
      cout << output-1 << endl;
      break;
    }
    if (k==1){
      cout << "No" << endl;
      break;
    }

    wait1[0][0]=0;
    k=1;
    for (int i=1;i<wait2[0][0]+1;i++){
      Coordinates pos={wait2[i][0],wait2[i][1]};
      zero_lists=findzero(map,height,width,pos);
      if (zero_lists.arr[0][0]==-2){
        found=1;
        break;
      }else{
        wait1[0][0]+=zero_lists.arr[0][0];
        if (zero_lists.arr[0][0]==0){
          continue;
        }else{
          for (int j=1;j<zero_lists.arr[0][0]+1;j++){
            wait1[k][0]=zero_lists.arr[j][0];
            wait1[k][1]=zero_lists.arr[j][1];
            map[zero_lists.arr[j][0]][zero_lists.arr[j][1]]=output;
            k+=1;
          }
        }
      }
    }
    output+=1;
    if (found==1){
      cout << output-1 << endl;
      break;
    }
    if (k==1){
      cout << "No" << endl;
      break;
    }
  }
  delete [] map; 
}
