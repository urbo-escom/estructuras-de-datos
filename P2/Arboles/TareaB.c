/*VER Arboles/TareaC.c PARA CAPTURAS DE PANTALLAS*/
/*
maxSize por default es 33,
data por default es int
deben ser especificados antes de un include
*/
#ifndef maxSize
   #define maxSize 33
#endif
#ifndef data
   #define data int
#endif

typedef struct node_s{
   data e;
   
   int left;
   int right;
   int father;
   
   int node_p;
}node_s;

typedef node_s* tree_s;

#ifndef REL_FUNCTION
   #define REL_FUNCTION 1234567

/*DEBE SER ESPECIFICADA*/
/*Devuelve valor < 0 si a debe ir a la
izq. de b, valor > 0 en caso contrario*/
int dataRelation( data a , data b );

#endif

/*Operaciones*/

/*Crea nodo*/
node_s create_node_s( data );

/*Agrega hijos*/
node_s* insert_s( tree_s , data );

/*Borra arbol*/
void drop_node_s( tree_s );

data info_s( node_s* );

node_s* left_s( node_s* );
node_s* right_s( node_s* );
node_s* father_s( node_s* );
node_s* brother_s( node_s* );

int isLeft_s( node_s* );
int isRight_s( node_s* );
int isRoot_s( node_s* );