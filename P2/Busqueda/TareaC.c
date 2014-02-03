#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 20

typedef struct ListEntry{
   int id;
   char nombre[21];
   char puesto[21];
   double sueldo;
}ListEntry;

#include "StaticList.h"

Node createNode(int id , char *nombre,
                char *puesto , double sueldo){
   Node n;
      n.entry.id = id%1000;
      strncpy(n.entry.nombre,nombre,sizeof(n.entry.nombre));
      strncpy(n.entry.puesto,puesto,sizeof(n.entry.puesto));
      n.entry.sueldo = sueldo;

   return n;
}

int equalNode(Node *a,Node *b){
   if(a->entry.id == b->entry.id &&
      strncmp(a->entry.nombre,b->entry.nombre,
         sizeof(a->entry.nombre)) == 0 &&
      strncmp(a->entry.puesto,b->entry.puesto,
         sizeof(a->entry.puesto)) == 0 &&
      a->entry.sueldo == b->entry.sueldo)
      return 1;
   return 0;
}

int interpol( int id , List *l ){
   int min = 0, max = l->size - 1;
   int i;
   
   while(min <= max){
      i = min;
      if( min != max )
      i += (max-min)/
           (l->nodes[max].entry.id -
            l->nodes[min].entry.id)*
           (id - min);
      
      if( l->nodes[i].entry.id == id)
         return i;
      else if( id < l->nodes[i].entry.id )
         max = i - 1;
      else if( l->nodes[i].entry.id < id )
         min = i + 1;

   }
   
   return -1;
}

void print( List *l ){
   int i;
   for(i = 0; i < l->size; i++){
      printf("%d\n",i);
      printf("ID: %d\n",l->nodes[i].entry.id);
      printf("Nombre: ");
      puts(l->nodes[i].entry.nombre);
      printf("Puesto: ");
      puts(l->nodes[i].entry.puesto);
      printf("Sueldo: %.2f\n",l->nodes[i].entry.sueldo);
   }
}

int main(){
   List l = createList();
   int i,j;
   
   insert( createNode( 234 , "Alberto" ,
                       "Puesto_1" , 4232.0 ) , 1 , &l );
   insert( createNode( 780 , "Juan" ,
                       "Puesto_4" , 3209.0 ) , 2 , &l );
   insert( createNode( 781 , "Pablo" ,
                       "Puesto_7" , 6210.0 ) , 3 , &l );
   insert( createNode( 890 , "Hector" ,
                       "Puesto_8" , 7242.0 ) , 4 , &l );
   insert( createNode( 999 , "Jose" ,
                       "Puesto_3" , 4032.0 ) , 5 , &l );
   
   int a[9] = {230,781,978,999,234,780,1000,-3,1001};
   
   print( &l );
   for(j = 0; j < 9; j++){
      i = interpol( a[j] , &l );
      printf("-------ID: %d encontrado en %d\n",a[j],i);
   }
   
   return 0;
}
