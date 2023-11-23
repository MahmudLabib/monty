#include "monty.h"

/**
 * push_stack - Push elements to the stack
 * @stack: stack contain the data
 * @token: command
 * @lineNo: no. of the line
 * Return: [EXIT_SUCCESS] on success, [EXIT_FAILURE] on failure
 *
*/
int push_stack(stack_t **stack, char **token, unsigned int lineNo)
{
	stack_t *newNode;
	int i;

	if ((token[1]) == NULL)
	{
		return (util_err(0, lineNo));
	}


	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (util_err(0, lineNo));
		}
		i++;
	}

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
		return (usage_err(0));

	newNode->n = atoi(token[1]);

	if ((*stack) != NULL)
		(*stack)->prev = newNode;

	newNode->next = *stack;
	newNode->prev = NULL;
	*stack = newNode;

	return (EXIT_SUCCESS);
}

/**
 * execute - check which fun to be executed
 * @stack: stack holds data (int) values
 * @token: pointer to string that hold the command
 * @lineNo: Line no.
 * Return: [EXIT_SUCCESS] on success, [EXIT_FAILURE] on fail.
*/
int execute(stack_t **stack, char **token, unsigned int lineNo)
{
	unsigned int i = 0;
	/*
	 *	instruction_t op[] = {
	 *	{"pall", monty_pall},
	 *	{"pint", monty_pint},
	 *	{"pop", monty_pop},
	 *	{"swap", monty_swap},
	 *	{"add", monty_add},
	 *	{"null", NULL}
	};
	for (; i < 6; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, lineNo);
			return (EXIT_SUCCESS);
		}
	}
	*/

	instruction_t op[] = {
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"null", NULL}
	};
	for (; i < 2; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, lineNo);
			return (EXIT_SUCCESS);
		}
	}



	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", lineNo, token[0]);
	return (EXIT_FAILURE);
}


/**
 * push_queue - pla pla
 * @stack: pla
 * @token: pla
 * @lineNo: pla
 * Return: pla pal pla
*/
int push_queue(stack_t **stack, char **token, unsigned int lineNo)
{
	(void)stack;
	(void)token;
	(void)lineNo;
	return (EXIT_SUCCESS);
}
