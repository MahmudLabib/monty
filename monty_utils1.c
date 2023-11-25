#include "monty.h"


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
/**
 * monty_pint - Funciton that prints the top val of the stack
 * @stack: struct stack hold the data, points to the top of stack
 * @line_number: Number of the line
 * Return: void
*/
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		util_err(5, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ptr->n);
}
/**
 * monty_pop - Funciton that removes the top element of the stack
 * @stack: struct stack hold the data, points to the top of stack
 * @line_number: Number of the line
 * Return: void
*/
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		util_err(6, line_number);
		exit(EXIT_FAILURE);
	}

	if (ptr->next)
		ptr->next->prev = ptr->prev;
	*stack = ptr->next;
	free(ptr);
}
/**
 * monty_swap - Funciton that swap top two elements of the stack
 * @stack: struct stack hold the data, points to the top of stack
 * @line_number: Number of the line
 * Return: void
*/
void monty_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack || (*stack)->next->n)
	{
		util_err(7, line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}
/* void monty_add(stack_t **stack, unsigned int line_number); */
