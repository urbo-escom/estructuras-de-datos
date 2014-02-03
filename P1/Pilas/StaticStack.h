typedef struct Node{
   StackEntry entry;
}Node;

typedef struct Stack{
   int size;
   Node nodes[maxSize];
}Stack;

Stack createStack(){
   Stack s;
      s.size = 0;  
   return s;
}

int empty(Stack *s){
   if(s->size > 0)
      return 0;
   return 1;
}

int full(Stack *s){
   if(s->size < maxSize)
      return 0;
   return 1;
}

Node top(Stack *s){
   if(!empty(s))
      return s->nodes[s->size - 1];
   return s->nodes[0];
}

void push(Node n,Stack *s){
   if(!full(s))
      s->nodes[s->size++] = n;
}

Node pop(Stack *s){
   if(!empty(s))
      return s->nodes[s->size-- - 1];
   return s->nodes[0];
}
