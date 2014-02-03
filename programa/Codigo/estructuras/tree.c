/*
Necesita la librería: stdlib.h
Para definir un nuevo arbol, node
debe ser del tipo:
struct node{
   struct node* l;
   struct node* r;
   struct node* f;
   ...
}

Se crean las funciones:
stack_node crear_stack_node();
int        empty_stack_node();
node*      top_node(stack_node);
void       push(node,stack_node);
node*      pop(stack_node);
*/
#define DEFINIR_NUEVO_TREE( node ) \
typedef node tree_##node; \
\
tree_##node* crear_tree_##node(){ return NULL; } \
\
int size_tree_##node( tree_##node *t ){ \
   if( t == NULL )   return 0; \
   return size_tree_##node( t->l ) + 1 + \
          size_tree_##node( t->r ); \
} \
\
node* insert_tree_##node( node *n , tree_##node **t){ \
   if( *t == NULL ){ \
      *t = n; \
      n->l = NULL; \
      n->r = NULL; \
      return n; \
   } \
   if( max_##node( *t , n ) == n ){ \
      (*t)->r = insert_tree_##node( n , &((*t)->r) ); \
      (*t)->r->f = (*t)->r; \
   }else{ \
      (*t)->l = insert_tree_##node( n , &((*t)->l) ); \
      (*t)->l->f = (*t)->l; \
   } \
\
   return *t; \
} \
\
node* remove_min_tree_##node( tree_##node **t ){ \
   node *min; \
   if( *t == NULL ) return NULL; \
   if( (*t)->l == NULL ){ \
      min = *t; \
      if( (*t)->f != NULL ) (*t)->f->l = NULL; \
      *t = (*t)->r; \
      min->r = NULL; \
      return min; \
   } \
   return remove_min_tree_##node( &((*t)->l) ); \
} \
\
node* remove_max_tree_##node( tree_##node **t ){ \
   node *max; \
   if( *t == NULL ) return NULL; \
   if( (*t)->r == NULL ){ \
      max = *t; \
      if( (*t)->f != NULL ) (*t)->f->r = NULL; \
      *t = (*t)->l; \
      max->l = NULL; \
      return max; \
   } \
   return remove_max_tree_##node( &((*t)->r) ); \
} \
\
void drop_tree_##node(tree_##node **t){ \
   if( *t != NULL ){ \
      drop_tree_##node( &((*t)->l) ); \
      drop_tree_##node( &((*t)->r) ); \
      free( *t ); \
   } \
} \

int tree_gen = 1;
