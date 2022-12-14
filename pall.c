#include "monty.h"

/**
 * print_all - print all
 * @stack: the stack
 * @line_number: the line number
 *
 * Description: print all
 * Return: none
 */

void print_all(__attribute__((unused))stack_t **stack,__attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr;
	ptr = temp;
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Stack underflow");
	}
	while (ptr != NULL)
	{
		printf("%d\n",ptr->n);
		ptr = ptr->next;
	}
}
