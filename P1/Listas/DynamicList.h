typedef struct Node{
   ListEntry entry;
   struct Node* next;
}Node;

typedef struct List{
   Node *start;
}List;

List createList();
int empty(List*);

void insert(Node*,int,List*);
Node* removeList(int,List*);
int search(Node*,List*);
Node* search_k(int,List*);

/*USER DEFINED FUNCTIONS*/
/*Node* createNode(var a,var b,...,var n)*/
int equalNode(Node*,Node*);

List createList(){
   List l;
      l.start = NULL;
   return l;
}

int empty(List *l){
   if(l->start != NULL)
      return 0;
   return 1;
}

void insert(Node *n,int pos,List *l){
   if(1 > pos)
      return;
   
   if(pos == 1){
      n->next = l->start;
      l->start = n;
      return;
   }else if(empty(l))
      return;
   
   Node *aux = l->start;
   
   while(pos-- - 2){
      aux = aux->next;
      if(aux == NULL)
         return;
   }
   
   n->next = aux->next;
   aux->next = n;
}

Node* removeList(int pos,List *l){
   if(empty(l) || 1 > pos)
      return NULL;
   
   Node *n,*aux;
   if(pos == 1){
      n = l->start;
      l->start = n->next;
      n->next = NULL;
      return n;
   }
   
   aux = l->start;
   
   while(pos-- - 2){
      aux = aux->next;
      if(aux == NULL)
         return NULL;
   }
   
   n = aux->next;
   if(n != NULL){
      aux->next = n->next;
      n->next = NULL;
   }
   
   return n;
}

int search(Node *n,List *l){
   Node *aux = l->start;
   int i = 1;
   while(aux != NULL){
      if(equalNode(n,aux))
         break;
      aux = aux->next;
      i++;
   }
   
   if(aux != NULL)
      return i;
   return -1;
}

Node* search_k(int pos,List *l){
   if(pos < 1)
      return NULL;
      
   Node *aux = l->start;
   while(pos-- - 1){
      aux = aux->next;
      if(aux == NULL)
         return NULL;
   }
   
   return aux;
}
