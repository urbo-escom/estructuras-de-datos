/*
Necesita las librerías stdlib.h
mapa/mapa.c, estructuras/pilas.c, estructuras/colas.c
*/

punto* puntoAleatorio( mapa *m );

dir dirAleatoria( dir *d );

int esDestruible( punto *p , mapa *m );

dir dirDestruibles( punto *p , mapa *m );

void actualizaMurosAdy( punto *p , mapa *m );

void borrarDir( dir *elim , dir *d );

void generarLaberinto( mapa *m );



punto* puntoAleatorio( mapa *m ){
   return
      crearPunto( rand()%(m->lx) , rand()%(m->ly) , rand()%(m->lz) );
}

dir dirAleatoria( dir *d ){
   #define CARGA (500)
   dir opciones[ 4*CARGA + 2 ];
   int num_op = 0, i , j;
   
   for(i = 0; i < 6; i++){
      if( (*d) & d_arr[ i ] ){
         if( d_arr[ i ] == AR || d_arr[ i ] == AB )
            opciones[ num_op++ ] = d_arr[ i ];
         else{
            for(j = 0; j < CARGA; j++)
            opciones[ num_op++ ] = d_arr[ i ];
         }
      }
   }
   
   if( num_op == 0 )   return SIN_DIR;
   if( num_op == 1 )   return opciones[ 0 ];
   return opciones[ rand()%num_op ];
}

int esDestruible( punto *p , mapa *m ){
   return esMuro( p , m ) && *( coordP( p , m ) ) == 1;
}

dir dirDestruibles( punto *p , mapa *m ){
   if( !esPuntoValido( p , m ) )   return SIN_DIR;
   dir ds = SIN_DIR;
   int i;
   
   for(i = 0; i < 6; i++){
      irA( d_arr[ i ] , p );
      if( esPuntoValido( p , m ) && esDestruible( p , m ) )
         ds += d_arr[ i ];
      irA( dirContr( d_arr[ i ] ) , p );
   }
   
   return ds;
}

void actualizaMurosAdy( punto *p , mapa *m ){
   int i;
   for(i = 0; i < 6; i++){
      irA( d_arr[ i ] , p );
      if( esPuntoValido( p , m ) && esMuro( p , m ) )
         *( coordP( p , m ) ) += 1;
      irA( dirContr( d_arr[ i ] ) , p );
   }
}

void borrarDir( dir *elim , dir *d ){ *d &= !( *elim ); }

void generarLaberinto( mapa *m ){
   stack_punto *pila = crear_stack_punto();
   queue_punto *cola = crear_queue_punto();
   
   dir d = SIN_DIR;
   int esNuevaRama = 1;
   
   //punto *p = puntoAleatorio( m );
   punto *p = crearPunto( 0 , 0 , 0 );
      convierteAPasillo( p , m );
      actualizaMurosAdy( p , m );
   #define debug1( s ) do{ \
      pintarMapa( p , m ); \
      imprimirPantalla(); \
      debug( 0 , m , s ); \
      debug( DEBUG_PUNTO , p , "Punto" ); \
      debug( DEBUG_DIR , &d , "Dir" ); \
      leerDeConsola(); }while( 0 ) \
      
   #define DEBUG 0
   int jh = 0;
   if( DEBUG )
      debug1( "Inicio-------------" );
   do{
      d = dirDestruibles( p , m );
      if( DEBUG )   debug1("Antes   de decision");
      if( d != SIN_DIR ){
         push_punto( p , pila );
         p = crearPunto( p->x , p->y , p->z );
            irA( dirAleatoria( &d ) , p );
            convierteAPasillo( p , m );
            actualizaMurosAdy( p , m );
         esNuevaRama = 1;
      }else{
         if( esNuevaRama )
            insert_queue_punto( p , cola );
         else
            free( p );
         p = pop_punto( pila );
         esNuevaRama = 0;
      }
      if( p != NULL ) if( DEBUG )
      debug1("Despues de decision");
      if( (jh++)%100000 == 0 )
         printf("%d,",jh);
   }while( p != NULL );
   drop_queue_punto( &cola );/*
   while( !empty_queue_punto( cola ) ){
      printf("(%d,%d,%d)", front_punto( cola )->x ,
                           front_punto( cola )->y ,
                           front_punto( cola )->z );
      free( remove_queue_punto( cola ) );
   }//*/
}