#include "monty.h"

/**
 * pint - print the top value
 * @stack: the top of the stack
 * @line_number: the number of the line read
 *
 * Description: print the top of the stack
 * Return: none
 */

void pint(stack_t **stack, unsigned int line_number)
{
	printf("%d\n", (*stack)->n);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
