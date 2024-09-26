#include "monty.h"

/**
 * call_func - Calls the function based on opcode
 *
 * @var: Pointer to vers_t struct
 * @opcode: The opcode to execute
 *
 * Return: 0 on success, EXIT_FAILURE on err
 */
int call_func(vars_t *var, char *opcode)
{
	if (strcmp(opcode, "pall") == 0)
	{
		pall(&(var->stack), var->line_number);
		return (0);
	}
	else if (strcmp(opcode, "push") == 0)
	{
		push(&(var->stack), var->line_number, var);
		return (0);
	}
	return (EXIT_FAILURE);
}

/**
 * free_stack - Frees the stack_t stack
 * @stack: Pointer to the stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
