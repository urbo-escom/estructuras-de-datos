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
mapa* leerMapa( char* nombre );

/*Guarda un mapa en un archivo de texto*/
void guardarMapa( char* nombre , mapa *m );

mapa* leerMapa( char* nombre ){
   FILE* fp;
   queue_ent *q;
   mapa *m;
   int tam = 0, x, y, z;
   char s[ 10 ];
   uchar c;
   
   fp = fopen( nombre , "r" );
   if( fp == NULL )   error( errIO[ 0 ] );
   
   fgets( s , sizeof( s ) , fp );
      x = atoi( s );
   fgets( s , sizeof( s ) , fp );
      y = atoi( s );
   fgets( s , sizeof( s ) , fp );
      z = atoi( s );
   
   if( x <= 1 || y <= 1 || z <= 1 )   error( errIO[ 1 ] );
   if( 1024 < x || 1024 < y || 1024 < z )   error( errIO[ 2 ] );
   
   q = crear_queue_ent();
   while( !feof( fp ) ){
      c = fgetc ( fp );
      if( c == '1' ){
         insert_queue_ent( nuevo_ent( PASILLO ) , q );
         tam++;
      }else if( c == '0' ){
         insert_queue_ent( nuevo_ent( MURO ) , q );
         tam++;
      }
   }
   fclose( fp );
   
   if( tam != x*y*z ){
      drop_queue_ent( &q );
      error( errIO[ 3 ] );
   }
   
   m = crearMapa( x , y , z );
   tam = 0;
   while( !empty_queue_ent( q ) ){
      m->coord[ tam++ ] = front_ent( q )->dato;
      free( remove_queue_ent( q ) );
   }
   obtenMetas( m );
   
   drop_queue_ent( &q );
   
   return m;
}

void guardarMapa( char* nombre , mapa *m ){
   FILE *fp = fopen( nombre , "w" );
   if( fp == NULL )   error( errIO[ 4 ] );
   
   fprintf( fp , "%.4d\n" , m->lx );
   fprintf( fp , "%.4d\n" , m->ly );
   fprintf( fp , "%.4d\n" , m->lz );
   
   int i, j, k, x = m->lx, y = m->ly, z = m->lz;
   punto *p = crearPunto( 0,0,0 );
   for(k = 0; k < z; k++){
      for(j = 0; j < y; j++){
         for(i = 0; i < x; i++){p->x = i;p->y = j;p->z = k;
            if( esPasillo( p , m ) )
               fprintf(fp,"%d",1);
            else
               fprintf(fp,"%d",0);
            //fprintf( fp , "%d" , m->coord[ i + j*x + k*x*y ] );
         }
         fprintf( fp , "\n" );
      }
      fprintf( fp , "------------------------------------\n" );
   }
   free( p );
   fclose( fp );
}
