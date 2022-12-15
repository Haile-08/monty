#include "monty.h"

/**
 * mod - mode
 * @stack: the top of the stack
 * @line_number: the number of the line
 *
 * Description: computes the modulo of two num
 * Return: none
 */
void mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	res = temp->next->n % temp->n;
	temp->next->n = res;
	*stack = temp->next;
	free(temp);
}
