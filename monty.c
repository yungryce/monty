#include "monty.h"
data_t data = {0};

/**
 * main - Monty Interpreter
 * @argc: command line argument count
 * @argv: monty file
 *
 * Return: Exit status
*/

int main(int argc, char **argv)
{
	ssize_t nread;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data.stream = fopen(argv[1], "r");
	if (!data.stream)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&(data.line), &len, data.stream)) != -1)
	{
		data.count++;
		parser(&data, &stack);
	}

	free(data.line);
	free_stack(&stack);
	fclose(data.stream);
	return (EXIT_SUCCESS);
}

/**
 * parser - handles and parses commands
 * @data: global data of program
 * @stack: pointer to DLL
 * Return: Exit status
*/
int parser(data_t *data, stack_t **stack)
{
	void (*builtin)(stack_t **stack, unsigned int counter);
	char *op = strtok(data->line, " \n\t");

	if (!op || op[0] == '#')
		return (0);

	builtin = get_builtin(op);

	data->arg = strtok(NULL, " \n\t");

	if (builtin)
		(builtin(stack, data->count));
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", data->count, op);
		error_exit(data, stack);
	}
	return (0);
}

/**
 * get_builtin - executes the opcode
 * @op: poiner to arg[0]
 * Return: no return
 */

void (*get_builtin(char *op))(stack_t **stack, unsigned int counter)
{
	instruction_t funcs[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{NULL, NULL}
	};

	int i;

	for (i = 0; funcs[i].opcode; i++)
	{
		if (strcmp(funcs[i].opcode, op) == 0)
			return (funcs[i].f);
	}

	return (NULL);
}

