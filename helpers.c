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
	char *temp = data->arg;

	if (temp)
	{
		if (*temp == '-')
			temp++;

		while (*temp)
		{
			if (*temp < '0' || *temp > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n", data->count);
				error_exit(data, stack);
			}
			temp++;
		}
		return (atoi(data->arg));
	}
	else
	{
		fprintf(stderr, "vimL%d: usage: push integer\n", data->count);
		error_exit(data, stack);
	}
	return (0);
}
