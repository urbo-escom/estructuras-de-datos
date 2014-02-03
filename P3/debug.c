/*
debug
*/

#define DEBUG_PUNTO 3450
#define DEBUG_DIR   3451

void debug( int debugType , void *var , char *s ){
   printf("%s:", s );
   punto *a;   dir *b;
   dir arr[ 6 ] = {AR,AB,OE,NO,SU,ES};
   char *arr_s[ 6 ] = {"AR","AB","OE","NO","SU","ES"};
   int i;
   switch( debugType ){
      case DEBUG_PUNTO:
         a = (punto*)var;
         printf("(%d,%d,%d),", a->x , a->y , a->z );
         break;
      case DEBUG_DIR:
         b = (dir*)var;
         for(i = 0; i < 6; i++)
            if( (*b) & arr[ i ] ) printf("%s:", arr_s[ i ] );
         printf(",");
         break;
   }
}