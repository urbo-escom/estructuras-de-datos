#include <stdio.h>

/*Caso base, B tiene solo 1 elemento,
B es subconjunto de A si ese elemento
pertenece a A,
Recursión, B es subconjunto de A si
sus subconjuntos son subconjuntos de A*/
int esSubConj( int *A , int n , int *B , int m );

void print(char,int*,int);

#define esSubConj2( A , B ) \
   esSubConj( A , sizeof( A ) / sizeof( A[0] ) , \
              B , sizeof( B ) / sizeof( B[0] ) )
              
#define print2( c , A ) \
   print( c , A , sizeof( A ) / sizeof( A[0] ) )

int main(){
   int A[9] = {1,2,3,4,5,6,7,8,56};
   int B[6] = {5,8,56,1,2,0};
   
   print2( 'A' , A );
   print2( 'B' , B );
   
   if( esSubConj2( A , B ) )
      printf("\n---B esta contenido en A");
   else
      printf("\n---B no esta contenido en A");

   B[5] = 3;
   
   print2( 'A' , A );
   print2( 'B' , B );
   
   if( esSubConj2( A , B ) )
      printf("\n---B esta contenido en A");
   else
      printf("\n---B no esta contenido en A");

   return 0;
}

void print( char c , int *A , int n ){
   printf("\n%c: ",c);
   while( n-- )
      printf("%d ",*( A++ ));
}

int esSub( int *A , int n , int *B , int m ){
   /*Caso base*/
   if( n == (m == 1) )
      return *A == *B;
   
   /*Recursión*/
   if( *A == *B )
      
}
