#include "monty.h"

/**
 * rot_l - Rotates the stack to the top.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void rot_l(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack, *temp_ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	temp_ptr = (*stack)->next;
	temp_ptr->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = temp_ptr;
}

/**
 * rot_r - Rotates the stack to the bottom.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void rot_r(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}

/**
 * add_node - Adds a new node to the stack.
 * @stack: Pointer to the stack.
 * @n: Value of the new node.
 *
 * Return: No return value.
 */
void add_node(stack_t **stack, int n)
{
	stack_t *new_node, *temp_ptr;

	temp_ptr = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp_ptr)
		temp_ptr->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
 * use_queue - Sets the stack mode to FIFO (First-In-First-Out).
 * @stack: Pointer to the stack.
 * @line_number: Line number.
 *
 * Return: No return value.
 */
void use_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	context.lifi = 1;
}

/**
 * add_queue - Adds a new node to the tail of the stack.
 * @stack: Pointer to the stack.
 * @n: Value of the new node.
 *
 * Return: No return value.
 */
void add_queue(stack_t **stack, int n)
{
	stack_t *new_node, *temp_ptr;

	temp_ptr = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp_ptr)
	{
		while (temp_ptr->next)
			temp_ptr = temp_ptr->next;
	}
	if (!temp_ptr)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp_ptr->next = new_node;
		new_node->prev = temp_ptr;
	}
}

