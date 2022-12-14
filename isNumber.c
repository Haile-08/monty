#include "monty.h"

/**
 * isNumber - is a number
 * @s: string input
 *
 * Description: check if a string is a number
 * Return: 0 if s is a number 1 else
 */

int isNumber(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
			return 0;
	}
	return 1;
}
