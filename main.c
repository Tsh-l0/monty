#define _GNU_SOURCE
#include "monty.h"

/**
 * main - Start MONTY Interpreter Program
 *
 * @argc: argument count
 * @argv: Argument values
 *
 * Return: 0, Success. 1 on failure
 */
int main(int argc, char *argv[])
{
	char *opcode;
	vars_t var;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(argv[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all(&var);
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.tmp, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_func(&var, opcode) == EXIT_FAILURE)
			{
				free_all(&var);
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}
	free_all(&var);

	return (EXIT_SUCCESS);
}
