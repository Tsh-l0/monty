#include "monty.h"

/**
 * push - Inserts a new value to the stack or queue
 *
 * @stack: Double linked list
 * @line_number: File line execution
 * @var: Pointer to the vars_t structure
 */
void push(stack_t **stack, unsigned int line_number, vars_t *var)
{
	stack_t *new_node = NULL;
	char *coin;

	/* Get user input. This is the int to push */
	coin = strtok(NULL, " \r\t\n");
	if (coin == NULL || !is_integer(coin)) /*NULL Check */
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all(var);
		exit(EXIT_FAILURE);
	}

	/* printf("Pushing value: %s\n", coin); */

	/* Create a new node */
	new_node = create_node(atoi(coin));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(var);
		exit(EXIT_FAILURE);
	}

	/* Add the new node into the stack */
	add_node(stack, new_node, var);
}

/**
 * pall - Prints the values on the stack starting from the top
 *
 * @stack: Double linked list representing the stack
 * @line_number: Current line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (!tmp)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
