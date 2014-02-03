typedef struct ent{
   uchar dato;
   struct ent *next;
}ent;

DEFINIR_NUEVO_QUEUE( ent )

ent* nuevo_ent( int dato ){
   ent *e = (ent*)malloc(sizeof(ent));
      e->dato = dato;
   return e;
}

/*Sale del programa si no puede leerlo*/
void leerMapa( char* nombre );

/*Guarda el mapa en un archivo de texto*/
void guardarMapa( char* nombre );


/*Lee de la consola sin contar espacios*/
char* leerDeConsola();

/*Mueve el punto de acuerdo al caracter c,
no hace algo si es movimiento prohibido*/
void mover( char c , punto *p );
void iniciarPantalla();

/*Pinta iniciando en x,y con ancho w y largo h*/
void pintarEnPantalla( char** obj , int x , int y , int w , int h );
void pintarMuro( int x , int y );
void pintarPasillo( int x , int y );
void pintarElevadorA( int x , int y );
void pintarElevadorB( int x , int y );
void pintarElevadorC( int x , int y );
void pintarPunto( int x , int y );
void pintarMeta( int x , int y );
void pintarMapa( punto *p );
void imprimirPantalla();

void leerMapa( char* nombre ){
   FILE* fp;
   queue_ent *q;
   int tam = 0, x, y, z, m_i, m_f;
   char s[ 10 ];
   uchar c;
   
   fp = fopen( nombre , "r" );
   if( fp == NULL )   error( "No se pudo abrir mapa." );
   
   fgets( s , sizeof( s ) , fp );   x = atoi( s );
   fgets( s , sizeof( s ) , fp );   y = atoi( s );
   fgets( s , sizeof( s ) , fp );   z = atoi( s );
   fgets( s , sizeof( s ) , fp );   m_i = atoi( s );
   fgets( s , sizeof( s ) , fp );   m_f = atoi( s );
   
   if( x <= 1 || y <= 1 || z <= 1 )
      error( "Mapa muy chico" );
   if( 1024 < x || 1024 < y || 1024 < z )
      error( "Mapa muy grande" );

   q = crear_queue_ent();
   while( !feof( fp ) ){
      c = fgetc ( fp );
      if( c == '1' ){
         insert_queue_ent( nuevo_ent( PASO ) , q );
         tam++;
      }else if( c == '0' ){
         insert_queue_ent( nuevo_ent( MURO ) , q );
         tam++;
      }
   }
   fclose( fp );
   
   if( tam != x*y*z ){
      drop_queue_ent( &q );
      error( "Las dimensiones del mapa no concuerdan." );
   }
   
   crearMapa( x , y , z );
   m->meta_i = m_i;
   m->meta_f = m_f;
   tam = 0;
   while( !empty_queue_ent( q ) ){
      m->coord[ tam++ ] = front_ent( q )->dato;
      free( remove_queue_ent( q ) );
   }
   obtenMetas();
   
   drop_queue_ent( &q );
}

void guardarMapa( char* nombre ){
   FILE *fp = fopen( nombre , "w" );
   if( fp == NULL )   error( "No se pudo guardar el mapa." );
   
   fprintf( fp , "%d\n" , m->lx );
   fprintf( fp , "%d\n" , m->ly );
   fprintf( fp , "%d\n" , m->lz );
   fprintf( fp , "%d\n" , m->meta_i );
   fprintf( fp , "%d\n" , m->meta_f );
   
   int i, j, k, x = m->lx, y = m->ly, z = m->lz;
   for(k = 0; k < z; k++){
      for(j = 0; j < y; j++){
         for(i = 0; i < x; i++){
            if( ES_PASO( i , j , k ) )
               fprintf(fp,"%d",1);
            else
               fprintf(fp,"%d",0);
         }
         fprintf( fp , "\n" );
      }
      fprintf( fp , "------------------------------------\n" );
   }
   fclose( fp );
}
/*Pantalla del laberinto*/
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

