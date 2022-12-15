#include "monty.h"

/**
 * pop - Remove element
 * @stack: the top pointer of the stack
 * @line_number: the line number of the stack
 *
 * Description: removes the top element of the stack
 * Return: none
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}
