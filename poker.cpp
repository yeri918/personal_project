#include <iostream>
#include <string>
#include <cstdlib>
#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
using namespace std;


void DealHand(int &c1, int &c2, int &c3, int &c4, int &c5);
void PrintHand(int c1, int c2, int c3, int c4, int c5);
bool IsFourOfAKind(int c1, int c2, int c3, int c4, int c5);
bool IsFullHouse(int c1, int c2, int c3, int c4, int c5);
bool IsFlush(int c1, int c2, int c3, int c4, int c5);
bool IsThreeOfAKind(int c1, int c2, int c3, int c4, int c5);
bool IsTwoPair(int c1, int c2, int c3, int c4, int c5);
bool IsOnePair(int c1, int c2, int c3, int c4, int c5);

int main()
{
  int number,c1,c2, c3, c4, c5;
  cin >> number;
  srand(number);
  DealHand(c1, c2, c3, c4, c5);
  PrintHand(c1, c2, c3, c4, c5);

  if (IsFourOfAKind(c1, c2, c3, c4, c5)){
    cout << "four of a kind"<<endl;
  }else if (IsFullHouse(c1, c2, c3, c4, c5)){
    cout << "full house"<<endl;
  }else if (IsFlush(c1, c2, c3, c4, c5)){
    cout << "flush"<<endl;
  }else if (IsThreeOfAKind(c1, c2, c3, c4, c5)){
    cout << "three of a kind"<<endl;
  }else if (IsTwoPair(c1, c2, c3, c4, c5)){
    cout << "two pair"<<endl;
  }else if (IsOnePair(c1, c2, c3, c4, c5)){
    cout << "one pair"<<endl;
  }else{
    cout << "others"<<endl;
  }
  return 0;
}

void DealHand(int &c1, int &c2, int &c3, int &c4, int &c5){
  c1=rand()%52;
  c2=rand()%52;
  c3=rand()%52;
  c4=rand()%52;
  c5=rand()%52;
}
void PrintHand(int c1, int c2, int c3, int c4, int c5){
  int a,count=0;
  while(count!=5){
    if (count==0){
      a=c1;
    }else if(count==1){
      a=c2;
    }else if (count==2){
      a=c3;
    }else if (count==3){
      a=c4;
    }else if (count==4){
      a=c5;
    }
    if (a>=0 && a<=12){
      if (a==1){
        cout << "A" << SPADE;
      }else if (a==10){
        cout << "J" << SPADE;
      }else if (a==11){
        cout << "Q" << SPADE;
      }else if (a==12){
        cout << "K" << SPADE;
      }else {
      cout << a+1 << SPADE;
      }
    }else if (a>=13 && a<=25){
      if (a==13){
        cout << "A" << HEART;
      }else if (a==23){
        cout << "J" << HEART;
      }else if (a==24){
        cout << "Q" << HEART;
      }else if (a==25){
        cout << "K" << HEART;
      }else{
        cout << a-12 << HEART;
      }
    }else if (a>=26 && a<=38){
      if (a==26){
        cout << "A" << CLUB;
      }else if (a==36){
        cout << "J" << CLUB;
      }else if (a==37){
        cout << "Q" << CLUB;
      }else if (a==38){
        cout << "K" << CLUB;
      }else{
        cout << a-25 << CLUB;
      }
    }else if (a>=39 && a<=51){
      if (a==39){
        cout << "A" << DIAMOND;
      }else if (a==49){
        cout << "J" << DIAMOND;
      }else if (a==50){
        cout << "Q" << DIAMOND;
      }else if (a==51){
        cout << "K" << DIAMOND;
      }else{
        cout << a-38 << DIAMOND;
      }
    }
    count+=1;
    if (count!=5){
      cout << " ";
    }else{
      cout << endl;
    }
  }
}
bool IsFourOfAKind(int c1, int c2, int c3, int c4, int c5){
  int a,b,c,d,e;
  a=c1%13;
  b=c2%13;
  c=c3%13;
  d=c4%13;
  e=c5%13;
  if ((a==b && a==c && a==d) || (a==b && a==c && a==e) ||
    (a==b && a==d && a==e) || (a==c && a==d && a==e) || (b==c && b==d && b==e)){
    return true;
  }else{
    return false;
  }
}
bool IsFullHouse(int c1, int c2, int c3, int c4, int c5){
  int a,b,c,d,e;
  a=c1%13;
  b=c2%13;
  c=c3%13;
  d=c4%13;
  e=c5%13;
  if ((a==b && a==c && d==e)||(a==c && c==d &&b==e)||(a==d && a==e && b==c)||
  (b==c && b==d && a==e)||(b==d && b==e && a==c)||(c==d && d==e && a==b)||
  (a==c && a==e && b==d)||(a==b &&a==e && d==c)||(a==b && a==d && c==e)||
  (b==c && b==e && a==d)){
    return true;
  }else{
    return false;
  }
}
bool IsFlush(int c1, int c2, int c3, int c4, int c5){
  if ((c1>=0 && c1<=12 && c2>=0 && c2<=12&& c3>=0 && c3<=12 && c4>=0 && c4<=12 && c5>=0 && c5<=12)||
  (c1>=13 && c1<=25 && c2>=13 && c2<=25 && c3>=13 && c3<=25 && c4>=13 && c4<=25 && c5>=13 && c5<=25)||
  (c1>=26 && c1<=38 && c2>=26 && c2<=38 && c3>=26 && c3<=38 && c4>=26 && c4<=38 && c5>=26 && c5<=38)||
  (c1>=39 && c1<=51 && c2>=39 && c2<=51 && c3>=39 && c3<=51 && c4>=39 && c4<=51 && c5>=39 && c5<=51)){
    return true;
  }else{
    return false;
  }
}
bool IsThreeOfAKind(int c1, int c2, int c3, int c4, int c5){
  int a,b,c,d,e;
  a=c1%13;
  b=c2%13;
  c=c3%13;
  d=c4%13;
  e=c5%13;
  if ((a==b && a==c)|| (a==b && a==d)|| (a==b && a==e)|| (a==c && a==d)||
  (a==c && a==e)|| (a==d && a==e)||(b==c && b==d)||(b==c && b==e)||
  (c==d && c==e)|| (b==d && b==e)){
    return true;
  }else{
    return false;
  }
}
bool IsTwoPair(int c1, int c2, int c3, int c4, int c5){
  int a,b,c,d,e;
  a=c1%13;
  b=c2%13;
  c=c3%13;
  d=c4%13;
  e=c5%13;
  if((a==b && c==d)||(a==b && c==e)||(a==b && d==e)||(a==c && b==d)||(a==c && b==e)||
  (a==c && d==e)||(a==d && b==c)||(a==d && b==e)||(a==d && c==e)||(a==e && b==d)||(a==e&&c==d)||
  (a==e&&b==c)||(b==c &&d==e)||(b==d&&c==e)||(b==e&&c==d)||(a==b && d==e)){
    return true;
  }else{
    return false;
  }
}
bool IsOnePair(int c1, int c2, int c3, int c4, int c5){
  int a,b,c,d,e;
  a=c1%13;
  b=c2%13;
  c=c3%13;
  d=c4%13;
  e=c5%13;
  if (a==b || a==c || a==d || a==e || b==c || b==d ||
    b==e || c==d || c==e || d==e){
      return true;
  }else{
    return false;
  }
}
