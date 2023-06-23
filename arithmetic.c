#include "monty.h"

/**
 * add_elem - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void add_elem(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	temp_ptr = head->n + head->next->n;
	head->next->n = temp_ptr;
	*stack = head->next;
	free(head);
}

/**
 * sub_elem - Subtracts the top element from the second element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void sub_elem(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_ptr;
	int sus, nodes;

	temp_ptr = *stack;
	for (nodes = 0; temp_ptr != NULL; nodes++)
		temp_ptr = temp_ptr->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp_ptr = *stack;
	sus = temp_ptr->next->n - temp_ptr->n;
	temp_ptr->next->n = sus;
	*stack = temp_ptr->next;
	free(temp_ptr);
}

/**
 * div_elem - Divides the top element by the second element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void div_elem(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp_ptr = head->next->n / head->n;
	head->next->n = temp_ptr;
	*stack = head->next;
	free(head);
}

/**
 * mul_elem - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void mul_elem(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	temp_ptr = head->next->n * head->n;
	head->next->n = temp_ptr;
	*stack = head->next;
	free(head);
}

/**
 * mod_elem - Computes the remainder of the division of the second top element
 *            of the stack by the top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void mod_elem(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(context.file);
		free(context.command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp_ptr = head->next->n % head->n;
	head->next->n = temp_ptr;
	*stack = head->next;
	free(head);
}

