#include <stdio.h>

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

int pop2(Stack *s){
   Node *n = pop(s);
   int pos = n->entry.pos;
   free(n);
   
   return pos;
}

#define OPERATOR 123
#define OPERAND 124
#define SPACE 125
#define INVALID_OP 126

#define VALID_EXPR 1000
#define MISSING_OP_ARGS 1001
#define OPERAND_NOT_UNDER_OP 1002
#define UNKNOWN_CHAR 1003

int charType(char c){
   if(c == '-' || c == '+' ||
      c == '/' || c == '*' || c == '^')
      return OPERATOR;
   else if('a' <= c && c <= 'z' ||
           'A' <= c && c <= 'Z' ||
           '0' <= c && c <= '9')
      return OPERAND;
   else if(c == ' ')
      return SPACE;
   else
      return INVALID_OP;
}

int postfixExprChecker(char *expr,int *err_index){
   Stack s = createStack();
   
   int i = 0;
   while(expr[i] != '\0'){
      switch(charType(expr[i])){
         case OPERATOR:
            if(!empty(&s))
               pop2(&s);
            else{
               *err_index = i;
               return MISSING_OP_ARGS;
            }
            if(!empty(&s))
               push(createNode('_',pop2(&s)),&s);
            else{
               *err_index = i;
               return MISSING_OP_ARGS;
            }
            break;
         case OPERAND:
            push(createNode(expr[i],i),&s);
            break;
         case INVALID_OP:
            *err_index = i;
            return UNKNOWN_CHAR;
            break;
      }
      i++;
   }
   if(i != 0)
      pop2(&s);
   
   if(!empty(&s)){
      *err_index = top(&s)->entry.pos;
      while(!empty(&s))
         pop2(&s);
      return OPERAND_NOT_UNDER_OP;
   }
   
   *err_index = -1;
   return VALID_EXPR;
}

int main(){
   int k;
   for(k = 0;k < 10;k++){
      char s[1024];s[0] = '\0';
      int err_index,i;
   
      gets(s);if(strlen(s) == 0)break;
      puts(s);
      
      switch(postfixExprChecker(s,&err_index)){
         case VALID_EXPR:
            printf("Is a valid expression.\n");
            break;
         case MISSING_OP_ARGS:
            for(i = 0;i < err_index;i++)
               printf(" ");
            printf("^\n");
            printf("Missing arguments for '%c' at %d.\n",s[err_index],err_index);
            break;
         case OPERAND_NOT_UNDER_OP:
            for(i = 0;i < err_index;i++)
               printf(" ");
            printf("^\n");
            printf("Operand starting at '%c' in position %d must be under an operator.\n",s[err_index],err_index);
            break;
         case UNKNOWN_CHAR:
            for(i = 0;i < err_index;i++)
               printf(" ");
            printf("^\n");
            printf("Unkown character '%c' at %d.\n",s[err_index],err_index);
            break;
      }
   }
   
   system("PAUSE");
   return 0;
}
