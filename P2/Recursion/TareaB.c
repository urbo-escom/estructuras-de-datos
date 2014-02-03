#include <stdio.h>

int pow2(int a,int b);

int main(){
   int a = 3,b;
   
   for(a = 2;a < 9;a++){
      for(b = 0;b < 8;b++)
         printf("%7d ",pow2(a,b));
      puts("");
   }
   return 0;
}

/*Si b es par, se calcula la raíz cuadrada de a^b,
y se devuelve el cuadrado de esta última; si b es
impar, se calcula la raiz cuadrada de a^b y se devuelve
el cuadrado, pero multiplicado por a*/
int pow2( int a , int b ){
   /*Caso base*/
   if( b == 0 )
      return 1;
   /*Recursión*/
   if( b % 2 ){
      b = pow2( a , b/2 );
      return a*b*b;
   }else{
      a = pow2( a , b/2 );
      return a*a;
   }
}
/*
NO LEER SI SE CREE EN EL FUNCIONAMIENTO DEL ALGORITMO

Demostración de que funciona el algoritmo recursivo:

--Inducción sobre b
+Casos bases:
b = 0:
   pow2(a,0) = 1 = a^0
b = 1:
   pow2(a,1) = a*pow2(a,0)*pow2(a,0) = a*1*1 = a = a^1
b = 2:
   pow2(a,2) = pow2(a,1)*pow2(a,1) = a*a = a^2

+Inducción (completa):
-Con cierto b > 1,
pow2(a,0), pow2(a,1), pow2(a,2),..., pow2(a,b)
funcionan y son correctos para cualquier a

-Con b+1,

Si b+1 es impar:
   pow2(a,b+1) = a*pow2(a,(b+1)/2)*pow2(a,(b+1)/2),
      ya que (b+1)/2 = b/2 en división entera,
      se puede reescribir como:
   pow2(a,b+1) = a*pow2(a,b/2)*pow2(a,b/2),
      como b/2 < b, pow2(a,b/2) funciona, es correcto
      e igual a a^(b/2),
   pow2(a,b+1) =
      a*a^(b/2)*a^(b/2) = a^(1+b/2+b/2) = a^(b+1)
Si b+1 es par:
   pow2(a,b+1) = pow2(a,(b+1)/2)*pow2(a,(b+1)/2),
      como (b+1)/2 < b, pow2(a,(b+1)/2) funciona,
      es correcto e igual a a^((b+1)/2)
   pow2(a,b+1) = a^((b+1)/2)*a^((b+1)/2) =
                 a^((b+1)/2+(b+1)/2) = a^(b+1)

Por lo que pow2(a,b+1) funciona y es correcto
para cualquier a, por lo tanto,

+Para todo b >= 0, pow2(a,b) funciona y es
correcto para cualquier a
*/