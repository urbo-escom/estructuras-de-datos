/*
Necesita la librería: stdlib.h
Para definir una nueva pila, node
debe ser del tipo:
struct node{
   struct node* next;
   ...
}

Se crean las funciones:
stack_node crear_stack_node();
int        empty_stack_node();
node*      top_node(stack_node);
void       push(node,stack_node);
node*      pop(stack_node);
*/
#define DEFINIR_NUEVO_STACK( node ) \
typedef struct stack_##node{ \
   node *top; \
}stack_##node; \
\
stack_##node* crear_stack_##node(){ \
   stack_##node *s = (stack_##node*)malloc(sizeof(stack_##node)); \
   if( s != NULL ) \
      s->top = NULL; \
   return s; \
} \
\
int empty_stack_##node(stack_##node *s){ \
   return s->top == NULL; \
} \
\
node* top_##node(stack_##node *s){ \
   return s->top; \
} \
\
void push_##node(node *n,stack_##node *s){ \
   n->next = s->top; \
   s->top = n; \
} \
\
node* pop_##node(stack_##node *s){ \
   node *aux = s->top; \
\
   if(aux != NULL){ \
      s->top = s->top->next; \
      aux->next = NULL; \
   } \
\
   return aux; \
} \
\
void drop_stack_##node(stack_##node **s){ \
   while(!empty_stack_##node(*s)) \
      free(pop_##node(*s)); \
   free(*s); \
} \

int stack_gen = 1;