#include <stdio.h>

typedef struct {
   char c;
}QueueEntry;

#include "DynamicQueue.h"

Node* createNode(char c){
   Node *n = (Node*)malloc(sizeof(Node));
      n->entry.c = c;
      n->next = NULL;
      
   return n;
}

char removeQueue2(Queue *q){
   Node *n = removeQueue(q);
   char c = n->entry.c;
   free(n);
   return c;
}

void showContent(Queue *q){
   int i = 0;
   Node *aux = q->front;
   
   for(;aux != NULL;aux = aux->next){
      printf("%c ",aux->entry.c);
   }
   printf("\n");
}

int main(){
   Queue q1 = createQueue();
   char s[1024];s[0] = '\0';
   int i = 10;
   
   showContent(&q1);
   while(i--){
      insert(createNode('A' + 10 - i),&q1);
      showContent(&q1);
   }
   while(!empty(&q1)){
      printf("Queue front removed: '%c'\n",removeQueue2(&q1));
      showContent(&q1);
   }
   printf("Queue empty\n");
   
   gets(s);
   return 0;
}
