#include "monty.h"

/**
 * rotl - rotl
 * @stack: the top of the stack
 * @line_number: the line that is read
 *
 * Description: rotates the stack to the top
 * Return: none
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int top;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	(void)line_number;
	temp = *stack;
	top = temp->n;
	while (temp->next)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	temp->n = top;
	temp = NULL;
	free(temp);
}
