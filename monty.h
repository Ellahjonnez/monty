#ifndef _MONTY_H_
#define _MONTY_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global_args - The current opcode argument
* @data_struct: stack mode, stack (default) and queue
* @argstring: the string arguments
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct global_args
{
	int line_num;
	int data_struct;
	FILE *file;
	char *arg_line;
	stack_t *stack;
} global_t;

global_t global;

/* Declearing the stack utility functions in doubly linked list */
stack_t *add_stack_node(stack_t **stack, const int n);
stack_t *queue_stack_node(stack_t **stack, const int n);
void free_all_stack(stack_t *stack, FILE *file);
void free_stack(stack_t *stack);
size_t print_stack_node(const stack_t *stack);

void push(stack_t **stack, unsigned int line_num);
void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);

void div_elements(stack_t **stack, unsigned int div_num);
void add_elements(stack_t **stack, unsigned int add_num);
void sub_elements(stack_t **stack, unsigned int sub_num);
void mul_elements(stack_t **stack, unsigned int mul_num);
void mod_elements(stack_t **stack, unsigned int mod_num);

void p_char(stack_t **stack, unsigned int line_num);
void p_str(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);

void op_code(stack_t **stack, char *str, unsigned int line_num);

int is_digit(char *string);
int is_number(char *str);

#endif /* end of_MONTY_H_ */
