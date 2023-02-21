#include "main.h"

/**
 * print_alphabet - print all lowercase character
 *
 * Return: void
 */

void print_alphabet(void)

{
        char lc;

        for (lc = 'a'; lc <= 'z'; lc++)
                _putchar(lc);
        _putchar('\n');
}
