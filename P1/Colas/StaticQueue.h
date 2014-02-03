typedef struct {
   QueueEntry entry;
}Node;

typedef struct {
   int back;
   int front;
   Node nodes[maxSize];
}Queue;

Queue createQueue(){
   Queue q;
      q.back = -1;
      q.front = 0;
   return q;
}

int empty(Queue *q){
   if(q->back - q->front + 1 > 0)
      return 0;
   return 1;
}

int full(Queue *q){
   if(q->back - q->front + 1 < maxSize)
      return 0;
   return 1;
}

int size(Queue *q){
   return q->back - q->front + 1;
}

void clean(Queue *q){
   if(q->back + 1 == maxSize){
      int n = q->front,i;
      for(i = q->front;i <= q->back && q->back > q-> front;i++){
         q->nodes[i - n] = q->nodes[i];
      }
      q->back -= n;
      q->front -= n;
   }
}

void insert(Node n,Queue *q){
   if(full(q))
      return;
      
   if(q->back + 1 == maxSize)
      clean(q);
      
   q->nodes[++q->back] = n;
}

Node removeQueue(Queue *q){
   if(!empty(q))
      return q->nodes[q->front++];
   return q->nodes[0];
}
