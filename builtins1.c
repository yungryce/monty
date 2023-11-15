#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n;

	(void) counter;

	n = str_convert(&data, head);
	if (data.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}


/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	(void) counter;

	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		error_exit(&data, head);
	}
	printf("%d\n", (*head)->n);
}


#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		error_exit(&data, head);
	}
	h = *head;
	*head = h->next;
	free(h);
}


/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		error_exit(&data, head);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
