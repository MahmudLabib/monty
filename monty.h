#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/***********************************************************************/
/******************		Monty Data Structure		********************/
/***********************************************************************/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/****************************************************************************/
/***********************		Monty Utils			*************************/
/****************************************************************************/

/*	monty_main.c  */
int main(int argc, char **argv);

/*	monty_run.c  */
int monty_run(FILE *file);
char **tokening(char *line, char *delimeter);
int empty_line(char *line, char *delimeter);
/*	monty_execute.c  */
int push_stack(stack_t **stack, char **token, unsigned int lineNo);
int push_queue(stack_t **stack, char **token, unsigned int lineNo);
int execute(stack_t **stack, char **token, unsigned int lineNo);
/*	monty_utils1.c  */
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
/* void monty_swap(stack_t **stack, unsigned int line_number); */
/* void monty_add(stack_t **stack, unsigned int line_number); */

/*	monty_free.c  */
void free_stack(stack_t **stack);
/* monty_errors.c*/
int usage_err(int flag);
int open_err(char *fname);
int util_err(int flag, unsigned int lineNo);

#endif /* __MONTY_H__ */
