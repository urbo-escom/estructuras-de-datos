#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
   int i;
   char nombre[10];
   char apellido[10];
   float promedio;
}QueueEntry;

#include "DynamicQueue.h"

Node* createNode(int i,char *nombre,char *apellido,float promedio){
   Node *n = (Node*)malloc(sizeof(Node));
      n->entry.i = i;
      strncpy(n->entry.nombre,nombre,10);
      strncpy(n->entry.apellido,apellido,10);
      n->entry.promedio = promedio;
      n->next = NULL;
      
   return n;
}

Node* maxNode(Node *a,Node *b){
   if(a->entry.promedio >= b->entry.promedio)
      return a;
   return b;
}

Node* DPQremove(Queue *dpq){
   if(empty(dpq))
      return NULL;
      
   Node *aux = dpq->front;
   Node *max = aux;
   
   while(aux->next != NULL){
      max = maxNode(max,aux->next);
      aux = aux->next;
   }
   
   aux = dpq->front;
   if(max == aux)
      return removeQueue(dpq);
      
   while(aux->next != max)
      aux = aux->next;
      
   aux->next = max->next;
   if(aux->next == NULL)
      dpq->back = aux;
   
   max->next = NULL;
   return max;
}

#define ALUMNO_ATENDIDO 1002
#define ALUMNO_REGISTRADO 1001

Queue cola;
Node *actual;

void mostrarEstado(){
   int i = 0;
   Node *aux = cola.front;
   
   printf("----------------------------------------COLA----------------\n");
   for(;aux != NULL;aux = aux->next){
      printf("%2d Nom.: %-9s,Apel.: %-9s,Prom.: %1.2f\n",
             aux->entry.i,
             aux->entry.nombre,
             aux->entry.apellido,
             aux->entry.promedio);
   }
   printf("----------------------------------------COLA----------------\n\n");
   
   if(actual != NULL)
   printf("Atendiendo... %2d: Nom.: %-9s,Apel.: %-9s,Prom.: %1.2f\n",
          actual->entry.i,
          actual->entry.nombre,
          actual->entry.apellido,
          actual->entry.promedio);
}

void atenderSig(){
   if(actual != NULL){
      printf("----Se termino de atender a %2d Nom.: %-9s,Apel.: %-9s,Prom.: %1.2f\n",
             actual->entry.i,
             actual->entry.nombre,
             actual->entry.apellido,
             actual->entry.promedio);
      free(actual);
   }
   
   if(!empty(&cola)){
      actual = DPQremove(&cola);
      printf("----Ahora se atendera a %2d Nom.: %-9s,Apel.: %-9s,Prom.: %1.2f\n\n",
             actual->entry.i,
             actual->entry.nombre,
             actual->entry.apellido,
             actual->entry.promedio);
   }
}

void registrarAlumno(Node *n){
   insert(n,&cola);
   printf("++++Se registro a %2d Nom.: %-9s,Apel.: %-9s,Prom.: %1.2f\n\n",
          n->entry.i,
          n->entry.nombre,
          n->entry.apellido,
          n->entry.promedio);
}

#include "time.h"

char *nombres[] = {
"Abel","Alberto","Alejandro","Carlos","Celia",
"Daniel","Fernando","Simon","Manuel","Juan"};

char *apellidos[] = {
"Montez","Garcia","Gonzalez","Rodriguez","Lopez",
"Sanchez","Fernandez","Perez","Martinez","Hernandez"};

Node* alumnoAleatorio(int i){
   return createNode(i,nombres[rand()%10],
                     apellidos[rand()%10],
                     ((rand()%401) + 600)/100.0);
}

int main(){
   cola = createQueue();
   actual = NULL;
   
   srand(time(NULL));
   
   int minutos = 0;
   
   for(minutos = 1;minutos <= 180;minutos++){
      char s[1024];s[0] = '\0';
   
      system("CLS");
      
      if(minutos <= 60)
      registrarAlumno(alumnoAleatorio(minutos));
      if(minutos%3 == 0 || minutos == 1)
         atenderSig();

      mostrarEstado();
      printf("Minuto: %d\nPress ENTER...\n",minutos);
      gets(s);
   }
   
   return 0;
}
