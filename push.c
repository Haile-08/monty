#include "monty.h"

/**
 * push_int - push int
 * @stack: the stack pointer
 * @lint_number: the line number
 *
 * Description: push the integer
 * Return: none
 */

void push_int(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (var_v.num)
	{
		ptr = malloc(sizeof(stack_t));
		if (ptr == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		ptr->n = atoi(var_v.num);
		if (*stack == NULL)
		{
			ptr->next = NULL;
			ptr->prev = NULL;
			*stack = ptr;
		}
		else
		{
			ptr->prev = NULL;
			ptr->next = *stack;
			*stack = ptr;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
