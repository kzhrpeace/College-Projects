// include parts of the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
void double_stack_push(struct double_stack * this, double value) {
  this->top += 1;
  this->items  [this->top] = value;
  printf("this top is %d\n",this->top);
}

// pop a value from the stack
double double_stack_pop(struct double_stack * this){
  double variable;
  variable = this->items [this->top];
  printf("the  variable is %f\n", variable);
  this->top -= 1;
  printf("the pop is %f\n", variable);
  return variable;
}

int main(int argc, char ** argv) {
  int i;

  if ( argc == 1 ) {
    printf("Please try adding some command-line parameters\n");
    printf("Usage: %s <param1> <param2> ...\n", argv[0]);
    exit(1);
  }
 
  printf("The number of command line parameters is stored in argc: %d\n", argc);
  printf("The value of argc counts the name of the program itself as a parameter\n");
  printf("The name of the program is stored in argv[0]: %s\n", argv[0]);
  printf("The parameters are:\n");
  for ( i = 1; i < argc; i++ ) {
    printf("%s\n", argv[i]);
  }
    printf("\n");
  struct double_stack * this = double_stack_new(argc);
  double_stack_push(this, 7);
  double_stack_push(this, 4);
  double_stack_push(this, 2);

  printf("\n");
  printf("pop: %f\n ",double_stack_pop(this));
  printf("pop: %f\n ",double_stack_pop(this));
  printf("pop: %f\n ",double_stack_pop(this));
  return 0;
}
// end of code



