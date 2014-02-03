#include <stdio.h>

#define bool int
#define false 0
#define true !false

int sequentialSearch(int,int[]);
int binarySearch1(int,int[]);
int binarySearch2(int,int,int,int[]);
int interpolationSearch1(int,int[]);
int interpolationSearch2(int,int,int,int[]);

/*Búsqueda secuencial, retorna -1 si no encuentra algo*/
int sequentialSearch(int value,int v[]){
   /*Busca empezando en 0 hasta el tamaño del arreglo*/
   int i,j = sizeof(v) / sizeof(v[0]);
   for(i = 0;i < j;i++)
      /*Si encuentra el valor, deja de buscar*/
      if(v[i] == value)
         break;
   /*Si encontró algo, debe estar entre 0 y j-1*/
   if(i < j)
      return i;
   return -1;
}

/*Busqueda binaria, retorna -1 si no encuentra algo*/
int binarySearch1(int value,int v[]){
   /*Busca con limite inferior en 0 y superior en el tamaño del arreglo,
   **encuentra la mitad y devuelve el indice si los valores son iguales,
   **sino, busca en la mitad inferior/superior de acuerdo a su relación
   **con el valor de en medio, cambiando los valores inf. y sup.
   **Se detiene cuando los limites se invierten y no encontró el indice*/
   int min = 0,max = sizeof(v) / sizeof(v[0]);
   int middle;
   while(min <= max){
      middle = (min + max) / 2;
      if(v[middle] == value)
         return middle;
      else if(value < v[middle])
         max = middle - 1;
      else if(v[middle] < value)
         min = middle + 1;
   }
   return -1;
}

/*Busqueda binaria recursiva, retorna -1 si no encuentra algo*/
int binarySearch2(int value,int min,int max,int v[]){
   if(min > max)
      return -1;

   int middle = (min + max) / 2;
   if(v[middle] == value)
      return middle;
   else if(value < v[middle])
      return binarySearch2(value,min,middle - 1,v);
   else if(v[middle] < value)
      return binarySearch2(value,middle + 1,max,v);
   
   return -1;
}

/*Busqueda con interpolación lineal, retorna -1 si no encuentra algo*/
int interpolationSearch1(int value,int v[]){
   int min = 0,max = sizeof(v) / sizeof(v[0]) - 1;
   int index;
   while(min <= max){
      index = min + (max-min) / (v[max]-v[min]) * (value - min);
      if(v[index] == value)
         return index;
      else if(value < v[index])
         max = index - 1;
      else if(v[index] < value)
         min = index + 1;
   }
   return -1;
}

/*Busqueda recursiva con interpolación lineal, retorna -1 si no encuentra algo*/
int interpolationSearch2(int value,int min,int max,int v[]){
   if(min > max)
      return -1;

   int index = min + (max - min) / (v[max] - v[min]) * (value - min);
   if(v[index] == value)
      return index;
   else if(value < v[index])
      return interpolationSearch2(value,min,index - 1,v);
   else if(v[index] < value)
      return interpolationSearch2(value,index + 1,max,v);
      
   return -1;
}

int main(int argc,char *argv[]){
   int i;
   for(i = 0;i < argc;i++)
      puts(argv[i]);
   return 0;
}
