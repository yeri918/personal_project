#include <iostream>
#include <string>
using namespace std;

int main(){
  int count1, count2;
  cin >> count1;
  cin >> count2;
  while (count1+count2!=0){
    if (count1!=0){
      cout << "y";
      count1-=1;
    }
    if (count2!=0){
      cout << "z";
      count2-=1;
    }
  }
  cout << endl;

}
