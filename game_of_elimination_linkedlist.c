#include <stdio.h>
#include <stdlib.h>

struct Node{
  int info;
  struct Node * next;
};

struct Node * make_list(struct Node * head, int num){
  struct Node * current=(struct Node *)malloc(sizeof(struct Node)), *p;
  for (int i=0;i<num;i++){
    p=(struct Node *)malloc(sizeof(struct Node));
    p->info=i+1;
    p->next=NULL;
    if (head==NULL){
      head=p;
      current=head;
    }else{
      current->next=p;
      current=current->next;
    }
  }
  current->next=head;
  return head;
}

int winner(struct Node * head, int n, int k){
  for (int i=0;i<n-1;i++){
    struct Node * eliminate=(struct Node *)malloc(sizeof(struct Node));
    eliminate=head;
    if (i==0){
      for (int j=0;j<k-2;j++){
        head=head->next;
        eliminate=eliminate->next;
      }
    }else{
      for (int j=0;j<k-1;j++){
        head=head->next;
        eliminate=eliminate->next;
      }
    }
    eliminate=eliminate->next;
    head->next=eliminate->next;
    free(eliminate);
  }
  return head->info;
}

int main(){
  int n,k;
  scanf("%i",&n);
  scanf("%i",&k);
  struct Node *head=NULL;
  head=make_list(head, n);
  printf("%i\n",winner(head,n,k));
}
