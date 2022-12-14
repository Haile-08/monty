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
	char dilm[5] = ".\t\r\n";
	char *tok, *format = "m", *line;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], O_RDONLY);
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	tok = strtok(av[1], dilm);
	tok = strtok(0, dilm);
	if (tok != format)
	{
		fprintf(stderr, "Error: wrong monty file");
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while ((c_read = getline(&line, NULL, fd)) != -1)
	{
		tokeniz(line,line_number);
	}
	fclose(fd);
	if (line)
		free(line);
	return (0);
}
