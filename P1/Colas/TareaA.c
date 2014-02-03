#include <stdio.h>

typedef struct {
   char c;
}QueueEntry;

#define maxSize 10
#include "StaticQueue.h"

Node createNode(char c){
   Node n;   n.entry.c = c;
   return n;
}

void showContent(Queue *q){
   int i = q->front;
   for(;i <= q->back;i++)
      printf("%c ",q->nodes[i].entry.c);
   printf("\n");
}

int main(){
   Queue q1 = createQueue();
   char s[1024];s[0] = '\0';
   
   showContent(&q1);
   while(!full(&q1)){
      insert(createNode('A' + size(&q1)),&q1);
      showContent(&q1);
   }
   printf("Queue full\n");
   while(!empty(&q1)){
      printf("Queue front removed: '%c'\n",removeQueue(&q1).entry.c);
      showContent(&q1);
   }
   printf("Queue empty\n");
   
   gets(s);
   return 0;
}
