#include "monty.h"

/**
 * print_all - print all
 * @stack: the stack
 * @line_number: the line number
 *
 * Description: print all
 * Return: none
 */

void print_all(stack_t **stack,__attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr;
	ptr = *stack;
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Stack underflow");
	}
	while (ptr)
	{
		printf("%d\n",ptr->n);
		ptr = ptr->next;
	}
}
