#include "monty.h"

/**
 * is_integer - Check if the user input is valid
 *
 * @str: The string from user input
 *
 * Return: 1 if valid, 0 on failure
 */

int is_integer(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str) /* Check user input */
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * create_node - Creates a new node for a stack
 *
 * @value: Value to be stored in new node
 *
 * Return: Pointer to the new node, NULL at memory alloc failure
 */
stack_t *create_node(int value)
{
	stack_t *node = malloc(sizeof(stack_t)); /* Allocate memory */

	if (!node)
		return (NULL);

	node->n = value;
	node->prev = NULL;
	node->next = NULL;

	return (node);
}

/**
 * add_node - Add a new node to stack
 *
 * @stack: Double linked list
 * @new_node: The new node to be added
 * @var: Pointer to the var struct
 */
void add_node(stack_t **stack, stack_t *new_node, vars_t *var)
{
	if (var->MODE == 0 || !*stack) /* Check if in LIFO Mode */
	{
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else /* Check if in FIFO mode */
	{
		stack_t *temp = *stack;

		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * start_vars - Initialize variables
 *
 * @var: Pointer to the cars_t struct
 *
 * Return: 0, succes. -1 on failure
 */
int start_vars(vars_t *var)
{
	var->stack = NULL;
	var->file = NULL;
	var->buff = NULL;
	var->line_number = 0;
	var->tmp = 0;
	return (0);
}

/**
 * free_all - Frees allocated memory
 * @var: Pointer to the var struct
 */
void free_all(vars_t *var)
{
	free_stack(var->stack);
	if (var->file)
		fclose(var->file);
	if (var->buff)
		free(var->buff);
}
