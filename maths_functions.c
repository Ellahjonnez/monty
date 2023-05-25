#include "monty.h"
/**
 * add - adds the first two elements of the stack.
 * @stack: stack head
 * @num_sum: line_number
 * Return: no return
*/
void add_elements(stack_t **stack, unsigned int num_sum)
{
	int sum;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", add_num);
		free_stacks(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	sum = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, add_num); 
	(*stack)->n = sum;
}

/**
 * div_elements - divides the next top element by the top element
 * @stack: main stack
 * @div_num: number of lines
 *
 * Return: void
 */

void div_elements(stack_t **stack, unsigned int div_num)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", div_num);
		free_stacks(*stack, global.file);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", div_num);
		free_stacks(*stack, global.file);
		exit(EXIT_FAILURE);

		return;
	}

	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, div_num);
	(*stack)->n = result;
}

/**
 * sub_elements -  substracts the first two top elements of the stack
 * @stack: main stack
 * @sub_num: number of lines
 *
 * Return: void
 */

void sub_elements(stack_t **stack, unsigned int sub_num)
{
	int sub_res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", sub_res);
		free_stacks(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	sub_res = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, sub_num);
	(*stack)->n = sub_res;
}

/**
 * mul_elements - multiplies the second top value of the stack with the top value
 * @stack: main stack
 * @mul_num: line number
 * 
 * Return: void
 */

void mul_elements(stack_t **stack, unsigned int mul_num)
{
	int mul_res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", mul_num);
		free_stacks(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	mul_res = (*stack)->n * (*stack)->next->n;
	_pop(stack, mul_num);
	(*stack)->n = mul_res;
}

/**
 * mod - calculates the remainder of the division
 * @stack: main stack
 * @mod_num: number of lines
 *
 * Return: void
 */

void mod_elements(stack_t **stack, unsigned int mod_num)
{
	int mod_res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", mod_num);
		free_stacks(*stack, global.file);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", mod_num);
		free_stacks(*stack, global.file);
		exit(EXIT_FAILURE);
		return;
	}

	mod_res = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, mod_num);
	(*stack)->n = mod_res;
}

