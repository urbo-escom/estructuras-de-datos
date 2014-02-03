typedef struct Node{
   ListEntry entry;
}Node;

typedef struct List{
   int size;
   Node nodes[maxSize];
}List;

List createList();
int empty(List*);
int full(List*);
void insert(Node,int,List*);
Node removeList(int,List*);
int search(Node,List*);
Node search_k(int,List*);

/*USER DEFINED FUNCTIONS*/
/*Node createNode(var a,var b,...,var n)*/
int equalNode(Node*,Node*);

List createList(){
   List l;
      l.size = 0;
   return l;
}

int empty(List *l){
   if(l->size > 0)
      return 0;
   return 1;
}

int full(List *l){
   if(l->size < maxSize)
      return 0;
   return 1;
}

void insert(Node n,int pos,List *l){
   if(full(l) || 1 > pos || l->size + 1 < pos)
      return;
      
   int i;
   if(pos != l->size + 1)
   for(i = l->size - 1;i >= pos;i--)
      l->nodes[i] = l->nodes[i - 1];
      
   l->nodes[pos - 1] = n;
   l->size++;
}

Node removeList(int pos,List *l){
   if(empty(l) || 1 > pos || l->size < pos)
      return l->nodes[0];
      
   Node n = l->nodes[pos - 1];
   
   int i;
   if(pos != l->size)
   for(i = pos - 1;i < l->size - 1;i++)
      l->nodes[i] = l->nodes[i + 1];
      
   l->size--;
   return n;
}

int search(Node n,List *l){
   int i;
   for(i = 0;i < l->size;i++)
      if(equalNode(&n,&l->nodes[i]))
         break;
   if(i != l->size)
      return i + 1;
   return -1;
}

Node search_k(int pos,List *l){
   if(1 <= pos && pos <= l->size)
      return l->nodes[pos - 1];
   return l->nodes[0];
}
