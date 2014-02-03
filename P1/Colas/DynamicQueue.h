typedef struct Node{
   QueueEntry entry;
   struct Node* next;
}Node;

typedef struct {
   Node *front;
   Node *back;
}Queue;

Queue createQueue(){
   Queue q;
      q.front = NULL;
      q.back = NULL;
   return q;
}

int empty(Queue *q){
   if(q->front != NULL)
      return 0;
   return 1;
}

void insert(Node *n,Queue *q){
   if(empty(q))
      q->front = n;
   else
      q->back->next = n;
   q->back = n;
}

Node* removeQueue(Queue *q){
   if(empty(q))
      return NULL;
      
   Node *aux = q->front;
   
   if(aux != NULL)
      q->front = q->front->next;
      
   return aux;
}
