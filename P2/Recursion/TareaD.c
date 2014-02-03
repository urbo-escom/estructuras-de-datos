#include <stdio.h>

int com(int n,int k);

int main(){
   int n,k;

   for(n = 1;n < 13;n++){
      for(k = 1;k <= n + 1;k++)
         printf("%3d ",com(n,k));
      puts("");
   }
   
   return 0;
}

int com(int n,int k){
   /*Hay 0 formas de elegir más de n personas*/
   if(n < k)
      return 0;
   /*Hay n formas de elegir a 1 persona de n personas*/
   else if(k == 1)
      return n;
   else
      return com(n - 1,k) + com(n - 1,k - 1);
}
/*
NO LEER SI SE CREE EN EL FUNCIONAMIENTO DEL ALGORITMO

Demostración de que funciona el algoritmo recursivo,

+com(n,k) funciona, es correcto e igual a
0 cuando n < k, para cuando n >= k:

--Inducción sobre n
+Casos bases:
n = 1:
   k = 1:
   com(1,1) = 1
n = 2:
   k = 1:
   com(2,1) = 2
   k = 2:
   com(2,2) = com(1,2) + com(1,1) = 0 + 1 = 1

+Inducción (completa):
-Con cierto n >= 1,
com(0,k), com(1,k), com(2,k),..., com(n,k) funcionan y
son correctos desde k = 1 hasta k = n

-Con n+1,

com(n+1,k) = com(n,k) + com(n,k-1),
com(n,k) y com(n,k-1) funcionan y son correctos
desde k = 1 hasta k = n, por lo tanto com(n+1,k)
funciona y es correcto desde k = 1 hasta k = n,

falta revisar k = n+1
com(n+1,k) = com(n+1,n+1) = com(n,n+1) + com(n,n) =
0 + com(n,n) = com(n,n)
com(n,n) funciona y es correcto, por lo que,
com(n+1,k) funciona y es correcto desde k = 1 hasta k = n+1;
por lo tanto:

+Para todo n,k >= 1, com(n,k) funciona y es correcto
*/