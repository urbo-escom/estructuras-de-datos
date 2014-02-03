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
   
   for(;aux != NULL;aux = aux->next)
      printf("%c ",aux->entry.c);
   printf("\n");
}

void concatQueue(Queue *q1,Queue *q2){
   if(empty(q2))
      return;
   
   insert(q2->front,q1);
   q1->back = q2->back;
   
   q2->front = NULL;
   q2->back = NULL;
}

void reverse(Queue *q){
   if(empty(q))
      return;

   Queue aux[2];
      aux[0] = createQueue();
      aux[1] = createQueue();
      
   Node *n;
   int i = 0;
   for(;!empty(q);i++){
      n = removeQueue(q);
         n->next = NULL;
      insert(n,&aux[i%2]);
      concatQueue(&aux[i%2],&aux[(i + 1)%2]);
   }
   
   while(!empty(&aux[(i + 1)%2])){
      n = removeQueue(&aux[(i + 1)%2]);
         n->next = NULL;
      insert(n,q);
   }
}

int main(){
   Queue q1[2];
      q1[0] = createQueue();
      q1[1] = createQueue();
   char s[1024];s[0] = '\0';
   int i = 10;
   
   showContent(&q1);
   while(i--){
      insert(createNode('A' + 9 - i),&q1[0]);
      showContent(&q1[0]);
   }
   reverse(&q1[0]);
   showContent(&q1[0]);
   
   i = 4;
   while(i--){
      insert(createNode('0' + 9 - i),&q1[1]);
      showContent(&q1[1]);
   }
   concatQueue(&q1[0],&q1[1]);
   showContent(&q1[0]);
   
   gets(s);
   return 0;
}
