#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

float charToFloat(char c);

/*Hace la operación binaria indicada por op*/
float operate( char op, float a , float b );

/*Evalúa una expresión infija correctamente formada*/
/*  *expr apuntará al final de la expresión*/
float prefxSlv( char **expr );

int main(){
   char *t[5] = {"1","/63","^+^32^42/12",
                 "^+^53+*361/12",
                 "/4+1/^12+2/^32+2/^52+2/^72+2^92"};
   
   int i;
   for(i = 0; i < 5; i++){
      puts(t[i]);
      printf( "\t= %.5f\n\n\n" , prefxSlv( &t[i] ) );
   }
   
   return 0;
}

float charToFloat(char c){
   char s[2];   
   s[0] = c;   s[1] = '\0';
   
   return atof(s);
}

float operate( char op , float a , float b ){
   switch( op ){
      case '^':
         return pow( a , b );
      case '*':
         return a * b;
      case '/':
         return a / b;
      case '+':
         return a + b;
      case '-':
         return a - b;
      case '%':
         return (float)(((int)a) % ((int)b));
      default:
         return 0.0f;
   }
}

/*Justo de después de evaluar el caso
base, *expr apuntará a la posición
sig. al fin de la expresión*/
float prefxSlv( char **expr ){
   /*Caso base, un dígito*/
   if( isdigit( *( (*expr)++ ) ) ){
      return charToFloat( *( *expr - 1 ) );
   }
   
   /*Recursión, operador y dos operandos*/
   int op = *( (*expr) - 1 );
   float A = prefxSlv( expr );
   float B = prefxSlv( expr );
   return operate( op , A , B );
}
/*
NO LEER SI SE CREE EN EL FUNCIONAMIENTO DEL ALGORITMO

Nota: Originalmente se propuso
'return operate( **expr, prefxSlv( expr ),
                         prefxSlv( expr ) );'
en vez de las líneas 64 a 68 pero ya que en C
no hay garantía de que el orden de evaluación
de parámetros sea de izq. a der., esta evaluación
no funcionaría, en una expresión = +AB, podría
evaluar por ejemplo a 'operate( \0 , B , A )' que
no tendría sentido, por eso se cambió a calcular
antes los operandos; la demostración se basa en el
algoritmo original suponiendo que sí se evalúan los
parámetros de izq. a der. pero es igual de válida para
el algoritmo implementado.

Demostración de que funciona el algoritmo recursivo:
$,# representan operadores binarios cualquiera
A,B,C dígitos cualquiera

--Inducción sobre el número de operadores (n)

+Casos bases:
n = 0:
   *expr -> {'A'}
   prefxSlv( &expr ) = A, *expr -> \0
n = 1:
   *expr -> {'$','A','B'}
   prefxSlv( &expr ) = operate( '$' , prefxSlv( &expr ),
                                      prefxSlv( &expr ) )
      ya que *expr -> {'A','B'} antes del 1er prefxSlv
      1er prefxSlv( &expr ) = A, *expr -> {'B'},
      2do prefxSlv( &expr ) = B, *expr -> \0
   prefxSlv( &expr ) = operate( '$' , A , B ) = $AB,
      *expr -> \0
n = 2:
   *expr -> {'$','A','#','B','C'}
   prefxSlv( &expr ) = operate( '$' , prefxSlv( &expr ),
                                      prefxSlv( &expr ) )
      ya que *expr -> {'A','#','B','C'} antes del 1er prefxSlv
         1er prefxSlv( &expr ) = A, *expr -> {'#','B','C'}
         2do prefxSlv( &expr ) = #BC, *expr -> \0 (ver n = 1)
   prefxSlv( &expr ) = operate( '$' , A , #BC ) = $A#BC
   
   *expr -> {'$','#','A','B','C'}
   prefxSlv( &expr ) = operate( '$' , prefxSlv( &expr ),
                                      prefxSlv( &expr ) )
      ya que *expr -> {'#','A','B','C'} antes del 1er prefxSlv
         1er prefxSlv( &expr ) = #AB, *expr -> {'C'} (ver n = 1)
         2do prefxSlv( &expr ) = C, *expr -> \0
   prefxSlv( &expr ) = operate( '$' , #AB , C ) = $#ABC

+Inducción (completa):
-Con cierto n > 2,
prefxSlv( &expr ) funciona, es correcto e igual
a la expresión que comienza en *expr si *expr
tiene de 0 a n operadores; además, deja *expr
apuntando a la posición sig. del final de la
expresión.

-Con n+1 operadores,
*expr debe ser de la forma $AB donde, A y B son
subexpresiones que tienen de 0 a n operadores
cada uno (si no fuera así, $AB tendría más de
n+1 operadores), con esto, *expr -> $AB
   prefxSlv( &expr ) = operate( '$' , prefxSlv( &expr ),
                                      prefxSlv( &expr ) )
      ya que *expr -> A antes del 1er prefxSlv
         1er prefxSlv( &expr ) = A, *expr -> B
         2do prefxSlv( &expr ) = B, *expr -> \0
   prefxSlv( &expr ) = operate( '$' , A , B ) = $AB,
      *expr = \0.
Así, con n+1 operadores, prefxSlv( &expr ) también es
igual a la expresión que comienza en *expr y deja *expr
apuntando a la posición sig. del final de expresión.

Por lo tanto,

+Para una expresión *expr de cualquier número de
operadores n >= 0, prefxSlv( expr ) funciona,
es correcto e igual a *expr y deja a *expr apuntando
a la posición sig. del final de *expr
*/