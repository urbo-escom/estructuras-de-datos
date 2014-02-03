#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define T_PUNTO 3450
#define T_DIR   3451

void error( char* );

void print( int , void* , char* );

#include "estructuras/stack.c"
#include "estructuras/queue.c"
#include "estructuras/tree.c"
#include "mapa.c"
#include "lectura.c"
#include "generar.c"

void navegar( char *nombre ){
   leerMapa( nombre );
   punto *jug = crearPunto( IND_X( m->meta_i ) ,
                            IND_Y( m->meta_i ) ,
                            IND_Z( m->meta_i ) , 1 );
   punto *q = crearPunto( IND_X( m->meta_f ) ,
                          IND_Y( m->meta_f ) ,
                          IND_Z( m->meta_f ) , 1 );
   punto *r = crearPunto( IND_X( m->meta_i ) ,
                          IND_Y( m->meta_i ) ,
                          IND_Z( m->meta_i ) , 1 );
   char *s = NULL;
   while( 1 ){
      pintarMapa( jug );
      imprimirPantalla();
      if( ES_META_F( jug ) )   printf("META FINAL!!!!!\n");
      if( ES_META_I( jug ) )   printf("META INICIAL.\n");
      print( T_PUNTO , r , "INICIAL " );
      print( T_PUNTO , q , "FINAL " );
      print( T_PUNTO , jug , "ACTUAL " );
      s = leerDeConsola();
      if( s[ 0 ] == '0' ){ break; }
      mover( s[ 0 ] , jug );
   }
   free( jug );
   free( r );
   free( q );
   borrarMapa();
}

int main( int argc , char** argv ){
   
   if( argc == 1 )   error( "No hay nada que hacer" );
   
   
   if( strncmp( argv[ 1 ] , "gen" , strlen( argv[ 0 ] ) ) == 0 ){
      if( argc <= 5 )   error( "Informacion insuficiente" );
      printf( "Creando mapa '%s'...\n" , argv[ 2 ] );
      int x = atoi( argv[ 3 ] );
      int y = atoi( argv[ 4 ] );
      int z = atoi( argv[ 5 ] );
      if( x < 4 || y < 4 || z <4 )   error( "Mapa muy chico..." );
      crearMapa( x , y , z );
      generarLaberinto();
      guardarMapa( argv[ 2 ] );
      puts( "Mapa guardado exitosamente." );
      return 0;
   }
   
   if( strncmp( argv[ 1 ] , "nav" , strlen( argv[ 0 ] ) ) == 0 ){
      if( argc == 2 )   error( "No se conoce nombre del mapa" );
      navegar( argv[ 2 ] );
      return 0;
   }
   
   if( strncmp( argv[ 1 ] , "res" , strlen( argv[ 0 ] ) ) == 0 ){
      if( argc == 2 )   error( "No se conoce nombre del mapa" );
      leerMapa( argv[ 2 ] );   resolverLaberinto();
      return 0;
   }
   
   return 0;
}

void error( char* txt ){
   puts( txt );
   exit( EXIT_FAILURE );
}

void print( int tipo , void *var , char *s ){
   printf("%s:", s );
   punto *a;   dir *b;
   dir arr[ 6 ] = {AR,AB,OE,NO,SU,ES};
   char *arr_s[ 6 ] = {"AR","AB","OE","NO","SU","ES"};
   int i;
   switch( tipo ){
      case T_PUNTO:
         a = (punto*)var;
         printf("(%d,%d,%d),", a->x , a->y , a->z );
         break;
      case T_DIR:
         b = (dir*)var;
         for(i = 0; i < 6; i++)
            if( (*b) & arr[ i ] ) printf("%s:", arr_s[ i ] );
         printf(",");
         break;
   }
}
