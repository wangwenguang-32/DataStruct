#include<stdint.h>
#include<stdlib.h>
#include"stack.h"
#include <stdbool.h>

stack_t* stack_create()
{
	stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
	stack->top = -1;
	return stack;
}

bool stack_push(stack_t* stack, int32_t data)
{
	if (stack->top + 1 == MAX_STACK)
		return false;

	stack->top++;
	stack->arr[stack->top] = data;
	return true;
}

bool stack_pop(stack_t* stack, int32_t* p_data)
{
	if (stack->top == -1)
		return false;

	*p_data = stack->arr[stack->top];
	stack->top--;
	return true;
}
