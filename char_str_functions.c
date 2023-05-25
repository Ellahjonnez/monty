#include "monty.h"

/**
 * p_char - prints the char at the top of the stack
 * @stack: the main stack
 * @line_num: number of lines
 *
 * Return: void
 */

void p_char(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * p_str - prints the string starting at the top of the stack,
 * @stack: stack head
 * @line_num: Number of lines
 *
 * Return: no return
*/

void p_str(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;

	(void)line_num;

	while (h)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		putchar((char) h->n);
		h = h->next;
	}
	putchar('\n');
}

/**
* rotl - to rotate the first element of the stack
* @stack: points to stack head
* @line_num: line number
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *left;
	stack_t *right;

	(void) line_num;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next) /* moves the right pointer to the last node */
		right = right->next;
	right->next = left;
	left->prev = right;
	*stack = left->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
* rotr - to rotate the last node of a stack
* @stack: points to the stack head
* @line_num: line number
*
* Return: void
*/

void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *last;
	stack_t *prev;

	(void) line_num;
	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;

	while (last->next)
		last = last->next;

	prev = last->prev;
	last->next = *stack;
	last->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = last;
	*stack = last;
}

/**
 * nop -  empty or nothing
 * @stack: dmain stack
 * @line_num : number of lines
 *
 * Return: Nothing
 */

void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
