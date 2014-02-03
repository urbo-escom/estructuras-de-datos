#include <stdio.h>
#include <stdlib.h>

#include "TareaA.c"

int dataRelation( data a , data b ){
   if( a <= b)
      return -1;
   return 1;
}

void preOrderPrint_d( tree_d t );

void inOrderPrint_d( tree_d t );

void postOrderPrint_d( tree_d t );

/*Devuelve imagen reflejo de árbol*/
tree_d swap_d( tree_d );

int main(){
   int a[9] = {6,2,2,9,4,7,2,5,8};
   int i;
   
   tree_d t1 = NULL, t2 = NULL;
   for(i = 0; i < sizeof( a ) / sizeof( a[0] ); i++)
      insert_d( t1 , a[i] );

   t2 = swap_d( t1 );
   
   /*Si en verdad t2 es la imagen de t1,
   se imprimirá en forma descendente*/
   printf("InOrden\n");
   inOrderPrint_d( t1 );
   printf("\nInOrden, imagen\n");
   inOrderPrint_d( t2 );
   
   return 0;
}

void preOrderPrint_d( tree_d t ){
   if( t != NULL ){
      printf( "%d " , t->e );
      preOrderPrint_d( t->left );
      preOrderPrint_d( t->right );
   }
}

void inOrderPrint_d( tree_d t ){
   if( t != NULL ){
      inOrderPrint_d( t->left );
      printf( "%d " , t->e );
      inOrderPrint_d( t->right );
   }
}

void postOrderPrint_d( tree_d t ){
   if( t != NULL ){
      postOrderPrint_d( t->left );
      postOrderPrint_d( t->right );
      printf( "%d " , t->e );
   }
}

tree_d swap_d( node_d *t ){
   if( t == NULL )
      return t;
   
   if( t->left == NULL && t->right == NULL )
      return create_node_d( t->e );
   
   tree_d aux = create_node_d( t->e );
   aux->left = swap_d( t->right );
      if( aux->left != NULL )
         aux->left->father = aux;
   aux->right = swap_d( t->left );
      if( aux->right != NULL )
         aux->right->father = aux;
   
   return aux;
}
