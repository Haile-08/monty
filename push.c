#include "monty.h"

/**
 * push_int - push int
 * @stack: the stack pointer
 * @lint_number: the line number
 *
 * Description: push the integer
 * Return: none
 */

void push_int(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		ptr->n = (*stack)->n;
		ptr->next = NULL;
		temp = ptr;
	}
	else
	{
		ptr->n = (*stack)->n;
		temp->next = temp;
		temp = ptr;
	}
}
