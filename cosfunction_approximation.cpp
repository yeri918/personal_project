#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  double cos(double);
  cout << "cos(x) by cmath: " << fixed << setprecision(15) << cos(a) << endl;

  int i=1;
  double sum=1;
  cout << "Taylor series approximation:" << endl;
  cout << "0 "<< fixed << setprecision(15)<< sum << endl;
  while (i!=(b+1)){
    double top, bottom=1, right;
    int factorial=(2*i), helpf=1;
    top=pow(-1,i);
    while (helpf!=(factorial+1)){
      bottom=bottom*helpf;
      helpf+=1;
    }
    right=pow(a,2*i);
    sum+=(top/bottom*right);
    cout << i << " " << fixed << setprecision(15) << sum << endl;
    i+=1;

  }
}
