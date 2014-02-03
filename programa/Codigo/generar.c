/**************************************************************
Funciones para la generacion y resolucion de laberintos
**************************************************************/

camino* max_camino( camino *a , camino *b ){
   if( a->d <= b->d )   return b;
   return a;
}

camino* crearCamino( int d , punto *i , punto *f ){
   camino *c = malloc1( camino );
   if( c == NULL )   error( "No se pudo crear camino" );
      c->d = d;   c->p_i = INDP( i );   c->p_f = INDP( f );
      c->l = NULL;   c->r = NULL;   c->f = NULL;
   return c;
}

/*Crea punto aleatorio*/
#define P_ALEAT() \
crearPunto( rand()%(m->lx) , rand()%(m->ly) , rand()%(m->lz) , 1 )

#define BORRAR_DIR( elim , d ) (d - (elim))

#define CONV_A_PASO( p ) COORD_P( p ) = PASO

#define ES_DESTRUIBLE( x , y , z ) \
   (ES_MURO( x , y , z ) && \
    (COORD( x , y , z ) <= MURO+1))

#define ES_DESTR_AR( p ) ES_DESTRUIBLE( p->x , p->y , p->z-1 )
#define ES_DESTR_AB( p ) ES_DESTRUIBLE( p->x , p->y , p->z+1 )
#define ES_DESTR_NO( p ) ES_DESTRUIBLE( p->x , p->y-1 , p->z )
#define ES_DESTR_SU( p ) ES_DESTRUIBLE( p->x , p->y+1 , p->z )
#define ES_DESTR_OE( p ) ES_DESTRUIBLE( p->x-1 , p->y , p->z )
#define ES_DESTR_ES( p ) ES_DESTRUIBLE( p->x+1 , p->y , p->z )

#define ACT_MURO( x , y , z ) COORD( x , y , z ) += 1

#define ACT_MUROS_ADY( p ) do{ \
   if( HAY_MURO_AR( p ) ) ACT_MURO( p->x , p->y , p->z-1 ); \
   if( HAY_MURO_AB( p ) ) ACT_MURO( p->x , p->y , p->z+1 ); \
   if( HAY_MURO_NO( p ) ) ACT_MURO( p->x , p->y-1 , p->z ); \
   if( HAY_MURO_SU( p ) ) ACT_MURO( p->x , p->y+1 , p->z ); \
   if( HAY_MURO_OE( p ) ) ACT_MURO( p->x-1 , p->y , p->z ); \
   if( HAY_MURO_ES( p ) ) ACT_MURO( p->x+1 , p->y , p->z ); \
}while( 0 )

#define OBTEN_DIRS_DESTR( p ) do{ \
   p->dv = SIN_DIR;   p->dc = SIN_DIR; \
   if( ES_DESTR_AR( p ) ){ p->dv += AR; p->dc++; } \
   if( ES_DESTR_AB( p ) ){ p->dv += AB; p->dc++; } \
   if( ES_DESTR_NO( p ) ){ p->dv += NO; p->dc++; } \
   if( ES_DESTR_SU( p ) ){ p->dv += SU; p->dc++; } \
   if( ES_DESTR_OE( p ) ){ p->dv += OE; p->dc++; } \
   if( ES_DESTR_ES( p ) ){ p->dv += ES; p->dc++; } \
}while( 0 )

#define OBTEN_DIRS_ACCES( p ) do{ \
   p->dv = SIN_DIR;   p->dc = SIN_DIR; \
   if( HAY_PASO_AR( p ) ){ p->dv += AR; p->dc++; } \
   if( HAY_PASO_AB( p ) ){ p->dv += AB; p->dc++; } \
   if( HAY_PASO_NO( p ) ){ p->dv += NO; p->dc++; } \
   if( HAY_PASO_SU( p ) ){ p->dv += SU; p->dc++; } \
   if( HAY_PASO_OE( p ) ){ p->dv += OE; p->dc++; } \
   if( HAY_PASO_ES( p ) ){ p->dv += ES; p->dc++; } \
}while( 0 )

#define ESCOGER_DIR( p ) \
(HAY_PASO_AR(p) && (p->dv & AR))?AR: \
(HAY_PASO_AB(p) && (p->dv & AB))?AB: \
(HAY_PASO_NO(p) && (p->dv & NO))?NO: \
(HAY_PASO_SU(p) && (p->dv & SU))?SU: \
(HAY_PASO_OE(p) && (p->dv & OE))?OE: \
(HAY_PASO_ES(p) && (p->dv & ES))?ES:SIN_DIR

dir dirAleatoria( dir *d );

void generarLaberinto();

void resolverLaberinto();

dir dirAleatoria( dir *d ){
   dir op1[ 4 ], op2[ 2 ];
   int num_op1 = 0, num_op2 = 0, i;
   
   for(i = 0; i < 6; i++){
      if( (*d) & d_arr[ i ] ){
         if( d_arr[ i ] == AR || d_arr[ i ] == AB )
            op2[ num_op2++ ] = d_arr[ i ];
         else{
            op1[ num_op1++ ] = d_arr[ i ];
         }
      }
   }
   
   if( num_op1 == 0 && num_op2 == 0 )   return SIN_DIR;
   if( num_op1 == 0 ){
      if( num_op2 == 1 )   return op2[ 0 ];
      return op2[ rand()%num_op2 ];
   }
   if( num_op1 == 1 )   return op1[ 0 ];
   return op1[ rand()%num_op1 ];
}

