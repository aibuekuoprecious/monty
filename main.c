#include "monty.h"
context_t context = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *command;
	FILE *file;
	size_t buf_size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	context.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		command = NULL;
		read_line = getline(&command, &buf_size, file);
		context.command = command;
		line_number++;
		if (read_line > 0)
		{
			execute(command, &stack, line_number, file);
		}
		free(command);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

