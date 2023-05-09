#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Input files of Name
 * @letters: Input Number
 *
 * Return: Depends on Condition
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f_open, f_read, f_write;
	char *buffer;

	if (filename == NULL)
		return (0);

	f_open = open(filename, O_RDONLY);
	if (f_open < 0)
		return (0);
	buffer = (char *) malloc(letters * sizeof(char));
	if (buffer == NULL)
		return (0);
	f_read = read(f_open, buffer, letters);
	if (f_read < 0)
	{
		free(buffer);
		return (0);
	}
	buffer[f_read] = '\0';
	f_write = write(STDOUT_FILENO, buffer, f_read);
	if (f_write < 0)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(f_open);
	return (f_write);
}
