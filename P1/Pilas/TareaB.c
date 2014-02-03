#include <stdio.h>

typedef struct {
   char c;
}StackEntry;

#include "DynamicStack.h"

Node* createNode(char c){
   StackEntry e;
      e.c = c;
   Node *n = (Node*)malloc(sizeof(Node));
      n->entry = e;
      n->next = NULL;
   return n;
}

char pop2(Stack *s){
   Node *n = pop(s);
   char c = n->entry.c;
   free(n);
   
   return c;
}

void showContent(Stack *s){
   int i = 0;
   Node *aux = s->top;
   
   for(;aux != NULL;aux = aux->next){
      printf("%c ",aux->entry.c);
   }
   printf("\n\n");
}

int main(){
   Stack s1 = createStack();
   char s[1024];s[0] = '\0';
   
   int i;
   for(i = 0;i < 20;i++){
      push(createNode('1' + i),&s1);
      printf("Stack pushed on top: '%c'\n",top(&s1)->entry.c);
      showContent(&s1);
   }
   
   for(i = 0;i < 23;i++){
      if(empty(&s1))
         printf("Stack empty\n");
      else
         printf("Stack top removed: '%c'\n",pop2(&s1));
      showContent(&s1);
   }
   
   gets(s);
   return 0;
}
