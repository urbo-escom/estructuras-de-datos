/*Pantalla del laberinto*/
/*
Necesita las librerías stdio.h,stdlib.h,mapa/mapa.c
*/
#define LARGO 80
#define ANCHO 40

char pantalla[ ANCHO ][ LARGO + 1 ];

void iniciarPantalla(){
   int i , j;
   for( i = 0 ; i < ANCHO ; i++ )
      for( j = 0 ; j < LARGO + 1 ; j++ )
         if( j == LARGO )
            pantalla[ i ][ j ] = '\0';
         else
            pantalla[ i ][ j ] = '.';
}

/*Pinta iniciando en x,y con ancho w y largo h*/
void pintarEnPantalla( char** obj ,
                       int x , int y ,
                       int w , int h ){
   int i , j;
   for( i = 0 ; i < w ; i++ )
      for( j = 0 ; j < h ; j++ )
         pantalla[ y+j ][ x+i ] = obj[ j ][ i ];
}

void pintarMuro( int x , int y , int n ){
   char *muro[ 5 ] = { "+---+" ,
                       "|+ +|" ,
                       "| + |" ,
                       "|+ +|" ,
                       "+---+" };
   pintarEnPantalla( muro , 5*x , 5*y , 5 , 5 );
}

void pintarPasillo( int x , int y ){
   char *paso[ 5 ] = { "     " ,
                       "     " ,
                       "     " ,
                       "     " ,
                       "     " };
   pintarEnPantalla( paso , 5*x , 5*y , 5 , 5 );
}

void pintarElevador( int x , int y ){
   char *elev[ 5 ] = { "     " ,
                       " ||| " ,
                       " ||| " ,
                       " ||| " ,
                       "     " };
   pintarEnPantalla( elev , 5*x , 5*y , 5 , 5 );
}

void pintarPunto( int x , int y ){
   char *punt[ 5 ] = { "     " ,
                       " OOO " ,
                       " OOO " ,
                       " OOO " ,
                       "     " };
   pintarEnPantalla( punt , 5*x , 5*y , 5 , 5 );
}

void pintarMapa( punto *p , mapa *m ){
   punto *aux = crearPunto( p->x , p->y , p->z );
   
   iniciarPantalla();
   int i, j;
   for(j = 0; j < 8; j++){
      for(i = 0; i < 16; i++){
         aux->x = p->x + i - 7;
         aux->y = p->y + j - 3;
         if( esPuntoValido( aux , m ) ){
            if( aux->x == p->x && aux->y == p->y )
               pintarPunto( i , j );
            else if( esElevA( aux , m ) || esElevB( aux , m ) )
               pintarElevador( i , j );
            else if( esPasillo( aux , m ) )
               pintarPasillo( i , j );
            else if( esMuro( aux , m ) )
               pintarMuro( i , j , *( coordP( p , m ) ) );
         }
      }
   }
   free( aux );
}

void imprimirPantalla(){
   int i;
   system( "CLS" );
   for(i = 0; i < ANCHO; i++)
      printf("%s",pantalla[ i ]);
}
