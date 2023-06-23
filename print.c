#include "monty.h"

/**
 * print_all - Prints all elements in the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction (unused).
 *
 * Return: No return value.
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

	head = *stack;
	if (head == NULL)
		return;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * print_int - Prints the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 *
 * Return: No return value.
 */
void print_int(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * print_char - Prints the character at the top of the stack,
 *              followed by a new line.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 *
 * Return: No return value.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", head->n);
}

/**
 * print_str - Prints the string starting at the top of the stack,
 *             followed by a new line.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction.
 *
 * Return: No return value.
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	(void)line_number;

	head = *stack;
	while (head)
	{
		if (head->n > 127 || head->n <= 0)
		{
			break;
		}

		printf("%c", head->n);
		head = head->next;
	}

	printf("\n");
}

/**
 * do_nothing - Does nothing.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the instruction (unused).
 *
 * Return: No return value.
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}

