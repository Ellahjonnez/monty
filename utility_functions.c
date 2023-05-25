#include "monty.h"

/**
 * op_code - function used for running builtins
 * @stack: main stack pointer
 * @str: string to compare
 * @line_num: line numbers
 *
 * Return: nothing
 */

void op_code(stack_t **stack, char *str, unsigned int line_num)
{
	instruction_t op[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add_elements},
		{"nop", nop}, {"sub", sub_elements},
		{"div", div_elements}, {"mul", mul_elements},
		{"mod", mod_elements}, {"pchar", p_char},
		{"pstr", p_str}, {"rotl", rotl},
		{"rotr", rotr}, {"#", nop},
		{"", nop}, {"\n", nop},
		{NULL, NULL}
	};
	int i = 0;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}
	while (opcode[i].op_code)
	{
		if (strcmp(opcode[i].op_code, str) == 0)
		{
			opcode[i].f(stack, line_num);
			return; /* if there is a match, run the function */
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
	exit(EXIT_FAILURE);
}

/**
 * is_digit - checks if the string is a digital
 * @string: the string to check
 *
 * Return: 1 if success, 0 if not
 */

int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}

/**
 * is_number - checks if the string is a number
 * @str: the string to check
 *
 * Return: 1 if the string is a number, else, 0.
 */

int is_number(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}

