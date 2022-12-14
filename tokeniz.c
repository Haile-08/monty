#include "monty.h"

/**
 * tokeniz - tokenization
 * @line: the line form the file
 * @lin_number: the line number
 *
 * Description: tokeniz each line of the file
 * Return: none
 */

void tokeniz(char* line, int line_number)
{
	char *tok, dilm = " \t\r\n";
	int i;
	stack_t ptr;

	instruction_t task[] = {
		{"push", push_int},
		{"pall", print_all},
		{NULL, NULL},
	};
	tok = strtok(line, dilm);
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	while (tok != NULL)
	{
		i = 0;
		while (task[i].opcode)
		{
			if (tok == task[i].opcode)
			{
				tok = strtok(NULL, dilm);
				ptr->n = atoi(tok);
				ptr->prev = NULL;
				ptr->next = NULL;
				task[i].f(ptr, line_number);
			}
			++i;
		}
		tok = strtok(NULL, dilm);
	}
}
