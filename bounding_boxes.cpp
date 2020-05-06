#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int main(){
  float inputx, inputy, inputw, inputh, inputr;
  float a,b,c,d,xr,xl,yr,yl;
  float x,y,width,height;
  float px,py;
  int n;
  char geo;
  cin >> geo;
  if (geo=='R'){
    cin >> inputx >> inputy >> inputw >> inputh;
    xr=inputx+(inputw/2);
    xl=inputx-(inputw/2);
    yr=inputy+(inputh/2);
    yl=inputy-(inputh/2);
  }else if (geo=='C'){
    cin >> inputx >> inputy >> inputr;
    xr=inputx+inputr;
    xl=inputx-inputr;
    yr=inputy+inputr;
    yl=inputy-inputr;
  }else if (geo=='P'){
    cin >> n;
    cin >> inputx >> inputy;
    xr=xl=inputx;
    yr=yl=inputy;
    for (int i=0;i<(n-1);i++){
      cin >> inputx >> inputy;
      xr=max(xr,inputx);
      xl=min(xl,inputx);
      yr=max(yr,inputy);
      yl=min(yl,inputy);
    }
  }
  cin >> geo;
  while (geo!='#'){
    if (geo=='R'){
      cin >> inputx >> inputy >> inputw >> inputh;
      a=inputx+(inputw/2);
      b=inputx-(inputw/2);
      c=inputy+(inputh/2);
      d=inputy-(inputh/2);
      xr=max(xr,a);
      xl=min(xl,b);
      yr=max(yr,c);
      yl=min(yl,d);
    }
    else if (geo=='C'){
      cin >> inputx >> inputy >> inputr;
      a=inputx+inputr;
      b=inputx-inputr;
      c=inputy+inputr;
      d=inputy-inputr;
      xr=max(xr,a);
      xl=min(xl,b);
      yr=max(yr,c);
      yl=min(yl,d);
    }
    else if (geo=='P'){
      cin >> n;
      for (int i=0;i<n;i++){
        cin >> inputx >> inputy;
        if (inputx>xr){
          xr=inputx;
        }else if(inputx<xl){
          xl=inputx;
        }
        if (inputy>yr){
          yr=inputy;
        }else if (inputy<yl){
          yl=inputy;
        }
      }
    }
    cin >> geo;
  }
  x=(xr+xl)/2;
  y=(yr+yl)/2;
  width=xr-xl;
  height=yr-yl;
  cout << x << " " << y << " " << width << " " << height << endl;
}
