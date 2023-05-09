#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 *
 * @filename: Input file of name
 * @text_content: Input Text
 *
 * Return: Depends on Condition
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int f_open, f_write, p;

	if (filename == NULL)
		return (-1);
	f_open = open(filename, O_WRONLY | O_APPEND);
	if (f_open < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(f_open);
		return (1);
	}
	for (p = 0; text_content[p] != '\0'; p++)
		;
	f_write = write(f_open, text_content, p);
	if (f_write < 0)
		return (-1);
	close(f_open);
	return (1);
}
