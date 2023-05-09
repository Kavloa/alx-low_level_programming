#include "main.h"

/**
 * create_file -> Creates a file
 *
 * @filename: Input files of name
 * @text_content: Input Text
 *
 * Return: Depends on Condition
*/

int create_file(const char *filename, char *text_content)
{
	int f_open, f_write, k;

	if (filename == NULL)
		return (-1);
	f_open = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (f_open < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(f_open);
		return (1);
	}
	for (k = 0; text_content[k] != '\0'; k++)
		;
	f_write = write(f_open, text_content, k);
	if (f_write < 0)
		return (-1);
	close(f_open);
	return (1);
}