#define debug0( str ) do{ \
   pintarMapa( p ); \
   imprimirPantalla(); \
   printf( "%s:" , str ); \
   debug( DEBUG_PUNTO , p , "Punto" ); \
   debug( DEBUG_DIR , &(p->dv) , "Dir" ); \
   leerDeConsola(); }while( 0 )
#define debug1( s ) if( 1 ) debug0( s )

void generarLaberinto(){
   stack_punto *pila = crear_stack_punto();
   tree_camino *arb = crear_tree_camino();
   
   dir d = SIN_DIR;
   int esNuevaRama = 1, esHoja = 0;
   
   punto *p = P_ALEAT();
   punto *i = p;
      CONV_A_PASO( p );   ACT_MUROS_ADY( p );
   int jh = 1;
   
   do{
      OBTEN_DIRS_DESTR( p );
      if( p->dv != SIN_DIR ){
         if( p->dc != 1 )   push_punto( p , pila );
         d = p->dv;
         p = crearPunto( p->x , p->y , p->z , p->dist );
            IR_A( dirAleatoria( &d ) , p );
            CONV_A_PASO( p );   ACT_MUROS_ADY( p );
         esNuevaRama = 1;
         p->dist++;
      }else{
         if( p == i )   esHoja = 1;
         if( esNuevaRama ){
            insert_tree_camino( crearCamino( p->dist , i , p ) , &arb );
            if( size_tree_camino( arb ) > 4 ){
               free( remove_min_tree_camino( &arb ) );
               free( remove_min_tree_camino( &arb ) );
            }
         }else   free( p );
         p = pop_punto( pila );
         esNuevaRama = 0;
      }
      if( (jh++)%1000000 == 0 ) printf("%d,",jh);
   }while( p != NULL );
   
   /*Escogemos el camino más largo de acuerdo al árbol*/
   camino *cam, *cam2;
   if( esHoja ){
      cam = remove_max_tree_camino( &arb );
      m->meta_i = cam->p_i;
      m->meta_f = cam->p_f;
      free( cam );
   }else{
      cam = remove_max_tree_camino( &arb );
      cam2 = remove_max_tree_camino( &arb );
      m->meta_i = cam->p_f;
      m->meta_f = cam2->p_f;
      free( cam );   free( cam2 );
   }
   
   drop_tree_camino( &arb );
   drop_stack_punto( &pila );
}

#define debug2( str ) do{ \
   pintarMapa( p ); \
   imprimirPantalla(); \
   print( T_PUNTO , r , " Inicio" ); \
   print( T_PUNTO , q , " Final" ); \
   printf( "\n%s:" , str ); \
   print( T_PUNTO , p , " Actual" ); \
   print( T_DIR , &(d) , " DirAnt" ); \
   print( T_DIR , &(p->dv) , " Dir" ); \
   leerDeConsola(); }while( 0 )
#define debug3( s ) if( 1 ) debug2( s )

void resolverLaberinto(){
   stack_punto *pila = crear_stack_punto();
   punto *p = crearPunto( IND_X( m->meta_i ) ,
                          IND_Y( m->meta_i ) ,
                          IND_Z( m->meta_i ) , 1 );
   punto *q = crearPunto( IND_X( m->meta_f ) ,
                          IND_Y( m->meta_f ) ,
                          IND_Z( m->meta_f ) , 1 );
   punto *r = crearPunto( IND_X( m->meta_i ) ,
                          IND_Y( m->meta_i ) ,
                          IND_Z( m->meta_i ) , 1 );
   dir d = SIN_DIR;
   int esDePila = 0;
   debug3("Inicio.");
   do{
      if( !esDePila ) OBTEN_DIRS_ACCES( p );
      debug3("Antes de borrar.");
      if( d != SIN_DIR ){ p->dv = BORRAR_DIR( d , p->dv ); p->dc--; }
      debug3("Antes de decision.");
      if( p->dc == 1 ){
         IR_A( p->dv , p );
         d = DIR_CONTR( p->dv );
         esDePila = 0;debug3("Solo hay un camino.");
      }else if( p->dc > 1 ){
         d = ESCOGER_DIR( p );
         p->dc--;
         p->dv = BORRAR_DIR( d , p->dv );
         debug3("Hay mas de un camino.");
         push_punto( p , pila );
         p = crearPunto( p->x , p->y , p->z , 1 );
         IR_A( d , p );
         d = DIR_CONTR( d );
         esDePila = 0;
      }else if( p->dc == 0 ){
         free( p );
         p = pop_punto( pila );
         d = SIN_DIR;
         debug3("Saco de pila.");
         esDePila = 1;
      }
      debug3("Despues de decision.");
   }while( !ES_META_F( p ) );
   
   while( strncmp( leerDeConsola() , "salir" , 5 ) != 0 ){
      debug3("SE LLEGO A LA META FINAL...!!!!!!!!!!!!!!!");
   }
   
   if( p != NULL )   free( p );
   if( q != NULL )   free( q );
   if( r != NULL )   free( r );
   drop_stack_punto( &pila );
}