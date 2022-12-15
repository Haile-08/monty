#include "monty.h"

/**
 * add - add
 * @stack: the top stack value
 * @line_number: the number of the line
 *
 * Description: add the top two elements of the stack
 * Return: none
 */

void add(stack_t **stack, unsigned int line_number)
{
	int len = 0, sum = 0, i = 2;
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = NULL;
	while (i > 0)
	{
		sum = sum + (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		i--;
	}
	newnode(stack, sum);
}
