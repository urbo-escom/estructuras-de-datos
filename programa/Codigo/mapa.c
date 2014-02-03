typedef unsigned char uchar;
typedef uchar dir;

#define malloc2( size , var ) (var*)malloc((size)*sizeof(var))
#define malloc1( var ) malloc2( 1 , var )

/*Estan definidos así para mayor facilidad*/
#define AR         (1 << 5)
#define NO         (1 << 4)
#define OE         (1 << 3)
#define AB         (1 << 2)
#define SU         (1 << 1)
#define ES         (1 << 0)
#define SIN_DIR    (  0   )

#define MURO  (  0   )
#define PASO  (1 << 3)
#define META  (PASO+1)

dir d_arr[ 6 ] = { AR , NO , ES , AB , SU , OE };

/*coord es un array 1d que sirve para guardar un array 3d*/
typedef struct mapa{
   uchar *coord;
   int meta_i, meta_f;
   int lx, ly, lz, lt;
}mapa;

mapa *m = NULL;

typedef struct punto{
   int x, y, z;
   dir dc, dv;
   int dist;
   struct punto *next;
}punto;

typedef struct camino{
   int d, p_i, p_f;
   struct camino *l, *r, *f;
}camino;

/*Crea el mapa con memoria almacenada
y coord todas como MURO*/
void crearMapa( int , int , int );

/*Libera la memoria del mapa y retorna NULL*/
void borrarMapa();

void obtenMetas();

punto* crearPunto( int x , int y , int z , int d );

camino* max_camino( camino *a , camino *b );

camino* crearCamino( int d , punto *i , punto *f );

void crearMapa( int x , int y , int z ){
   m = malloc1( mapa );
   if( m == NULL )   error( "El mapa no se pudo crear" );
      m->lx = x;  m->ly = y;   m->lz = z;
      m->lt = x*y*z;
   m->coord = malloc2( x*y*z , uchar );
   if( m->coord == NULL ){ borrarMapa(); error("Mapa sin crear"); }
   int i;
   for(i = 0; i < m->lt; i++)
      m->coord[ i ] = MURO;
}

void borrarMapa(){
   if( m == NULL )   return;
   free( m->coord );   free( m );   m = NULL;
}

void obtenMetas(){
   int i = 0, j = (m->lx)*(m->ly)*(m->lz);
   for(; i < j; i++)
      if( m->coord[ i ] == META ){ m->meta_i = i++; break; }
   for(; i < j; i++)
      if( m->coord[ i ] == META ){ m->meta_f = i; break; }
}

punto* crearPunto( int x , int y , int z , int dist ){
   punto *p = malloc1( punto );
   if( p == NULL )   return NULL;
      p->x = x;   p->y = y;   p->z = z;   p->dc = (p->dv = SIN_DIR);
      p->next = NULL;   p->dist = dist;
   return p;
}

DEFINIR_NUEVO_STACK( punto )
DEFINIR_NUEVO_QUEUE( punto )
DEFINIR_NUEVO_TREE( camino )

/*Acceso al indice 1d con coord 3d*/
#define COORD( x , y , z ) \
   m->coord[ ((x)+(y)*(m->lx)+(z)*(m->ly)*(m->lx)) ]

/*Es coord 3d valida*/
#define ES_VAL( x , y , z ) \
(( 0 <= (x) && (x) < m->lx ) && \
 ( 0 <= (y) && (y) < m->ly ) && \
 ( 0 <= (z) && (z) < m->lz ))

#define ES_PASO( x , y , z ) \
   (ES_VAL( x , y , z ) && \
    ((COORD( x , y , z ) & PASO) != 0))

#define ES_MURO( x , y , z ) \
   (ES_VAL( x , y , z ) && \
    ((COORD( x , y , z) & PASO) == 0))

#define HAY_PASO_AR( p ) ES_PASO( p->x , p->y , p->z-1 )
#define HAY_PASO_AB( p ) ES_PASO( p->x , p->y , p->z+1 )
#define HAY_PASO_NO( p ) ES_PASO( p->x , p->y-1 , p->z )
#define HAY_PASO_SU( p ) ES_PASO( p->x , p->y+1 , p->z )
#define HAY_PASO_OE( p ) ES_PASO( p->x-1 , p->y , p->z )
#define HAY_PASO_ES( p ) ES_PASO( p->x+1 , p->y , p->z )

#define HAY_MURO_AR( p ) ES_MURO( p->x , p->y , p->z-1 )
#define HAY_MURO_AB( p ) ES_MURO( p->x , p->y , p->z+1 )
#define HAY_MURO_NO( p ) ES_MURO( p->x , p->y-1 , p->z )
#define HAY_MURO_SU( p ) ES_MURO( p->x , p->y+1 , p->z )
#define HAY_MURO_OE( p ) ES_MURO( p->x-1 , p->y , p->z )
#define HAY_MURO_ES( p ) ES_MURO( p->x+1 , p->y , p->z )

#define HAY_PASO_A( d , p ) \
(d == AR)?(HAY_PASO_AR(p))?1:0: \
(d == AB)?(HAY_PASO_AB(p))?1:0: \
(d == NO)?(HAY_PASO_NO(p))?1:0: \
(d == SU)?(HAY_PASO_SU(p))?1:0: \
(d == OE)?(HAY_PASO_OE(p))?1:0: \
(d == ES)?(HAY_PASO_ES(p))?1:0:0 \

/*Se mueve a d*/
#define IR_A( d , p ) do{ \
   switch( d ){ \
      case AR: p->z--; break; case AB: p->z++; break; \
      case NO: p->y--; break; case SU: p->y++; break; \
      case OE: p->x--; break; case ES: p->x++; break; \
   } \
}while( 0 ) \

/*Resuelve indice 1d de coord 3d*/
#define INDP( p ) ((p->x)+((p->y)+(p->z)*(m->ly))*(m->lx))
/*Acceso a indice 1d con punto 3d p*/
#define COORD_P( p ) COORD( p->x , p->y , p->z )

#define ES_META_I( p ) (INDP( p ) == m->meta_i)
#define ES_META_F( p ) (INDP( p ) == m->meta_f)

#define IGUAL_P( p , q ) \
   (p->x == q->x && p->y == q->y && p->z == q->z)

/*Resuelve los indices 3d del indice 1d*/
#define IND_X( ind ) ((ind)%(m->lx))
#define IND_Y( ind ) ((((ind)-IND_X(ind))/(m->lx))%(m->ly))
#define IND_Z( ind ) (((((ind)-IND_X(ind))/(m->lx))-IND_Y(ind))/(m->ly))

#define ES_P_PASO( p ) ES_PASO( p->x , p->y , p->z )
#define ES_P_MURO( p ) ES_MURO( p->x , p->y , p->z )

#define ES_P_VAL( p ) ES_VAL( p->x , p->y , p->z )

/*Direccion contraria: AR-AB,NO-SU,ES,OE*/
#define DIR_CONTR( d ) (d > AB)?(d >> 3):(d << 3)