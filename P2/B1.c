typedef char Entry;
typedef struct node Node;
typedef struct list List;

void createList(List*);
bool empty(List*);
void insert(Node*,int,List*);
Entry removeList(int,List*);

struct node{
   Entry e;
   Node *next;
   int f;
};

struct list{
   Node *start;
};