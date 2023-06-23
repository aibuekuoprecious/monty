#ifndef MONTY_H
#define MONTY_H

/* System header files */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct context_s - variables -args, file, line command
 * @arg: value
 * @file: pointer to monty file
 * @command: line command
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct context_s
{
	char *arg;
	FILE *file;
	char *command;
	int lifi;
} context_t;
extern context_t context;

/* execute.c */
int execute(char *command, stack_t **stack, unsigned int line_number, FILE *file);

/* arithmetic.c */
void add_elem(stack_t **stack, unsigned int line_number);
void sub_elem(stack_t **stack, unsigned int line_number);
void div_elem(stack_t **stack, unsigned int line_number);
void mul_elem(stack_t **stack, unsigned int line_number);
void mod_elem(stack_t **stack, unsigned int line_number);

/* print.c*/
void print_all(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);

/* stack.c */
void push_stack(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void pop_stack(stack_t **stack, unsigned int line_number);
void use_stack(stack_t **stack, unsigned int line_number);
void swap_elem(stack_t **stack, unsigned int line_number);

/* rotate_queue.c */
void rot_l(stack_t **stack, unsigned int line_number);
void rot_r(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void add_node(stack_t **stack, int n);
void add_queue(stack_t **stack, int n);
void use_queue(stack_t **stack, unsigned int line_number);

#endif

