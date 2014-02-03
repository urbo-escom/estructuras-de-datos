#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 20

typedef struct ListEntry{
   char nombre[21];
   char apeMat[21];
   char apePat[21];
   char boleta[11];
   double prom;
}ListEntry;

typedef union Key{
   char nombre[20];
   char apeMat[20];
   char apePat[20];
   char boleta[10];
   double prom;
}Key;

#include "StaticList.h"

Node createNode(char *nombre,char *apePat,char *apeMat,
                char *boleta,double prom){
   Node n;
      strncpy(n.entry.nombre,nombre,sizeof(n.entry.nombre));
      strncpy(n.entry.apeMat,apeMat,sizeof(n.entry.apeMat));
      strncpy(n.entry.apePat,apePat,sizeof(n.entry.apePat));
      strncpy(n.entry.boleta,boleta,sizeof(n.entry.boleta));
      n.entry.prom = prom;

   return n;
}

int equalNode(Node *a,Node *b){
   if(strncmp(a->entry.nombre,b->entry.nombre,
         sizeof(a->entry.nombre)) == 0 &&
      strncmp(a->entry.apeMat,b->entry.apeMat,
         sizeof(a->entry.apeMat)) == 0 &&
      strncmp(a->entry.apePat,b->entry.apePat,
         sizeof(a->entry.apePat)) == 0 &&
      strncmp(a->entry.boleta,b->entry.boleta,
         sizeof(a->entry.boleta)) == 0 &&
      a->entry.prom == b->entry.prom)
      return 1;
   return 0;
}

int keycmpNOMBRE(Key *k,Node *n){
   return strncmp( k->nombre,n->entry.nombre,
                   sizeof( n->entry.nombre ) );
}

int keycmpAPEPAT(Key *k,Node *n){
   return strncmp( k->apePat,n->entry.apePat,
                   sizeof( n->entry.apePat ) );
}

int keycmpAPEMAT(Key *k,Node *n){
   return strncmp( k->apeMat,n->entry.apeMat,
                   sizeof( n->entry.apeMat ) );
}

int keycmpBOLETA(Key *k,Node *n){
   return strncmp( k->boleta,n->entry.boleta,
                   sizeof( n->entry.boleta ) );
}

int keycmpPROM(Key *k,Node *n){
   if( k->prom == n->entry.prom )
      return 0;
   else if( k->prom < n->entry.prom )
      return -1;
   return 1;
}

#define BUSQ_NOMBRE 32248
#define BUSQ_APEPAT 3223
#define BUSQ_APEMAT 32231
#define BUSQ_BOLETA 3242
#define BUSQ_PROM 323
/*Busqueda binaria, retorna -1 si no encuentra algo*/
/*Para que funcione, la llave de los elementos ya
debe estar ordenada*/
int busqBin( int busq , Key *k , List *l ){
   int min = 0, max = l->size - 1;
   int middle , aux = 0;
   
   int (*keyCmp) ( Key* , Node* );
   
   switch( busq ){
      case BUSQ_NOMBRE:
         keyCmp = &keycmpNOMBRE;
         break;
      case BUSQ_APEPAT:
         keyCmp = &keycmpAPEPAT;
         break;
      case BUSQ_APEMAT:
         keyCmp = &keycmpAPEMAT;
         break;
      case BUSQ_BOLETA:
         keyCmp = &keycmpBOLETA;
         break;
      case BUSQ_PROM:
         keyCmp = &keycmpPROM;
         break;
   }
   
   while(min <= max){
      middle = (min + max) / 2;
      aux = keyCmp( k , &l->nodes[middle] );
      if( aux == 0 )
         return middle;
      else if( aux < 0 )
         max = middle - 1;
      else if( 0 < aux )
         min = middle + 1;
   }
   
   return -1;
}

void print( List *l ){
   int i;
   for(i = 0; i < l->size; i++){
      printf("%d\n",i+1);
      printf("Nombre: ");
      puts(l->nodes[i].entry.nombre);
      printf("Apellido paterno: ");
      puts(l->nodes[i].entry.apePat);
      printf("Apellido materno: ");
      puts(l->nodes[i].entry.apeMat);
      printf("Boleta: ");
      puts(l->nodes[i].entry.boleta);
      printf("Prom: %.2f\n",l->nodes[i].entry.prom);
   }
}

int main(){
   List l = createList();
   Key k;
   int i;
   
   insert( createNode( "Abel" , "Alfar" , "Benitez" ,
                       "2012000000" , 6.0 ) , 1 , &l );
   insert( createNode( "Axel" , "Alvarez" , "Bolanios" ,
                       "2012000020" , 7.5 ) , 2 , &l );
   insert( createNode( "Carlos" , "Salazar" , "Fernandez" ,
                       "2012000100" , 7.6 ) , 3 , &l );
   insert( createNode( "Teodoro" , "Sanchez" , "Gonzalez" ,
                       "2012000120" , 8.1 ) , 4 , &l );
   insert( createNode( "Ximena" , "Urrutia" , "Hernandez" ,
                       "2012003220" , 8.3 ) , 5 , &l );
   
   print( &l );
   
   strncpy( k.nombre , "Axel" , 20 );
   i = busqBin( BUSQ_NOMBRE , &k , &l );
   printf( "Nombre: %s, se encontro en %d\n" ,
            k.nombre , i+1 );

   strncpy( k.apePat , "Sanchez" , 20 );
   i = busqBin( BUSQ_APEPAT , &k , &l );
   printf( "Apellido paterno: %s, se encontro en %d\n" ,
            k.apePat , i+1 );
            
   strncpy( k.apeMat , "Benitez" , 20 );
   i = busqBin( BUSQ_APEMAT , &k , &l );
   printf( "Apellido materno: %s, se encontro en %d\n" ,
            k.apeMat , i+1 );
   
   strncpy( k.boleta , "2012000120" , 10 );
   i = busqBin( BUSQ_BOLETA , &k , &l );
   printf( "Boleta: %s, se encontro en %d\n" ,
            k.boleta , i+1 );
            
   k.prom = 8.3;
   i = busqBin( BUSQ_PROM , &k , &l );
   printf( "Promedio: %.2f, se encontro en %d\n" ,
            k.prom , i+1 );
   
   return 0;
}
