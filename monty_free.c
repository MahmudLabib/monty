#include "monty.h"

/**
 * free_stack - Function that frees the stack structure
 * @stack: structure to be freed
 * Return: void
*/
void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;

	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}
