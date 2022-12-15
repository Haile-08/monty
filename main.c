#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

var_t var = {NULL, NULL};

/**
 * main - Entry point
 * @ac: the number of args
 * @av: the array of the args
 *
 * Return: 0 on (Success)
 */

int main(int ac, char* av[])
{
	int line_number, c_read;
	FILE *fd;
	char *line;
	size_t len = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	var.file = fd;
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while ((c_read = getline(&line, &len, fd)) != -1)
	{
		tokeniz(line,line_number, &stack);
		free(line);
	}
	free_stack(stack);
	fclose(fd);
	return (0);
}
