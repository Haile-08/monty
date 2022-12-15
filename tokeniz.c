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
		{NULL, NULL},
	};
	tok = strtok(line, " $\n\t");
	printf("token 1 = %s\n", tok);
	while (task[i].opcode != NULL)
	{
		printf("task[i].opcode != %s\n", task[i].opcode);
		if (strcmp(tok, task[i].opcode) == 0)
		{
			var.num = strtok(NULL, " $\n\t");
			printf("token 2 = %s\n", var.num);
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
