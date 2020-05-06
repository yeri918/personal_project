#include <iostream>
#include <string>
using namespace std;

int main(){
  int x,i,k,j;
  string input;
  char s;
  cin >> s >> k;
  getline(cin, input);
  int count=input.length();
  int number=2;
  if (s=='e' && (k<0)){
    s='d';
    k=abs(k);
  }
  else if (s=='d' && (k<0)){
    s='e';
    k=abs(k);
  }
  if (s=='e'){
    for (x=1; x<count; x++){
      if (isalpha(input[x])){
        for (i=0;i<k;i++){
          if (input[x]=='z'){
            input[x]='a';
          }
          else if (input[x]=='Z'){
            input[x]='A';
          }
          else{
            input[x]++;
          }
        }
      }
    }
  }
  else if (s=='d'){
    for (x=1; x<count; x++){
      if (isalpha(input[x])){
        for (i=0;i<k;i++){
          if (input[x]=='a'){
            input[x]='z';
          }
          else if (input[x]=='A'){
            input[x]='Z';
          }
          else{
            input[x]--;
          }
        }
      }
    }
  }

  for (j=0;j<count;j++){
    if (input[j]!=' '){
      if (isalpha(input[j])){
        if (isupper(input[j])){
          input[j]= tolower(input[j]);
          cout << input[j] ;
        }
        else if (islower(input[j])){
          input[j]= toupper(input[j]);
          cout << input[j] ;
        }
      }
      else if (input[j]=='!'){
        cout << input[j] << endl;
      }
      else{
        cout <<input[j];
      }
    }

  }
}
