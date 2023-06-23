#include "monty.h"
/**
* execute - executes the opcode
* @stack: stack linked list - stack
* @line_number: line_counter
* @file: pointer to monty file
* @command: line command
* Return: no return
*/
int execute(char *command, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_stack},
				{"pall", print_all},
				{"pint", print_int},
				{"pop", pop_stack},
				{"swap", swap_elem},
				{"add", add_elem},
				{"nop", do_nothing},
				{"sub", sub_elem},
				{"div", div_elem},
				{"mul", mul_elem},
				{"mod", mod_elem},
				{"pchar", print_char},
				{"pstr", print_str},
				{"rotl", rot_l},
				{"rotr", rot_r},
				{"queue", use_queue},
				{"stack", use_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(command, " \n\t");
	if (op && op[0] == '#')
		return (0);
	context.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(command);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

