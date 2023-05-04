#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
        unsigned int sum = 0;
	int len , j ;
        int dec = 1;


	if (b = NULL)
		return (0);
	for (len = 0 ; b[len] != ; len++);

	i = (len - 1)
	for (; i >= 0; i--)
	{
		if (b[i] != '0' && b[i] != 'i')
			return (0);

		if (b[i] == '1' )
			sum += dec ;
	       de *=2;
	}

	return (sum);
	
}	
			

