#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
   char c;
   int pos;
}StackEntry;

#include "DynamicStack.h"

Node* createNode(char c,int pos){
   StackEntry e;
      e.c = c;
      e.pos = pos;
   Node *n = (Node*)malloc(sizeof(Node));
      n->entry = e;
      n->next = NULL;
   return n;
}

char pop2(Stack *s){
   Node *n = pop(s);
   char c = n->entry.c;
   free(n);
   
   return c;
}

#define OPEN_DEL 123
#define CLOSE_DEL 124
#define NON_DEL 125

#define VALID_EXPR 1000
#define MISSING_OPEN_DEL 1001
#define MISSING_CLOSE_DEL 1002

int delimiterType(char d){
   if(d == '[' || d == '{' || d == '(')
      return OPEN_DEL;
   else if(d == ']' || d == '}' || d == ')')
      return CLOSE_DEL;
   else
      return NON_DEL;
}

int matches(char open,char close){
   if(open - close == '[' - ']' ||
      open - close == '{' - '}' ||
      open - close == '(' - ')')
      return 1;
   return 0;
}

int delimiterChecker(char *expr,int *err_index){
   Stack s = createStack();
   
   int i = 0;
   while(expr[i] != '\0'){
      switch(delimiterType(expr[i])){
         case OPEN_DEL:
            push(createNode(expr[i],i),&s);
            break;
         case CLOSE_DEL:
            if(!empty(&s) && matches(top(&s)->entry.c,expr[i]))
               pop2(&s);
            else{
               *err_index = i;
               return MISSING_OPEN_DEL;
            }
            break;
      }
      i++;
   }
   
   if(!empty(&s)){
      *err_index = top(&s)->entry.pos;
      while(!empty(&s))
         pop2(&s);
      return MISSING_CLOSE_DEL;
   }
   
   *err_index = -1;
   return VALID_EXPR;
}

int main(){
   Stack s1 = createStack();
   
   char s[1024];s[0] = '\0';
   for(;;){
      int err_index,i;
   
      gets(s);if(strlen(s) == 0)break;
      puts(s);
      
      switch(delimiterChecker(s,&err_index)){
         case VALID_EXPR:
            printf("Is a valid expression.\n");
            break;
         case MISSING_OPEN_DEL:
            for(i = 0;i < err_index;i++)
               printf(" ");
            printf("^\n");
            printf("Missing open delimiter for '%c' at %d.\n",s[err_index],err_index);
            break;
         case MISSING_CLOSE_DEL:
            for(i = 0;i < err_index;i++)
               printf(" ");
            printf("^\n");
            printf("Missing close delimiter for '%c' at %d.\n",s[err_index],err_index);
            break;
      }
   }
   
   system("PAUSE");
   return 0;
}
