#include "monty.h"

/**
 * main - Entry point
 * @ac: the number of args
 * @av: the array of the args
 *
 * Return: 0 on (Success)
 */

int main(int ac, char* av[])
{
	int fd;
	char dilm[5] = "./n/a/t";
	char *tok;
	char *format = "m";

	if (ac != 2)
	{
		fprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == NULL)
	{
		fprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	tok = strtok(av[1], dilm);
	tok = strtok(0, dilm);
	if (tok != format)
	{
		fprintf(2, "Error: wrong monty file");
		exit(EXIT_FAILURE);
	}
}
