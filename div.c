#include "monty.h"

/**
 * div_num - div
 * @stack: the top of the stack
 * @line_number: the number of the line
 *
 * Description: divid the two elements of the stack
 * Return: none
 */
void div_num(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	res = temp->next->n / temp->n;
	temp->next->n = res;
	*stack = temp->next;
	free(temp);
}
