#include <stdio.h>
#include <stdlib.h>

typedef struct ListEntry{
   int a;
}ListEntry;

#include "DynamicCircularList.h"

Node* createNode(int a){
   Node *n = (Node*)malloc(sizeof(Node));
      n->entry.a = a;
      n->prev = NULL;
      n->next = NULL;
   return n;
}

int equalNode(Node *a,Node *b){
   if(a->entry.a == b->entry.a)
      return 1;
   return 0;
}

int equal(List *l1,List *l2){
   Node *aux1 = l1->sentinel->next;
   Node *aux2 = l2->sentinel->next;
   
   if(aux1 == l1->sentinel && aux2 != l2->sentinel)
      return 0;
   if(aux2 == l2->sentinel && aux1 != l1->sentinel)
      return 0;
   while(aux1 != l1->sentinel && aux2 != l2->sentinel){
      if(!equalNode(aux1,aux2))
         return 0;
      
      aux1 = aux1->next;
      aux2 = aux2->next;
      if(aux1 == l1->sentinel && aux2 != l2->sentinel)
         return 0;
      if(aux2 == l2->sentinel && aux1 != l1->sentinel)
         return 0;
   }
   
   return 1;
}

void copy(List *l1,List *l2){
   while(!empty(l1))
      free(removeList(1,l1));
      
   Node *aux = l2->sentinel->next;
   Node *aux2;
   int i = 1;
   while(aux != l2->sentinel){
      aux2 = createNode(aux->entry.a);
      insert(aux2,i++,l1);
      aux = aux->next;
   }
}

void swap(List *l1,List *l2){
   List temp;
   createList(&temp);
   
   copy(&temp,l1);
   copy(l1,l2);
   copy(l2,&temp);
}

int combine(List *l1,List *l2){
   List temp;createList(&temp);
   
   int i = 1;
   while(!empty(l1) || !empty(l2)){
      if(!empty(l1))
         insert(removeList(1,l1),i++,&temp);
      if(!empty(l2))
         insert(removeList(1,l2),i++,&temp);
   }
   
   copy(l1,&temp);
   return 1;
}

void showList(List *l){
   Node *aux = l->sentinel->next;
   for(;aux != l->sentinel;aux = aux->next)
      printf("%d ",aux->entry.a);
   printf("\n");
}

int main(){
   List l1;createList(&l1);
   List l2;createList(&l2);
   Node *n;
   char s[1024];s[0] = '\0';
   
   int i;
   for(i = 1;i < 7;i++){
      insert(createNode(i*10),i,&l2);
      showList(&l1);
      insert(createNode(i*10),i,&l1);
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
