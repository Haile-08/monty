#include "monty.h"

/**
 * pstr - pstr
 * @stack: the top of the stack
 * @line_number: the number of lines
 *
 * Description: prints the string starting at the top of the stack
 * Return: nonoe
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int num;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		num = temp->n;
		if (num == 0)
			break;
		if (num < 0 || num > 127)
			break;
		if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
			printf("%c", num);
		temp = temp->next;
	}
	printf("\n");
}
