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

/*Llena *int en inorden*/
void fill_inOrder_d( int** , tree_d );

/*Ordena b y lo pone en a */
void order_d( int *a , int *b , int n );

int main(){
   int a[9] = {6,2,2,9,4,7,2,5,8};
   int b[9];
   
   int i, j = sizeof( a ) / sizeof( a[0] );
   
   puts("");
   for(i = 0; i < j; i++)
      printf("%d ", a[i] );

   order_d( b , a , j );
   
   puts("");
   for(i = 0; i < j; i++)
      printf("%d ", b[i] );
   
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

void fill_inOrder_d( int **A , node_d *t ){
   if( t != NULL ){
      fill_inOrder_d( A , t->left );
      **A = t->e;
      (*A)++;
      fill_inOrder_d( A , t->right );
   }
}

/*  B es un arreglo y n su tamaño*/
void order_d( int *A , int *B , int n ){
   tree_d t = NULL;
   
   int aux = n;
   while( aux-- ){
      insert_d( t , *(B++) );
   }
   
   fill_inOrder_d( &A , t );
   
   return;
}
