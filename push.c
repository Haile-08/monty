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
	if (isNumber(strtok(var.num, "$\n\t")))
	{
		(void)line_number;
		newnode(stack, atoi(strtok(var.num, "$\n\t")));
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

}
