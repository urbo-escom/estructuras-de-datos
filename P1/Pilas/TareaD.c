#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
   char plate[4];
   int mvts;
}StackEntry;

#define maxSize 10
#include "StaticStack.h"

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

int park(char *plate,Stack *prkLot){
   if(full(prkLot))
      return FULL_PARKING_LOT;
      
   push(createNode(plate),prkLot);
   return PARKING_SUCCEEDED;
}

int unPark(char *plate,Node *car,Stack *prkLot){
   if(empty(prkLot))
      return CAR_NOT_FOUND;
      
   Stack tempPrkLot = createStack();
   int found = 0;
   do{
      *car = pop(prkLot);
      if(strncmp(car->entry.plate,plate,3) == 0){
         found = 1;
         break;
      }else{
         car->entry.mvts++;
         push(*car,&tempPrkLot);
      }
   }while(!empty(prkLot));
   
   while(!empty(&tempPrkLot))
      push(pop(&tempPrkLot),prkLot);
      
   if(!found)
      return CAR_NOT_FOUND;
   
   return UNPARKING_SUCCEEDED;
}

int isAValidVehiclePlate(char *plate){
   if(isdigit(plate[0]) &&
      isdigit(plate[1]) &&
      isdigit(plate[2]))
      return 1;
   return 0;
}

#define PARK 'E'
#define UNPARK 'S'

void showParkingLot(Stack *prkLot){
   int i;
   for(i = prkLot->size - 1;i >= 0;i--)
      printf("%.3s   movs: %2d\n",
             prkLot->nodes[i].entry.plate,
	     prkLot->nodes[i].entry.mvts);
   printf("\n");
}

int main(){
   Stack prkLot = createStack();
   Node car;
   
   int k;
   for(k = 0;k < 30;k++){
      char s[1024];s[0] = '\0';
      int aux;

      showParkingLot(&prkLot);
      gets(s);
      
      if(!isAValidVehiclePlate(s + 1) || strlen(s) > 4){
         printf("Wrong plate: '%.3s'.\n",s + 1);
         continue;
      }
      
      if(s[0] == PARK){
         aux = park(s + 1,&prkLot);
         printf("Car '%.3s' has arrived.\n",s + 1);
      }else if(s[0] == UNPARK){
         aux = unPark(s + 1,&car,&prkLot);
         printf("Waiting for car '%.3s'.\n",s + 1);
      }else{
         printf("Unkown action: '%c'.\n",s[0]);
         continue;
      }
      
      switch(aux){
         case FULL_PARKING_LOT:
            printf("The parking lot is full.\n");
            break;
         case PARKING_SUCCEEDED:
            printf("Parking succeeded.\n");
            break;
         case CAR_NOT_FOUND:
            printf("Sorry, car '%.3s' is not in the parking lot.\n",s + 1);
            break;
         case UNPARKING_SUCCEEDED:
            printf("Unparking succeeded.\n");
            printf("Car '%.3s' has been moved %d times.\n",car.entry.plate,car.entry.mvts);
            break;
      }
      printf("\n");
   }
   
   system("PAUSE");
   return 0;
}
