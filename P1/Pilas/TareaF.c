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

char pop1(Stack *s){
   Node *n = pop(s);
   char c = n->entry.c;
   free(n);
   
   return c;
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
#define OPEN_DEL 127
#define CLOSE_DEL 128

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
   if(c == '[' || c == '{' ||
      c == '(')
      return OPEN_DEL;
   if(c == ']' || c == '}' ||
      c == ')')
      return CLOSE_DEL;
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

void moveOperands(Stack *s1,Stack *s2,int n){
   int p = 0;
   for(;n > 0;n--){
      p = 0;
      if(charType(top(s1)->entry.c) == CLOSE_DEL){
         p++;
         push(pop(s1),s2);
         while(p){
            if(charType(top(s1)->entry.c) == CLOSE_DEL)
               p++;
            if(charType(top(s1)->entry.c) == OPEN_DEL)
               p--;
            push(pop(s1),s2);
         }
      }else if(charType(top(s1)->entry.c) == OPEN_DEL){
         p++;
         push(pop(s1),s2);
         while(p){
            if(charType(top(s1)->entry.c) == OPEN_DEL)
               p++;
            if(charType(top(s1)->entry.c) == CLOSE_DEL)
               p--;
            push(pop(s1),s2);
         }
      }else if(charType(top(s1)->entry.c) == OPERAND)
         push(pop(s1),s2);
   }
}

int postfixToInfix(char *infixExpr,char *expr){
   int err;
   if(postfixExprChecker(expr,&err) != VALID_EXPR){
      return err;
   }
      
   Stack s1 = createStack();
   Stack s2 = createStack();
   
   int i = 0;
   while(expr[i] != '\0'){
      switch(charType(expr[i])){
         case OPERATOR:
            moveOperands(&s1,&s2,2);
            push(createNode('(',-1),&s1);
            moveOperands(&s2,&s1,1);
            push(createNode(expr[i],i),&s1);
            moveOperands(&s2,&s1,1);
            push(createNode(')',-1),&s1);
            break;
         case OPERAND:
            push(createNode(expr[i],i),&s1);
            break;
      }
      i++;
   }
   
   while(!empty(&s1))
      push(pop(&s1),&s2);
      
   i = 0;
   while(!empty(&s2))
      infixExpr[i++] = pop1(&s2);
      
   infixExpr[i] = '\0';
   
   return err;
}

int main(){
   for(;;){
      char s[1024];s[0] = '\0';
      char r[1024];r[0] = '\0';
         
      gets(s);if(strlen(s) == 0)break;
      printf("----Postfix\n%s\n",s);
      
      int i,err = postfixToInfix(r,s);
      if(err != -1){
         for(i = 0;i < err;i++)
               printf(" ");
            printf("^\n");
            printf("Error '%c' at %d.\n",s[err],err);
      }else
         printf("----Infix '%s'.\n",r);
   }
   
   system("PAUSE");
   return 0;
}
