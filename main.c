#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

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

	printf("DEBUG: FILE NAME = %s\n", av[1]);
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	printf("DEBUG: NUMBER OF AGGUMENT: %d\n", ac);
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while ((c_read = getline(&line, &len, fd)) != -1)
	{
		tokeniz(line,line_number);
	}
	fclose(fd);
	if (line)
		free(line);
	return (0);
}
