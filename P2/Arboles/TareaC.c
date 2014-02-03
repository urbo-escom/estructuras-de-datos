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

int main(){
   int a[8] = {6,3,4,-2,9,7,8,5};
   int i;
   
   tree_d t1 = NULL;
   for(i = 0; i < sizeof( a ) / sizeof( a[0] ); i++)
      insert_d( t1 , a[i] );
   
   puts("IMPRESION");
   preOrderPrint_d( t1 );puts("");
   inOrderPrint_d( t1 );puts("");
   postOrderPrint_d( t1 );
   
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