#include "monty.h"

/**
 * usage_err - Error function prints usage error message
 * @flag: error type '0' for [malloc] err, '1' for [USAGE] err
 * Return: '0' for [malloc] err, '1' for [USAGE] err
*/
int usage_err(int flag)
{
	char *errno[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errno[flag]);
	return (EXIT_FAILURE);
}
/**
 * open_err - Error function prints open error message
 * @fname: File name
 * Return: no return, exit() with EXIT_FAILURE flag
*/
int open_err(char *fname)
{
	fprintf(stderr, "Error: Can't open file %s\n", fname);
	return (EXIT_FAILURE);
}
/**
 * util_err - funciton prints errors
 * @flag: index of the error message to choose
 * @lineNo: line number that have error
 * Return: EXIT_FAILURE
*/
int util_err(int flag, unsigned int lineNo)
{
	char *err[] = {"usage: push integer", "can\'t pint, stack empty",
		"can\'t pop an empty stack", "can't swap, stack too short",
		"can\'t add, stack too short", "can't pint, stack empty"};
	fprintf(stderr, "L%d: %s\n", lineNo, err[flag]);
	return (EXIT_FAILURE);
}

