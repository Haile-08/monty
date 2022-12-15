#include "monty.h"

/**
 * mul - mul
 * @stack: the top of the stack
 * @line_number: the number of the line
 *
 * Description: muliplite two of the numbers
 * Retrun: none
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int len = 0, res;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	res = temp->next->n * temp->n;
	temp->next->n = res;
	*stack = temp->next;
	free(temp);
}
