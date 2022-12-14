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
	char *tok, *dilm = " $\t\r\n";
	int i;
	stack_t *ptr;
	
	instruction_t task[] = {
		{"push", push_int},
		{"pall", print_all},
		{NULL, NULL},
	};
	printf("DEBUG LINE %d: %s", line_number, line);
	tok = strtok(line, dilm);
	printf("TOKEN 1: %s\n", tok);
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (tok != NULL)
	{
		i = 0;
		while (task[i].opcode)
		{
			printf("task[%d].opcode = %s and %s\n",i ,task[i].opcode , tok);
			if (strcmp(tok, task[i].opcode) == 0)
			{
				printf("TOKEN FOUND FOR tok  %s = task[i].opecode %s ",tok,task[i].opcode);
				tok = strtok(NULL, dilm);
				printf("VALUE = %s\n",tok);
				if (!isNumber(tok))
				{
					fprintf(stderr,"L%d: usage: push integer\n",line_number);
					exit(EXIT_FAILURE);
				}
				ptr->n = atoi(tok);
				ptr->prev = NULL;
				ptr->next = NULL;
				task[i].f(&ptr, line_number);
			}
			++i;
		}
		tok = strtok(NULL, dilm);
	}
}
