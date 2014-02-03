/*VER Arboles/TareaC.c PARA CAPTURAS DE PANTALLAS*/
/*
data por default es int
debe ser especificado antes de un include
*/
#ifndef data
   #define data int
#endif

typedef struct node_d{
   data e;
   
   struct node_d *left;
   struct node_d *right;
   struct node_d *father;
}node_d;

typedef node_d* tree_d;

#ifndef REL_FUNCTION
   #define REL_FUNCTION 1234567

/*DEBE SER ESPECIFICADA*/
/*Devuelve valor < 0 si a debe ir a la
izq. de b, valor > 0 en caso contrario*/
int dataRelation( data a , data b );

#endif

/*Operaciones*/

/*Crea nodo*/
node_d* create_node_d( data );

/*Agrega nodo*/
node_d* insert_d( tree_d , data );

/*Borra arbol*/
void drop_node_d( tree_d );

data info_d( node_d* );

node_d* left_d( node_d* );
node_d* right_d( node_d* );
node_d* father_d( node_d* );
node_d* brother_d( node_d* );

int isLeft_d( node_d* );
int isRight_d( node_d* );
int isRoot_d( node_d* );

/*Implementación dinámica*/
node_d* create_node_d( data e ){
   node_d *n = (node_d*)malloc(sizeof(node_d));
      n->e = e;
      n->left = NULL;
      n->right = NULL;
      n->father = NULL;
   return n;
}

/*Para arbol t vacío, se debe usar t = insert_d( t , e )*/
node_d* insert_d( node_d *t , data e ){
   if( t == NULL ){
      t = create_node_d( e );
   }else{
      if( dataRelation( e , t->e ) < 0 ){
         t->left = insert_d( t->left , e );
         t->left->father = t;
      }else{
         t->right = insert_d( t->right , e );
         t->right->father = t;
      }
   }
   
   /*Sirve para asignar al hijo de t, por eso
   la recursión t->hijo = insert_d( t->hijo , e ),
   útil cuando t->hijo es NULL, trivial cuando no,
   ya que t->hijo permanece inalterado y se devuelve
   el mismo valor (t->hijo = t->hijo)*/
   return t;
}

#define insert_d( t , e ) do{ \
   if( t == NULL ) \
      t = insert_d( t , e ); \
   else \
      insert_d( t , e ); \
}while(0)

void drop_node_d( node_d *n ){
   if( n != NULL){
      drop_node_d( left_d( n ) );
      drop_node_d( right_d( n ) );
      free( n );
   }
}

data info_d( node_d *n ){ return n->e; }

node_d* left_d( node_d *n ){ return n->left; }
node_d* right_d( node_d *n ){ return n->right; }
node_d* father_d( node_d *n ){ return n->father; }
node_d* brother_d( node_d *n ){
   if( isRoot_d( n ) )   return NULL;
   if( n->father->left == n )
      return n->father->right;
   return n->father->left;
}

int isLeft_d( node_d *n ){
   return !isRoot_d( n ) && n == n->father->left;
}

int isRight_d( node_d *n ){
   return !isRoot_d( n ) && n == n->father->right;
}

int isRoot_d( node_d *n ){ return n->father == NULL; }
