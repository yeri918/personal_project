#include <iostream>
#include <string>
using namespace std;

int main(){
  int m1, m2, d1, d2;
  cout << "a: ";
  cin >> m1;
  cout << "b: ";
  cin >> m2;
  cout << "Divisor 1: ";
  cin >> d1;
  cout << "Divisor 2: ";
  cin >> d2;
  cout << "M " << d1 << " " << d2 << endl;

  int result1, result2;
  while (m1!=m2){
    if (m1%d1==0){
      result1=1;
    } else {
      result1=0;
    }
    if (m1%d2==0){
      result2=1;
    } else {
      result2=0;
    }
    cout << m1 << " " << result1 << " " << result2 << endl;
    m1+=1;
  }
}
