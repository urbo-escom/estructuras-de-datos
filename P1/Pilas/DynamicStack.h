typedef struct Node{
   StackEntry entry;
   struct Node* next;
}Node;

typedef struct Stack{
   Node* top;
}Stack;

Stack createStack(){
   Stack s;
      s.top = NULL;
   return s;
}

int empty(Stack *s){
   if(s->top == NULL)
      return 1;
   return 0;
}

Node* top(Stack *s){
   return s->top;
}

void push(Node *n,Stack *s){
   n->next = s->top;
   s->top = n;
}

Node* pop(Stack *s){
   Node *aux = s->top;
   
   if(aux != NULL)
      s->top = s->top->next;
   
   return aux;
}
