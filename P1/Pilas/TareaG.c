#include <stdio.h>

typedef struct StackEntry{
   char c;
}StackEntry;

#define maxSize 10

typedef struct Node{
   StackEntry entry;
}Node;

typedef struct Stack{
   int size1;
   int size2;
   Node nodes[maxSize];
}Stack;

Stack createStack(){
   Stack s;
      s.size1 = 0;
      s.size2 = 0;
   return s;
}

int empty(int i,Stack *s){
   if(i == 0){
      if(s->size1 > 0)
         return 0;
   }else{
      if(s->size2 > 0)
         return 0;}
   return 1;
}

int full(Stack *s){
   if(s->size1 + s->size2 < maxSize)
      return 0;
   return 1;
}

Node top(int i,Stack *s){
   if(!empty(i,s))
      if(i == 0)
         return s->nodes[s->size1 - 1];
      else if(s->size2 > 0)
         return s->nodes[maxSize - s->size2];
   return s->nodes[0];
}

void push(int i,Node n,Stack *s){
   if(!full(s))
      if(i == 0)
         s->nodes[s->size1++] = n;
      else
         s->nodes[maxSize - ++s->size2] = n;
}

Node pop(int i,Stack *s){
   if(!empty(i,s))
      if(i == 0)
         return s->nodes[s->size1-- - 1];
      else
         return s->nodes[maxSize - s->size2--];
   return s->nodes[0];
}

Node createNode(char c){
   Node n;
      n.entry.c = c;
   return n;
}

void showContent(Stack *s){
   int i;
   for(i = 0;i < s->size1;i++)
      printf("%c ",s->nodes[i].entry.c);
   printf("\n");
   for(i = maxSize - s->size2;i < maxSize;i++)
      printf("%c ",s->nodes[i].entry.c);
   printf("\n");
}

int main(){
   Stack s1 = createStack();
   char s[1024];s[0] = '\0';
   
   int i;
   for(i = 0;i < 6;i++){
      if(!full(&s1)){
      push(0,createNode('1' + i),&s1);
      printf("Stack pushed on top: '%c'\n",top(0,&s1).entry.c);}
      else printf("Stack full\n");
      showContent(&s1);
   }
   
   for(i = 0;i < 6;i++){
      if(!full(&s1)){
      push(1,createNode('1' + i),&s1);
      printf("Stack pushed on top: '%c'\n",top(1,&s1).entry.c);}
      else printf("Stack full\n");
      showContent(&s1);
   }
   
   for(i = 0;i < 13;i++){
      if(empty(i%2,&s1))
         printf("Stack %d empty\n",i%2);
      else
         printf("Stack top removed: '%c'\n",pop(i%2,&s1));
      showContent(&s1);
   }
   gets(s);
   return 0;
}
