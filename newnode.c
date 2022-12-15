#include "monty.h"

/**
 * newnode - new node
 * @stack: the top of the stack
 * @n: the input value
 *
 * Description: add a new node
 * Return: none
 */
void newnode(stack_t **top, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	if (*top == NULL)
		new->next = NULL;
	else
		new->next = *top;
	*top = new;
}
	
