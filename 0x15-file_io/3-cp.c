#include "main.h"

/**
 * main - Entrys point
 *
 * @argc: Input Arguments number
 * @argv: Input Arguments value
 *
 * Return: Always 0
*/

int main(int argc, char *argv[])
{
	int f_read, f_write, f, d, l;
	char buffer[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy file_from file_to\n");
		exit(97);
	}
	f_read = open(argv[1], O_RDONLY);
	if (f_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		exit(98);
	}
	f_write = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((f = read(f_read, buffer, BUFSIZ)) > 0)
	{
		if (f_write < 0 || write(f_write, buffer, f) != f)
		{
			dprintf(STDERR_FILENO, "Error: Cannot write to %s\n", argv[2]);
			close(f_read);
			exit(99);
		}
	}
	if (f < 0)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]);
		exit(98);
	}
	d = close(f_read);
	l = close(f_write);
	if (d < 0 || l < 0)
	{
		if (d < 0)
			dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", f_read);
		if (l < 0)
			dprintf(STDERR_FILENO, "Error: Cannot close fd %d\n", f_write);
		exit(100);
	}
	return (0);
}
