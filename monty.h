#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * (or queue)
 *
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues,
 * LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 *
 * @opcode: the opcode
 * @f: Function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_type - global variables to be used
 *
 * @file: Pointer to the read file
 * @buff: Buffer to store lines from the file
 * @tmp: Temporary variable for
 * getline
 * @line_number: Current line
 * @MODE: Mode of operation (LIFO / FIFO)
 * @stack: Pointer to the stack
 *
 * Description: Holds global variables for interpreter
 */
typedef struct var_type
{
	FILE *file;
	char *buff;
	size_t tmp;
	unsigned int line_number;
	int MODE;
	stack_t *stack;
} vars_t;

/* Push function prototypes */
void push(stack_t **stack, unsigned int line_number, vars_t *var);
int is_integer(char *str);
stack_t *create_node(int value);
void add_node(stack_t **stack, stack_t *new_node, vars_t *var);
void free_all(vars_t *var);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int start_vars(vars_t *var);
int call_func(vars_t *var, char *opcode);

#endif /* MONTY_H */
