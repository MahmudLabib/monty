#include "monty.h"

/**
 * monty_run - Function that gets the line from the file
 * @file: File to parse its commands
 * Return: status
*/
int monty_run(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delimeter[] = " \n\t\a\b";
	size_t len = 0, mode = 1;
	unsigned int line_num = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &len, file) != -1)
	{
		line_num++;
		if (empty_line(line, delimeter))
			continue;
		token = tokening(line, delimeter);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "stack") == 0)
			mode = 1;
		else if (strcmp(token[0], "queue") == 0)
			mode = 0;
		else if (strcmp(token[0], "push") == 0 && mode == 0)
			exit_status = push_queue(&stack, token, line_num);
		else if (strcmp(token[0], "push") == 0 && mode == 1)
			exit_status = push_stack(&stack, token, line_num);
		else
			exit_status = execute(&stack, token, line_num);
		free(token);
		if (exit_status == EXIT_FAILURE)
			break;
	}
	free_stack(&stack);
	free(line);
	return (exit_status);
}

/**
 * tokening - Function that tokenize the monty bytecode line
 * @line: line to be tokenized
 * @delimeter: the delimeter between the words
 * Return: pointer to the tokens
*/
char **tokening(char *line, char *delimeter)
{
	char **token = NULL, *toks = NULL;
	size_t buffer_size = 0;
	int i = 0;

	if (!*line || line == NULL)
	{
		printf("In Tok fun 0");
		return (NULL);
	}
	buffer_size = strlen(line);
	if (buffer_size == 0)
	{
		printf("In Tok fun 1");
		return (NULL);
	}
	token = malloc(buffer_size * sizeof(char *));
	if (token == NULL)
	{
		free(line);
		free(token);
		exit(usage_err(0));
	}
	toks = strtok(line, delimeter);
	if (toks == NULL)
	{
		free(line);
		free(token);
		printf("In Tok fun 2");
		return (NULL);
	}
	while (toks != NULL)
	{
		token[i] = toks;
		i++;
		toks = strtok(NULL, delimeter);
	}
	token[i] = '\0';
	return (token);

}

/**
 * empty_line - check if line only contain delims
 * @line: pointer to string literal contain the line command
 * @delimeter: array of delims characters
 * Return: 1 if line only contains delims, otherwise 0
*/
int empty_line(char *line, char *delimeter)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delimeter[j]; j++)
		{
			if (line[i] == delimeter[j])
				break;
		}
		if (delimeter[j] == '\0')
			return (0);
	}
	return (1);
}
