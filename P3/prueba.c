#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "error.c"
#include "mapa/mapa.c"
#include "io/pantalla.c"
#include "io/consola.c"
#include "estructuras/stack.c"
#include "estructuras/queue.c"
#include "io/lectura.c"

DEFINIR_NUEVO_STACK( punto )
DEFINIR_NUEVO_QUEUE( punto )

#include "debug.c"
#include "generar.c"

int main( int argc , char** argv ){
   
   mapa *m = /*crearMapa( 128 , 128 , 128 );
   generarLaberinto( m );*/
   leerMapa( "nuevoMapa2.txt" );
   punto *jug = crearPunto( 0 , 0 , 0 );
   char *s = NULL;
   while( 1 ){
      pintarMapa( jug , m );
      imprimirPantalla();
      s = leerDeConsola();
      if( s[ 0 ] == '0' ){ break; }
      mover( s[ 0 ] , jug , m );
   }
   
   guardarMapa( "nuevoMapa2.txt" , m );
   puts( "Mapa guardado exitosamente." );
   
   free( jug );
   borrarMapa( &m );
   
   return 0;
}
