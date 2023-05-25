#include "monty.h"

/**
 * free_all_stack - frees all stacks and files
 * @stack: points to the stack
 * @file: points to the file
 *
 * Return: void
 */

void free_all_stack(stack_t *stack, FILE *file)
{
	free_stack(stack);
	fclose(file);
}

/**
 * free_stack - to free the stack
 * @stack: points to the stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *present = stack;

	while (present != NULL)
	{
		present = present->next;
		free(stack);
		stack = present;
	}
}

/**
 * queue_stack_node - adds a node to a stack in queue_node
 * @stack: points to the stack
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */

stack_t *queue_stack_node(stack_t **stack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*stack)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
			break;
		}
		current = current->next;
	}

	return (new);
}

/**
 * add_stack_node - adds a node to the start
 * @stack: points to the stack head
 * @n: number for the new node
 *
 * Return: the reated node, if creation fails, return NULL.
 */

stack_t *add_stack_node(stack_t **stack, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;

	*stack = new;

	return (new);
}

/**
 * print_stack_node - prints the contents of the stack
 * @stack: points to the stack
 *
 * Return: number of elements
 */

size_t print_stack_node(const stack_t *stack)
{
	size_t j = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		j++;
	}

	return (j);
}
