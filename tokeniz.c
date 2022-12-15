#include "monty.h"

/**
 * tokeniz - tokenization
 * @line: the line form the file
 * @lin_number: the line number
 *
 * Description: tokeniz each line of the file
 * Return: none
 */

int tokeniz(char* line, int line_number, stack_t **stack)
{
	char *tok;
	int i;
	instruction_t task[] = {
		{"push", push_int},
		{"pall", print_all},
		{NULL, NULL},
	};
	tok = strtok(line, " $\t\r\n");
	var_v.num = strtok(NULL, " $\t\r\n");
	while (task[i].opcode)
	{
		if (strcmp(tok, task[i].opcode) == 0)
		{
			task[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (tok == NULL && task[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tok);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);

}
