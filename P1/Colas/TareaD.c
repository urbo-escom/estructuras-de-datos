#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
   char plate[4];
   int mvts;
}QueueEntry;

#define maxSize 10
#include "StaticQueue.h"

Node createNode(char *plate){
   Node n;
      strncpy(n.entry.plate,plate,3);
      n.entry.mvts = 0;
   return n;
}

#define FULL_PARKING_LOT 1000
#define PARKING_SUCCEEDED 1001

#define CAR_NOT_FOUND 1002
#define UNPARKING_SUCCEEDED 1003
#define AVAILABLE_SPACE 1004

int park(char *plate,Queue *prkLot,Queue *wtLot){
   if(full(prkLot)){
      if(!full(wtLot))
         insert(createNode(plate),wtLot);
      return FULL_PARKING_LOT;
   }

   insert(createNode(plate),prkLot);
   return PARKING_SUCCEEDED;
}

int unPark(char *plate,Node *car1,Node *car2,Queue *prkLot,Queue *wtLot){
   if(empty(prkLot))
      return CAR_NOT_FOUND;
      
   Queue tempLot = createQueue();
   int found = 0,movs = 0,k = 0;
   do{
      k++;
      *car1 = removeQueue(prkLot);
      if(strncmp(car1->entry.plate,plate,3) == 0){
         found = 1;
         car1->entry.mvts++;
         break;
      }else{
         car1->entry.mvts++;
         insert(*car1,prkLot);
         movs++;
      }
   }while(k != size(prkLot));
   
   if(found)
   while(size(prkLot) - movs++)
      insert(removeQueue(prkLot),prkLot);

   clean(prkLot);
   
   if(!found)
      return CAR_NOT_FOUND;
   
   if(!empty(wtLot)){
      *car2 = removeQueue(wtLot);
      insert(*car2,prkLot);
      return AVAILABLE_SPACE;
   }
   
   return UNPARKING_SUCCEEDED;
}

int isAValidVehiclePlate(char *plate){
   if(isdigit(plate[0]) &&
      isdigit(plate[1]) &&
      isdigit(plate[2]))
      return 1;
   return 0;
}

#define PARK 'A'
#define UNPARK 'D'

void showContent(Queue *q){
   int i = q->front;
   for(;i <= q->back;i++)
      printf("%.3s movs:%2d\n",q->nodes[i].entry.plate,q->nodes[i].entry.mvts);
   printf("\n");
}

int main(){
   Queue prkLot = createQueue();
   Queue wtLot = createQueue();
   Node car1;
   Node car2;
   
   for(;;){
      char s[1024];s[0] = '\0';
      int aux;
      
      showContent(&prkLot);
      showContent(&wtLot);
      gets(s);if(strlen(s) == 0)break;
      
      if(!isAValidVehiclePlate(s + 1) || strlen(s) > 4){
         printf("Wrong plate: '%.3s'.\n",s + 1);
         continue;
      }
      
      if(s[0] == PARK){
         aux = park(s + 1,&prkLot,&wtLot);
         printf("Car '%.3s' has arrived.\n",s + 1);
      }else if(s[0] == UNPARK){
         aux = unPark(s + 1,&car1,&car2,&prkLot,&wtLot);
         printf("Waiting for car '%.3s'.\n",s + 1);
      }else{
         printf("Unkown action: '%c'.\n",s[0]);
         continue;
      }
      
      switch(aux){
         case FULL_PARKING_LOT:
            printf("The parking lot is full.\n");
            printf("-The car '%.3s' has to wait.\n",s + 1);
            break;
         case PARKING_SUCCEEDED:
            printf("Parking succeeded.\n");
            break;
         case CAR_NOT_FOUND:
            printf("Sorry, car '%.3s' is not in the parking lot.\n",s + 1);
            break;
         case UNPARKING_SUCCEEDED:
            printf("Unparking succeeded.\n");
            printf("-Car '%.3s' has been moved %d times.\n",car1.entry.plate,car1.entry.mvts);
            break;
         case AVAILABLE_SPACE:
            printf("Unparking succeeded.\n");
            printf("-Car '%.3s' has been moved %d times.\n",car1.entry.plate,car1.entry.mvts);
            printf("-There's space available.\n");
            printf("-The car '%.3s' is now parking.\n",car2.entry.plate);
            break;
      }
   }
   
   return 0;
}
