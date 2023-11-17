#include "monty_header.h"


/**
 * monty_pall - Funciton that prints in FILO order,
 * the values of stack.
 * @stack: struct stack hold the data, points to the top of stack
 * @line_number: Number of the line
 * Return: void
*/
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *sptr = *stack;
	(void)line_number;

	while (sptr)
	{
		printf("%d\n", sptr->n);
		sptr = sptr->next;
	}

}
/* void monty_pint(stack_t **stack, unsigned int line_number); */
/* void monty_pop(stack_t **stack, unsigned int line_number); */
/* void monty_swap(stack_t **stack, unsigned int line_number); */
/* void monty_add(stack_t **stack, unsigned int line_number); */
