#include "monty.h"

/**
 * sub - sub
 * @stack: the top of th stack
 * @line_number: the number of the line to print
 *
 * Description: subtracts the top element
 * Return: none
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int len = 0, dif;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	dif = temp->next->n - temp->n;
	temp->next->n = dif;
	*stack = temp->next;
	free(temp);
}
