#ifndef STACK_H
#define STACK_H

#include<stdint.h>
#include<stdbool.h>

#define MAX_STACK 100

typedef struct
{
	int32_t top;
	int32_t arr[MAX_STACK];

}stack_t;

stack_t* stack_create();
bool stack_push(stack_t* stack, int32_t data);
bool stack_pop(stack_t* stack, int32_t* p_data);

#endif 

