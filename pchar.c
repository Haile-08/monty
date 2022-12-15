#include "monty.h"

/**
 * pchar - pchar
 * @stack: the top of the stack
 * @line_number: the number of the line read
 *
 * Description: prints the char at the top of the stack
 * Retrun: none
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
