/*
Necesita las librerías stdio.h, string.h, mapa/mapa.c
*/

/*Lee de la consola sin contar espacios*/
char* leerDeConsola();

/*Mueve el punto de acuerdo al caracter c,
no hace algo si es movimiento prohibido*/
punto* mover( char c , punto *p , mapa *m );

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

punto* mover( char c , punto *p , mapa *m ){
   dir d = SIN_DIR;
   switch( c ){
      case 'w':   d = NO;    break;
      case 's':   d = SU;      break;
      case 'a':   d = OE;    break;
      case 'd':   d = ES;     break;
      case 'e':   d = AR;   break;
      case 'f':   d = AB;    break;
   }
   irA( d , p );
   if( !esPuntoValido( p , m ) || !esPasillo( p , m ) )
      irA( dirContr( d ) , p );
   
   return p;
}
