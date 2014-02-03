#include <stdio.h>

typedef struct {
   char c;
}StackEntry;

#define maxSize 10
#include "StaticStack.h"

Node createNode(char c){
   Node n;   n.entry.c = c;
   return n;
}

void showContent(Stack *s){
   int i = 0;
   for(;i < s->size;i++){
      printf("%c ",s->nodes[i].entry.c);
   }
   printf("\n\n");
}

int main(){
   Stack s1 = createStack();
   
   int i;
   char s[1024];s[0] = '\0';
   
   for(i = 0;i < maxSize + 2;i++){
      showContent(&s1);
      if(!full(&s1)){
         push(createNode('a' + i),&s1);
         printf("Stack pushed on top: '%c'\n",top(&s1).entry.c);
      }else
         printf("Stack is full\n");
   }
   
   for(i = 0;i < maxSize + 2;i++){
      showContent(&s1);
      if(!empty(&s1)){
         printf("Stack top removed: '%c'\n",pop(&s1).entry.c);
      }else
         printf("Stack is empty\n");
   }
   
   gets(s);
   return 0;
}
