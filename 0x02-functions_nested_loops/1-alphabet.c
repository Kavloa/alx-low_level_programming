#include "main.h"

/**
 * print_alphabet - print all lowercase character
 *
 * Return: void
 */
int print_alphabet(void)
{
	char lowercase;

	for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
		putchar(lowercase);

	putchar('\n');
}
