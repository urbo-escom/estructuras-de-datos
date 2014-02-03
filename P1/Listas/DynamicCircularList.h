typedef struct Node{
   ListEntry entry;
   struct Node* prev;
   struct Node* next;
}Node;

typedef struct List{
   Node *sentinel;
}List;

void createList(List*);
int empty(List*);

void insert(Node*,int,List*);
Node* removeList(int,List*);
int search(Node*,List*);
Node* search_k(int,List*);

/*USER DEFINED FUNCTIONS*/
/*Node* createNode(var a,var b,...,var n)*/
int equalNode(Node*,Node*);

void createList(List *l){
   l->sentinel = (Node*)malloc(sizeof(Node));
   l->sentinel->prev = l->sentinel;
   l->sentinel->next = l->sentinel;
}

int empty(List *l){
   if(l->sentinel->next != l->sentinel)
      return 0;
   return 1;
}

void insert(Node *n,int pos,List *l){
   if(pos < 1)
      return;
   
   Node *aux = l->sentinel;
   while(--pos){
      aux = aux->next;
      if(aux == l->sentinel)
         return;
   }
   
   n->next = aux->next;
   aux->next = n;
   n->next->prev = n;
   n->prev = aux;
}

Node* removeList(int pos,List *l){
   if(pos < 1)
      return NULL;
   
   Node *aux = l->sentinel;
   while(pos--){
      aux = aux->next;
      if(aux == l->sentinel)
         return NULL;
   }
   
   aux->prev->next = aux->next;
   aux->next->prev = aux->prev;
   aux->prev = NULL;
   aux->next = NULL;
   
   return aux;
}

int search(Node *n,List *l){
   Node *aux = l->sentinel->next;
   int i = 1;
   while(aux != l->sentinel){
      if(equalNode(n,aux))
         break;
      aux = aux->next;
      i++;
   }
   
   if(aux != l->sentinel)
      return i;
   return -1;
}

Node* search_k(int pos,List *l){
   if(pos < 1)
      return NULL;
      
   Node *aux = l->sentinel;
   while(pos--){
      aux = aux->next;
      if(aux == l->sentinel)
         return NULL;
   }
   
   return aux;
}