void pintarMuro( int x , int y ){
   char *muro[ 5 ] = { "_____" ,
                       "_____" ,
                       "_____" ,
                       "_____" ,
                       "_____" };
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

void pintarElevadorA( int x , int y ){
   char *elev[ 1 ] = { "E" };
   pintarEnPantalla( elev , 5*x + 1 , 5*y + 1 , 1 , 1 );
}

void pintarElevadorB( int x , int y ){
   char *elev[ 1 ] = { "F" };
   pintarEnPantalla( elev , 5*x + 2 , 5*y + 2 , 1 , 1 );
}

void pintarElevadorC( int x , int y ){
   char *elev[ 1 ] = { "X" };
   pintarEnPantalla( elev , 5*x + 1 , 5*y + 1 , 1 , 1 );
}

void pintarPunto( int x , int y ){
   char *punt[ 1 ] = { "O" };
   pintarEnPantalla( punt , 5*x + 1 , 5*y , 1 , 1 );
   pintarEnPantalla( punt , 5*x + 2 , 5*y , 1 , 1 );
   pintarEnPantalla( punt , 5*x + 3 , 5*y , 1 , 1 );
   pintarEnPantalla( punt , 5*x + 1 , 5*y + 4 , 1 , 1 );
   pintarEnPantalla( punt , 5*x + 2 , 5*y + 4 , 1 , 1 );
   pintarEnPantalla( punt , 5*x + 3 , 5*y + 4 , 1 , 1 );
}

void pintarMeta( int x , int y ){
   char *punt[ 1 ] = { "M" };
   pintarEnPantalla( punt , 5*x + 2 , 5*y + 2 , 1 , 1 );
}

void pintarMapa( punto *p ){
   punto *aux = crearPunto( p->x , p->y , p->z , 0 );
   
   iniciarPantalla();
   int i, j;
   for(j = 0; j < 8; j++){
      for(i = 0; i < 16; i++){
         aux->x = p->x + i - 7;
         aux->y = p->y + j - 3;
         if( ES_P_PASO( aux ) )   pintarPasillo( i , j );
         if( aux->x == p->x && aux->y == p->y )
               pintarPunto( i , j );
         if( ES_P_PASO( aux ) && HAY_PASO_AR( aux ) &&
                                      HAY_PASO_AB( aux ) )
               pintarElevadorC( i , j );
         if( ES_P_PASO( aux ) && HAY_PASO_AR( aux ) )
               pintarElevadorA( i , j );
         if( ES_P_PASO( aux ) && HAY_PASO_AB( aux ) )
               pintarElevadorB( i , j );
         if( ES_P_MURO( aux ) )
               pintarMuro( i , j );
         if( ES_META_I( aux ) || ES_META_F( aux ) )
            pintarMeta( i , j );
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

char* leerDeConsola(){
   static char str[ 1024 ];
   
   fgets( str , sizeof( str ) , stdin );
   if(str[strlen(str) - 1] == '\n'){
      str[strlen(str) - 1] = '\0';
   }else{
      char dummy[2];
      do{ fgets( dummy , sizeof(dummy) , stdin );
      }while( dummy[strlen(dummy) - 1] != '\n' );
   }
   
   int i = 0, j = 0;
   while( *(str + j) != '\0'){
      if( *(str + j) != ' ' ){
         *(str + i) = *(str + j);   i++;
      }
      j++;
   }
   *(str + i) = '\0';
   return str;
}

void mover( char c , punto *p ){
   dir d = SIN_DIR;
   switch( c ){
      case 'w':   d = NO;   break;
      case 's':   d = SU;   break;
      case 'a':   d = OE;   break;
      case 'd':   d = ES;   break;
      case 'e':   d = AR;   break;
      case 'f':   d = AB;   break;
   }
   if( HAY_PASO_A( d , p ) )   IR_A( d , p );
}