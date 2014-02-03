#include <stdio.h>
#include <stdlib.h>

typedef char ListEntry;
typedef ListEntry Entry;

#include "DynamicList.h"

Node* createNode(Entry e){
   Node *n = (Node*)malloc(sizeof(Node));
      n->entry = e;
      n->t = 0;
      n->next = NULL;
   return n;
}

int equalNode(Node *a,Node *b){
   if(a->entry == b->entry)
      return 1;
   return 0;
}

/*Busca secuencialmente en una lista lineal vinculada,
**si un elemento se ha buscado más de 3 veces se mueve
**al frente, de lo contrario se transpone, retorna la
**posición donde lo encontró*/
int busq(Entry entry,List *l){
   if(empty(l))
      return -1;

   Node *aux = l->start,*aux2;

   /*Si está en la 1ra o 2da posición,
   **aquí, mover al frente es igual a transponer*/
   if(aux->entry == entry){
      aux->t++;
      return 1;
   }else if(aux->next != NULL && aux->next->entry == entry){
      aux2 = aux->next;
      aux->next = aux2->next;
      aux2->next = aux;
      l->start = aux2;
      aux2->t++;
      return 1;
   }else if(aux->next == NULL)
      return -1;
   
   int pos = 3;
   /*Si está en i-ésima posición,i > 2, sigue buscando*/
   while(aux->next->next != NULL && aux->next->next->entry != entry){
      aux = aux->next;
      pos++;
   }
   
   /*Si no lo encontró*/
   if(aux->next->next == NULL)
      return -1;
   
   /*Si lo encontró, se registra otra búsqueda más para ese nodo*/
   aux->next->next->t++;
   /*Se mueve al frente/transpone*/
   if(aux->next->next->t >= 3){
      aux2 = aux->next->next;
      aux->next->next = aux->next->next->next;
      aux2->next = l->start;
      l->start = aux2;
      pos = 1;
   }else{
      aux2 = aux->next->next;
      aux->next->next = aux->next->next->next;
      aux2->next = aux->next;
      aux->next = aux2;
      pos--;
   }
   
   return pos;
}

void printList(List *l){
   Node *aux = l->start;
   
   puts("");
   while(aux != NULL){
      printf("(%c,%d)",aux->entry,aux->t);
      aux = aux->next;
   }
   puts("");
}

int main(){
   List l = createList();
   
   int i,j;
   for(i = 0;i < 12;i++)
      insert(createNode('a' + i),i,&l);
      
   printList(&l);
   
   char c[7] = {'d','j','j','l','j','a','d'};
   
   for(j = 0; j < 7; j++){
      i = busq(c[j],&l);
      printList(&l);
      printf("%50c+++|%c en %d",' ',c[j],i);
   }
   
   return 0;
}
