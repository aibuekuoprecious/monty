#include "monty.h"

/**
 * push_stack - add node to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void push_stack(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (context.arg)
	{
		/* Check if argument starts with a minus sign */
		if (context.arg[0] == '-')
			j++;
		/* Check if argument is a valid integer */
		for (; context.arg[j] != '\0'; j++)
		{
			if (context.arg[j] > 57 || context.arg[j] < 48)
				flag = 1;
		}
		/* Print error message and exit if argument is invalid */
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(context.file);
			free(context.command);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Print error message and exit if argument is missing */
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* Convert argument to integer */
	n = atoi(context.arg);
	/* Add node to the stack or queue based on context */
	if (context.lifi == 0)
		add_node(stack, n);
	else
		add_queue(stack, n);
}

/**
 * free_stack - frees a doubly linked list
 * @stack: stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp_ptr;

	temp_ptr = stack;
	while (stack)
	{
		temp_ptr = stack->next;
		free(stack);
		stack = temp_ptr;
	}
}

/**
 * pop_stack - removes the top element from the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	*stack = head->next;
	free(head);
}

/**
 * use_stack - sets the stack mode to LIFO (Last-In-First-Out)
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void use_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	context.lifi = 0;
}

/**
 * swap_elem - adds the top two elements of the stack.
 * @stack: stack stack
 * @line_number: line_number
 * Return: no return
 */
void swap_elem(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int len = 0, temp_ptr;

	head = *stack;
	while (head)
	{
		head = head->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	temp_ptr = head->n;
	head->n = head->next->n;
	head->next->n = temp_ptr;
}

