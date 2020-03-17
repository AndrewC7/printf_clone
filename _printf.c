#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to format
 * @format: datatype to print
 * Return: input length
 */
int _printf(const char * const format, ...)
{
	int count = 0;
	va_list args;
	int i, j;

	data_t type[] = {
		{"c", _printchar},
		{"s", _printstr},
		{"d", _printnum},
		{"i", _printnum},
		{"%", _printp},
		{NULL, NULL},
	};

	va_start(args, format);

	if (format == NULL)
		return (-1);
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	if (format[0] == '%' && format[1] == ' ')
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; type[j].type; j++)
			{
				if (format[i + 1] == *(type[j].type))
				{
					count += type[j].f_ptr(args);
					i += 2;
				}
			}
		}
		_putchar(format[i]);
		count++;
	}
	va_end(args);
	return (count);
}
