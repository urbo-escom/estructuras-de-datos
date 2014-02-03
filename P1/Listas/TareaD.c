#include <stdio.h>
#include <stdlib.h>

typedef struct ListEntry{
   int a;
}ListEntry;

#define maxSize 15
#include "StaticList.h"

Node createNode(int a){
   Node n;
      n.entry.a = a;
   return n;
}

int equalNode(Node *a,Node *b){
   if(a->entry.a == b->entry.a)
      return 1;
   return 0;
}

int equal(List *l1,List *l2){
   if(l1->size != l2->size)
      return 0;
   
   int i = 0;
   for(;i < l1->size;i++)
      if(!equalNode(&l1->nodes[i],&l2->nodes[i]))
         return 0;
   
   return 1;
}

void copy(List *l1,List *l2){
   if(empty(l2))
      return;
   int i = 0;
   for(;i < l2->size;i++)
      l1->nodes[i] = l2->nodes[i];
   
   l1->size = l2->size;
}

void swap(List *l1,List *l2){
   List aux = createList();
   
   copy(&aux,l1);
   copy(l1,l2);
   copy(l2,&aux);
}

int insertList(List *l1,int pos,List *l2){
   if(l1->size + l2->size > maxSize
      || full(l1) || empty(l2))
      return 0;

   if(pos < 1 || l1->size < pos - 1)
      return 0;
   
   while(!empty(l2))
      insert(removeList(l2->size,l2),pos,l1);
   
   return 1;
}

int combine(List *l1,List *l2){
   if(l1->size + l2->size > maxSize
      || full(l1) || empty(l2))
      return 0;

   List temp = createList();
   int i = l1->size + l2->size;
   while(i){
      if(!empty(l1)){
         insert(removeList(1,l1),temp.size + 1,&temp);
         i--;
      }
      if(!empty(l2)){
         insert(removeList(1,l2),temp.size + 1,&temp);
         i--;
      }
   }
   copy(l1,&temp);
   
   return 1;
}

void showList(List *l){
   int i;
   for(i = 0;i < l->size;i++)
      printf("%d ",l->nodes[i].entry.a);
   printf("\n");
}

int main(){
   List l1 = createList();
   List l2 = createList();
   Node n;
   char s[1024];s[0] = '\0';
   
   int i;
   for(i = 1;i < 7;i++){
      if(!full(&l1))
         insert(createNode(i*10),i,&l2);
      else
         printf("Full list...\n");
      showList(&l1);
      if(!full(&l1))
         insert(createNode(i*10),i,&l1);
      else
         printf("Full list...\n");
      showList(&l1);
   }
   
   n = removeList(4,&l2);
      showList(&l1);
      showList(&l2);
   if(!equal(&l1,&l2))
      printf("Unequal lists\n");
   insert(n,4,&l2);
      showList(&l1);
      showList(&l2);
   if(equal(&l1,&l2))
      printf("Equal lists\n");
   
   combine(&l1,&l2);
   showList(&l1);
   printf("Combined list ^\n");
   
   gets(s);
   return 0;
}
