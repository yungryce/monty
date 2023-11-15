#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
		aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}


/**
 * print_list - Prints data of DLL
 * @h: Head of DLL
 *
 * Return: Node count
 */

size_t print_list(const stack_t *h)
{
	const stack_t *head = h;
	size_t count = 0;

	if (!head)
		return (count);

	while (head->prev)
		head = head->prev;

	while (head)
	{
		printf("%d\n", head->n);

		head = head->next;
		count++;
	}

	return (count);
}
