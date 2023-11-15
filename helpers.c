#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t **head)
{
	stack_t *aux;

	while (*head)
	{
		aux = (*head)->next;
		free(*head);
		*head = aux;
	}
}


/**
 * error_exit - cleans up, closese stream and exits
 * @data: data of program
 * @stack: pointer to DLL
*/

void error_exit(data_t *data, stack_t **stack)
{
	fclose(data->stream);
	free(data->line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * str_convert - converts string to int
 * @data: data of program
 * @stack: head to DLL
 * Return: integer
*/
int str_convert(data_t *data, stack_t **stack)
{
	int flag = 0;
	char *temp;

	if (data->arg)
	{
		temp = data->arg;
		if (*temp == '-')
			temp++;

		while (*temp)
		{
			if (*temp < '0' || *temp > '9')
				flag = 1;
			temp++;
		}
		if (flag)
		{
			fprintf(stderr, "L%d: usage: push integer\n", data->count);
			error_exit(data, stack);
		}
		return (atoi(data->arg));
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", data->count);
		error_exit(data, stack);
	}
	return (0);
}
