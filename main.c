#include "monty.h"

/* Global variable declaration */
void file_error(char *argv);
void error_usg(void);
int status = 0;

/**
 * main - the entry point
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: nothing
 */

int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *string = NULL;
	stack_t *stack = NULL;
	unsigned int line_num = 1;
	ssize_t line_len;

	global.data_struct = 1;
	if (argc != 2)
		error_usg();

	global.file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while ((line_len = getline(&buffer, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_num++;
			continue;
		}
		string = strtok(buffer, " \t\n");
		if (!string || *string == '#')
		{
			line_num++;
			continue;
		}
		global.arg_line = strtok(NULL, " \t\n");
		op_code(&stack, string, line_num);
		line_num++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - prints the error message and exits
 * @argv: the arguments given by main()
 *
 * Desc: To print a msg when file is not possible to open
 * Return: nothing
 */

void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * error_usg - prints error usage message and exits
 *
 * Desc: to print error usage msg if user does not give
 * any file or more than one argument to the program
 *
 * Return: nothing
 */

void error_usg(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
