// include parts of the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
 
// type declaration for stack of doubles
struct double_stack {
 double * items;
 int max_size;
 int top;
};
 
// prototypes of functions that operate on the double stack
 
// create a new empty stack
struct double_stack * double_stack_new(int max_size) {
 struct double_stack * result;
 
 // allocate space for the stack header
 result = malloc(sizeof(struct double_stack));
 result->max_size = max_size;
 result->top = 0;
 // allocate space for the data stored in the stack
 result->items = malloc(sizeof(double)*max_size);
 // return a pointer to the newly-allocated stack
 return result;
}
 
// push a value onto the stack
void double_stack_push(struct double_stack * this, double value){
 this->items += 1;
 *(this->items) = value;
 this->top = value;
 printf("this top is %d\n",this->top);
}
 
// pop a value from the stack
double double_stack_pop(struct double_stack * this){
 double variable;
 variable = *(this->items);
 this->items -= 1;
 printf("the pop is %f\n", variable);
 return variable;
}

void apply_operator(struct double_stack * this, char expr) {
   char c = expr;
   double second = double_stack_pop(this);
   double first = double_stack_pop(this);
   double result;
   switch(c) {
      case '+':
      result = first + second;
      case '-':
      result = first - second;
      case 'X':
      result = first * second;
      case '/':
      result = first / second;
      case '^':
      result = pow(first, second);
      break;
      default:
      break;
   }
   double_stack_push(this, result);
}
 
double evaluate_postfix_expression(char**args, int nargs) {
 struct double_stack * stack = double_stack_new(nargs);
 double result;
    for(int i=0; i<nargs; i++) {
        if(strlen(args[i])==1) {
            switch(args[i][0]) {
                case '+':
                case '-':
                case 'X':
                case '/':
                case '^':
                apply_operator(stack, args[i][0]);
                break;
                    
                default:
                double_stack_push(stack,atof(args[i]));
                break;
            }
        }
        else {
            double_stack_push(stack,atof(args[i]));
        }
    }
    result = double_stack_pop(stack);
    return result;
}
 
 
// main function for a simple bench calculator with command
// line inputs
int main(int argc, char ** argv) {
 if ( argc == 1 ) {
   // command line contains only the name of the program
   printf("Error: No command line parameters provided\n");
   printf("Usage: %s postfix|infix <expression>\n", argv[0]);
   exit(1);
 }
 else if ( argc == 2 ) {
   // command line contains name of prog and one other parameter
   printf("Error: No expression to evaluate provided\n");
   printf("Usage: %s postfix|infix <expression>\n", argv[0]);
   exit(1);
 }
 else {
   // command line has enough parameters for an expression
   double result;
   if ( strcmp(argv[1], "postfix") == 0 ) {
     // pass the command line parameters, but with the first two removed
     result = evaluate_postfix_expression(argv+2, argc-2);
     printf("Result is %lf\n", result);
   }
   else if ( strcmp(argv[1], "infix") == 0 ) {
     // pass the command line parameters, but with the first two removed
     result = evaluate_infix_expression(argv+2, argc-2);
     printf("Result is %lf\n", result);
   }
   else {
     printf("Error: You must specify whether the expression is infix or postfix\n");
     printf("Usage: %s postfix|infix <expression>\n", argv[0]);
     exit(1);
   }
 
 return 0;
 }
}
