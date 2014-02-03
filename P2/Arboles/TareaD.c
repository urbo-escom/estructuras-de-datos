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

/*a. # de nodos*/
int tree_size_d( node_d *t );

/*b. Suma de nodos*/
int tree_sum_d( node_d *t );

/*c. Profundidad de árbol*/
int tree_depth_d( node_d *t );

/*d. Ocurrencias en árbol*/
int times_in_tree_d( node_d *t , data value );

int main(){
   int a[9] = {6,2,2,9,4,7,2,5,8};
   int i;
   
   tree_d t1 = NULL;
   for(i = 0; i < sizeof( a ) / sizeof( a[0] ); i++)
      insert_d( t1 , a[i] );

   puts("InOrden");
   inOrderPrint_d( t1 );   
   printf("\nTamanio: %d", tree_size_d( t1 ) );
   printf("\nSuma: %d", tree_sum_d( t1 ) );
   printf("\nProfundidad: %d", tree_depth_d( t1 ) );
   printf("\nOcurrencia de 2: %d",
          times_in_tree_d( t1 , 2 ) );
   
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

/*a.*/
int tree_size_d( node_d *t ){
   if( t == NULL )
      return 0;
   return tree_size_d( t->left ) + 1 +
          tree_size_d( t->right );
}

/*b.*/
int tree_sum_d( node_d *t ){
   if( t == NULL )
      return 0;
   return tree_sum_d( t->left ) + t->e +
          tree_sum_d( t->right );
}

/*c.*/
int tree_depth_d( node_d *t ){
   if( t == NULL )
      return -1;
   if( t->left == NULL && t->right == NULL )
      return 0;

   int depth_l = 0, depth_r = 0;
   
   if( t->left != NULL )
      depth_l = tree_depth_d( t->left );
   if( t->right != NULL )
      depth_r = tree_depth_d( t->right );
      
   if( depth_l >= depth_r )
      return 1 + depth_l;
   return 1 + depth_r;
}

/*d.*/
int times_in_tree_d( node_d *t , data value ){
   if( t == NULL )
      return 0;
   return times_in_tree_d( t->left , value ) +
            (t->e == value) +
          times_in_tree_d( t->right , value );
}