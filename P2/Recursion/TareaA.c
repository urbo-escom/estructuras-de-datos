#include <stdio.h>

#define maxSize 5

typedef int Node;

typedef struct Stack{
   int size;
   char c;
   Node nodes[maxSize];
}Stack;

#define createStack(s,ch) do{ \
   (s).size = 0; \
   (s).c = ch; \
}while(0)

#define push(x,s) do{ \
   (s).nodes[(s).size++] = x; \
}while(0)

#define top(s) (s).nodes[(s).size - 1]

#define pop(s) do{ (s).size--; }while(0)

#define size(s) (s).size

void display();

void hanoi( int , Stack* , Stack* , Stack* );

Stack t[3];

int main(){
   int i;
      createStack( t[0] , 'A' );
      createStack( t[1] , 'B' );
      createStack( t[2] , 'C' );

   for(i = maxSize; i > 0; i--)
      push( i , t[0] );
   
   display();
   hanoi( size( t[0] ) , t , t+1 , t+2 );
   
   return 0;
}

void display(){
   int i,j;
   for(i = maxSize; i > 0; i--){
      for(j = 0; j < 3; j++){
         if( i <= size(t[j]) )
            printf("%2d",t[j].nodes[i - 1]);
         else
            printf("%2s"," ");
      }
      puts("");
   }
   printf("%2s%2s%2s\n","A","B","C");
}

void hanoi( int d , Stack *a ,
                    Stack *b ,
                    Stack *c ){
   if( d > 0 ){
      hanoi( d - 1 , a , c , b );
      
      push( top( *a ) , *c );
      pop( *a );
      display();
      printf( "%d, %c a %c\n\n" ,
              d , a->c , c->c );
      
      hanoi( d - 1 , b , a , c );
   }
}