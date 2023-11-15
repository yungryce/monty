#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct data_s - variables -args, file, line content
 * @arg: value
 * @stream: pointer to monty file
 * @line: line content
 * @ret: flag change stack <-> queue
 * @count: line number
 * Description: carries values through the program
 */
typedef struct data_s
{
	char *arg;
	FILE *stream;
	char *line;
	int ret;
	int count;
}  data_t;
extern data_t data;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char **argv);
int parser(data_t *data, stack_t **stack);
void (*get_builtin(char *op))(stack_t **stack, unsigned int counter);

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);

void f_push(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter);
void f_pint(stack_t **head, unsigned int counter);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
void f_queue(stack_t **head, unsigned int counter);

void error_exit(data_t *data, stack_t **stack);
void free_stack(stack_t **head);
size_t print_list(const stack_t *h);
int str_convert(data_t *data, stack_t **stack);

#endif
