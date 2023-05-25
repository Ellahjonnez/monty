#include "monty.h"

/**
 * push - adds an element to the top of the stack
 * @stack: the stack
 * @line_num: The number of line
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_num)
{
	char *c = global.arg_line;

	if ((is_digit(c)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (global.line_num == 1)
	{
		if (!add_stack_node(stack, atoi(global.arg_line)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_stack_node(stack, atoi(global.arg_line)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - display all the elements in the stack from top to bottom
 * @head: stack head
 * @line_num: Number of lines
 * Return: no return
*/

void pall(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint -  prints the value of the element at the top of the stack
 * @stack: stack given by main in start.c
 * @line_num: the line number
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - removes and returns the element at the top of the stack
* @stack: the main stack
* @line_num: number of lines
*
* Return: void
*/

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}

/**
 * swap -   exchanges the positions of the two elements at the top of the stack
 * @stack: the stack
 * @line_num: number of lines
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int temp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp_n = temp->n;
	temp->n = temp_n;

	temp->n = temp->next->n;
	temp->next->n = temp_n;
}
