#include <stdio.h>

const int MAX_INT_LENGTH = 101; // string length for representing 100 digits

void AddTwoBigNumbers(char bigN[], char bigM[], char sum[])
{
  int i,l1=0,l2=0;
  for (i=0;i<MAX_INT_LENGTH;i++){
    if (bigN[i]=='\0'){
      l1=i;
      break;
    }
  }
  for (i=0;i<MAX_INT_LENGTH;i++){
    if (bigM[i]=='\0'){
      l2=i;
      break;
    }
  }
  //Reversing the numbers
  char temp;
  //reverse l1
  if (l1%2==0){
    for (i=0;i<l1/2;i++){
      temp=bigN[l1-i-1];
      bigN[l1-i-1]=bigN[i];
      bigN[i]=temp;
    }
  }else if (l1%2==1){
    for (i=0;i<(l1-1)/2;i++){
      temp=bigN[l1-i-1];
      bigN[l1-i-1]=bigN[i];
      bigN[i]=temp;
    }
  }
  //reverse l2
  if (l2%2==0){
    for (i=0;i<l2/2;i++){
      temp=bigM[l2-i-1];
      bigM[l2-i-1]=bigM[i];
      bigM[i]=temp;
    }
  }else if (l2%2==1){
    for (i=0;i<(l2-1)/2;i++){
      temp=bigM[l2-i-1];
      bigM[l2-i-1]=bigM[i];
      bigM[i]=temp;
    }
  }

  //adding to sum
  int x,y,higherdigit=0,lowerdigit=0,count=0;
  char z;
  if(l1>l2){
    for (i=0;i<l2;i++){
      x= bigN[i]-'0';
      y= bigM[i]-'0';
      lowerdigit=(x+y+higherdigit)%10;
      z=lowerdigit+'0';
      sum[i]=z;
      higherdigit=(x+y+higherdigit)/10;
      count+=1;

    }
    for (i=l2;i<l1;i++){
      x=bigN[i]-'0';
      lowerdigit=(x+higherdigit)%10;
      //printf("x:%d   lowerdigit:%d   ",x,lowerdigit);
      z=lowerdigit+'0';
      sum[i]=z;
      higherdigit=(x+higherdigit)/10;
      count+=1;
      //printf("higherdigit:%d\n",higherdigit);
    }
    if (higherdigit!=0){
      //printf("higherdigit not 0");
      z=higherdigit+'0';
      sum[l1]=z;
      count+=1;
    }
  }else if (l2>=l1){
    for (i=0;i<l1;i++){
      x=bigN[i]-'0';
      y=bigM[i]-'0';
      lowerdigit=(x+y+higherdigit)%10;
      z=lowerdigit+'0';
      sum[i]=z;
      higherdigit=(x+y+higherdigit)/10;
      count+=1;
    }
    if (l2>l1){
      for (i=l1;i<l2;i++){
        y=bigM[i]-'0';
        lowerdigit=(y+higherdigit)%10;
        z=lowerdigit+'0';
        sum[i]=z;
        higherdigit=(y+higherdigit)/10;
        count+=1;
      }
      if(higherdigit!=0){
        sum[l2]=higherdigit+'0';
        count+=1;
      }
    }else if (l2==l1){
      if (higherdigit!=0){
        z=higherdigit+'0';
        sum[l1]=z;
        count+=1;
      }
    }
  }
  if (count%2==0){
    for (i=0;i<count/2;i++){
      temp=sum[count-i-1];
      sum[count-i-1]=sum[i];
      sum[i]=temp;
    }
  }else if (count%2==1){
    for (i=0;i<(count+1)/2;i++){
      temp=sum[count-i-1];
      sum[count-i-1]=sum[i];
      sum[i]=temp;
    }
  }
  sum[count]='\0';
}



int main()
{
  char bignum[2][MAX_INT_LENGTH]; // bignum[0] and bignum[1] are to store the digits of the two input number
  char sum[MAX_INT_LENGTH+1];     // to store the sum of the two big numbers

  // read in two numbers
  scanf("%s", bignum[0]);
  scanf("%s", bignum[1]);

  // calculate sum of the two numbers
  AddTwoBigNumbers(bignum[0], bignum[1], sum);

  // display the sum on screen
  printf("%s\n", sum);


  return 0;
}
