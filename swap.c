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
	int num1, num2;

	temp = *stack;
	num1 = temp->n;
	*stack = (*stack)->next;
	free(temp);
	temp = *stack;
	num2 = temp->n;
	*stack = (*stack)->next;
	free(temp);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	newnode(stack, num1);
	newnode(stack, num2);
}
