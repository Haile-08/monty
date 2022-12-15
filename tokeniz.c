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
	int i = 0;
	instruction_t task[] = {
		{"push", push_int},
		{"pall", print_all},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_num},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL},
	};
	tok = strtok(line, " \n\t");
	if (strcmp(tok, "#") == 0)
		return (0);
	if (strcmp(tok, "$") == 0)
		return (0);
	var.num = strtok(NULL, " \n\t");
	tok = strtok(tok, "$");
	while (task[i].opcode != NULL)
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
		fclose(var.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);

}
