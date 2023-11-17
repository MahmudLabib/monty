#include "monty_header.h"

/**
 * main - Monty Interpreter program
 * @argc: Number of args passed to program
 * @argv: Arguments names passed to program
 * Return: [0] on success
*/
int main(int argc, char **argv)
{
	FILE *fptr = NULL;
	int exit_status = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_err(1));

	fptr = fopen(argv[1], "r");
	if (!fptr)
		return (open_err(argv[1]));
	exit_status = monty_run(fptr);
	fclose(fptr);
	return (exit_status);
		open_err(argv[1]);
	monty_run(fptr);
	exit(exit_status);
	return (0);
}
