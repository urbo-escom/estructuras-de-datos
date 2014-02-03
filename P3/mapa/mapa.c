typedef unsigned char uchar;
typedef uchar dir;

#define TODAS_DIRS ((1 << 6) - 1)
#define AR         (1 << 5)
#define AB         (1 << 4)
#define NO         (1 << 3)
#define SU         (1 << 2)
#define ES         (1 << 1)
#define OE         (1 << 0)
#define SIN_DIR    (  0   )

#define MURO     (  0   )
#define PASILLO  (1 << 3)
#define META     (PASILLO+1)

dir d_arr[ 6 ] = { AR , NO , ES , OE , SU , AB };

/*coord es un array 1d que sirve para guardar un array 3d*/
typedef struct mapa{
   uchar *coord;
   int meta_i, meta_f;
   int lx, ly, lz, lt;
}mapa;

typedef struct punto{
   int x, y, z;
   dir ds;
   struct punto *next;
}punto;

/*Devuelve un mapa con memoria almacenada
y coord todas como MURO*/
mapa* crearMapa( int , int , int );

/*Libera la memoria del mapa y retorna NULL*/
mapa* borrarMapa( mapa** );

void obtenMetas( mapa *m );

punto* crearPunto( int , int , int );

/*Checa si el punto p no se sale del mapa m*/
int esPuntoValido( punto *p , mapa *m );

/*Resuelve el indice 1d del punto 3d p en el mapa m*/
int indP( punto *p , mapa *m );

/*Resuelve los indices 3d del indice 1d ind del mapa m*/
void puntoInd( punto *p , int ind , mapa *m );

/*Devuelve la dirrecion en memoria del punto p en el mapa m*/
uchar* coordP( punto *p , mapa *m );

/*Devuelve la dirección contraria*/
dir dirContr( dir d );

/*Altera el punto p, no importa si se sale del mapa*/
punto* irA( dir d , punto *p );

int esPasillo( punto *p , mapa *m );

int esMuro( punto *p , mapa *m );

/*Hay acceso hacia arriba*/
int esElevA( punto *p , mapa *m );

/*Hay acceso hacia abajo*/
int esElevB( punto *p , mapa *m );

/*Hay acceso hacia ambos*/
int esElev( punto *p , mapa *m );

/*Borra toda información previa*/
punto* convierteAPasillo( punto *p , mapa *m );

#define malloc2( size , var ) (var*)malloc((size)*sizeof(var))
#define malloc1( var ) malloc2( 1 , var )

mapa* crearMapa( int x , int y , int z ){
   mapa *m = malloc1( mapa );
   if( m == NULL )   return NULL;
      m->lx = x;  m->ly = y;   m->lz = z;
      m->lt = x*y*z;
   m->coord = malloc2( x*y*z , uchar );
   if( m->coord == NULL )   return borrarMapa( &m );
   
   int i;
   for(i = 0; i < m->lt; i++)
      m->coord[ i ] = MURO;
   
   return m;
}

mapa* borrarMapa( mapa **m ){
   if( *m == NULL )   return NULL;
   free( *m );   *m = NULL;
   return *m;
}

void obtenMetas( mapa *m ){
   int i = 0, j = (m->lx)*(m->ly)*(m->lz);
   
   for(; i < j; i++)
      if( m->coord[ i ] == META ){ m->meta_i = i++; break; }
   for(; i < j; i++)
      if( m->coord[ i ] == META ){ m->meta_f = i; break; }
}

punto* crearPunto( int x , int y , int z ){
   punto *p = malloc1( punto );
   if( p == NULL )   return NULL;
      p->x = x;   p->y = y;   p->z = z;
      p->next = NULL;
   return p;
}

int esPuntoValido( punto *p , mapa *m ){
   return 0 <= p->x && p->x < m->lx &&
          0 <= p->y && p->y < m->ly &&
          0 <= p->z && p->z < m->lz;
}

int indP( punto *p , mapa *m ){
   return (p->z)*(m->ly)*(m->lx) +
          (p->y)*(m->lx) +
          (p->x);
}

void puntoInd( punto *p , int ind , mapa *m ){
   p->x = ind%(m->lx);   ind = (ind - p->x)/(m->lx);
   p->y = ind%(m->ly);   ind = (ind - p->y)/(m->ly);
   p->z = ind%(m->lz);
}

uchar* coordP( punto *p , mapa *m ){
   return m->coord + indP( p , m );
}

dir dirContr( dir d ){
   switch( d ){
      case AR:   return AB;
      case AB:   return AR;
      case OE:   return ES;
      case NO:   return SU;
      case SU:   return NO;
      case ES:   return OE;
   }
   return SIN_DIR;
}

punto* irA( dir d , punto *p ){
   switch( d ){
      case AR:   p->z--;   return p;
      case AB:   p->z++;   return p;
      case OE:   p->x--;   return p;
      case NO:   p->y--;   return p;
      case SU:   p->y++;   return p;
      case ES:   p->x++;   return p;
   }
   return p;
}

int esPasillo( punto *p , mapa *m ){
   return *( coordP( p , m ) ) & PASILLO;
}

int esMuro( punto *p , mapa *m ){ return !esPasillo( p , m ); }

int esElevA( punto *p , mapa *m ){
   if( esMuro( p , m ) )   return 0;
   irA( AR , p );
   if( esPuntoValido( p , m ) && esPasillo( p , m ) ){
      irA( AB , p );
      return 1;
   }
   irA( AB , p );
   return 0;
}

int esElevB( punto *p , mapa *m ){
   if( esMuro( p , m ) )   return 0;
   irA( AB , p );
   if( esPuntoValido( p , m ) && esPasillo( p , m ) ){
      irA( AR , p );
      return 1;
   }
   irA( AR , p );
   return 0;
}

int esElev( punto *p , mapa *m ){
   return esElevA( p , m ) && esElevB( p , m );
}

punto* convierteAPasillo( punto *p , mapa *m ){
   *( coordP( p , m ) ) = PASILLO;
   return p;
}