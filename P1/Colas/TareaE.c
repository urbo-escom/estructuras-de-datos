#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
   int a;
}QueueEntry;

#include "DynamicQueue.h"

Node* createNode(int a){
   Node *n = (Node*)malloc(sizeof(Node));
      n->entry.a = a;
      n->next = NULL;
      
   return n;
}

Node* minNode(Node *a,Node *b){
   if(a->entry.a <= b->entry.a)
      return a;
   return b;
}

Node* maxNode(Node *a,Node *b){
   if(a->entry.a >= b->entry.a)
      return a;
   return b;
}

Node* APQremove(Queue *apq){
   if(empty(apq))
      return NULL;
      
   Node *aux = apq->front;
   Node *min = aux;
   
   while(aux->next != NULL){
      min = minNode(min,aux->next);
      aux = aux->next;
   }
   
   aux = apq->front;
   if(min == aux)
      return removeQueue(apq);
      
   while(aux->next != min)
      aux = aux->next;
      
   aux->next = min->next;
   if(aux->next == NULL)
      apq->back = aux;
   
   min->next = NULL;
   return min;
}

Node* DPQremove(Queue *dpq){
   if(empty(dpq))
      return NULL;
      
   Node *aux = dpq->front;
   Node *max = aux;
   
   while(aux->next != NULL){
      max = maxNode(max,aux->next);
      aux = aux->next;
   }
   
   aux = dpq->front;
   if(max == aux)
      return removeQueue(dpq);
      
   while(aux->next != max)
      aux = aux->next;
      
   aux->next = max->next;
   if(aux->next == NULL)
      dpq->back = aux;
   
   max->next = NULL;
   return max;
}

void showContent(Queue *q){
   int i = 0;
   Node *aux = q->front;
   
   for(;aux != NULL;aux = aux->next){
      printf("%d ",aux->entry.a);
   }
   printf("\n");
}

#include "time.h"

int main(){
   Queue q1 = createQueue();
   Node *n;
   char s[1024];s[0] = '\0';
   int i = 8;
   
   showContent(&q1);
   while(i--){
      insert(createNode(rand()%201),&q1);
      showContent(&q1);
   }
   
   while(!empty(&q1)){
      n = APQremove(&q1);
      printf("APQQueue removed: %d\n",n->entry.a);
      showContent(&q1);free(n);
   }
   printf("Queue empty\n");
   showContent(&q1);
   i = 8;
   while(i--){
      insert(createNode(rand()%201),&q1);
      showContent(&q1);
   }
   
   while(!empty(&q1)){
      n = DPQremove(&q1);
      printf("DPQQueue removed: %d\n",n->entry.a);
      showContent(&q1);free(n);
   }
   gets(s);
   return 0;
}
