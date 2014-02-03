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

void showList(List *l){
   Node *aux = l->sentinel->next;
   for(;aux != l->sentinel;aux = aux->next)
      printf("%d ",aux->entry.a);
   printf("\n");
}

int main(){
   List l1;createList(&l1);
   char s[1024];s[0] = '\0';
   
   int i;
   for(i = 0;i < 12;i++){   
      insert(createNode(i*100),i,&l1);
      showList(&l1);
   }
   
   Node *n = removeList(3,&l1);
   showList(&l1);
   printf("3 removed: %d\n\n",n->entry.a);
   
   n->entry.a += 150;
   insert(n,9,&l1);
   showList(&l1);
   printf("9 inserted: %d\n\n",n->entry.a);
   
   showList(&l1);
   printf("%d found at pos %d\n\n",n->entry.a,search(n,&l1));
   
   n = createNode(101);
   showList(&l1);
   printf("%d not found pos != %d\n\n",n->entry.a,search(n,&l1));
   
   showList(&l1);
   printf("3 has: %d\n\n",search_k(3,&l1)->entry.a);
   
   for(i = 0;i < 12;i++){
      char s[1024];
      
      if(!empty(&l1)){
         n = removeList(1,&l1);
         if(n != NULL)
            free(n);
      }else
         printf("Empty list...\n");
      showList(&l1);
   }
   
   gets(s);
   return 0;
}
