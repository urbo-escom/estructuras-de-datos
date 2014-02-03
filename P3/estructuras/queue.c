/*
Necesita la librería: stdlib.h
Para definir una nueva cola, node
debe ser del tipo:
struct node{
   struct node* next;
   ...
}

Se crean las funciones:
queue_node crear_queue_node();
int        empty_queue_node();
node*      front_node(queue_node);
void       insert_queue_node(node,queue_node);
node*      remove_queue_node(queue_node);
*/
#define DEFINIR_NUEVO_QUEUE( node ) \
typedef struct queue_##node{ \
   node *front; \
   node *back; \
}queue_##node; \
\
queue_##node* crear_queue_##node(){ \
   queue_##node *q = (queue_##node*)malloc(sizeof(queue_##node)); \
   if( q == NULL ) return q; \
      q->front = NULL; \
      q->back = NULL; \
   return q; \
} \
\
int empty_queue_##node(queue_##node *q){ \
   return q->front == NULL; \
} \
\
node* front_##node(queue_##node *q){ \
   return q->front; \
} \
\
void insert_queue_##node(node *n,queue_##node *q){ \
   if( n == NULL ) return; \
\
   if(empty_queue_##node(q)) \
      q->front = n; \
   else \
      q->back->next = n; \
   q->back = n; \
   q->back->next = NULL; \
} \
\
node* remove_queue_##node(queue_##node *q){ \
   if(empty_queue_##node(q)) \
      return NULL; \
\
   node *aux = q->front; \
   q->front = q->front->next; \
\
   aux->next = NULL; \
\
   return aux; \
} \
\
void drop_queue_##node(queue_##node **q){ \
   while(!empty_queue_##node(*q)) \
      free(remove_queue_##node(*q)); \
   free(*q);\
} \

int queue_gen = 1;