#include "monty.h"

/**
 * swap - swap
 * @stack: the top of the stack
 * @line_number: the line number of the opcode
 *
 * Description: swaps the top two elements of the stack
 * Return: none
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int num, len = 0;

	temp = *stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	num = temp->n;
	temp->n = temp->next->n;
	temp->next->n = num;
}
