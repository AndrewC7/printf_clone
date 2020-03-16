#include "printf.h"

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

	data_t type[] = {
		{"c", _printchar},
		{"s", _printstr},
		{"d", _printnum},
		{"i", _printnum},
		{"%", _printp},
		{NULL, NULL},
	};

	va_start(args, format);

/* stdio.h printf always has a string as the first arg, regardless of whether
 or not it's just format tags or a larger printable string containing format
 tags. */

/* so if const char * const format is that string, looking at the example
 outputs from their main, we don't measure the length in chars until the end,
 after all formatting */

/* mockup of basic structure using _putchar: */
	for (i = 0; format && format[i]; i++)
	{
/* iterating though to print it char by char, we test for the % fmt tag
 indicator: */
		if (format[i] == '%')
		{
/* iterate though fmt tag members of each struct in array 'type' */
			for (j = 0; type[j].type; j++)
			{
/* if the next char in format matches one of the type members of the structs
   in array 'type' */
				if (format[i + 1] == *(type[j].type))
				{
/* execute function pointed to by f_ptr on the next arg in va_list */
					type[j].f_ptr(args);
				}
			}
/* what to do with a non matching char after '%'? throw an error? we already
   have _printp for "%%" */
		}

/* encounter neither format tag, print chars in format string.
 maybe we can measure as we print, with count += 1? this may not work with
 helper functions */
		_putchar(format[i]);
	}

	va_end(args);

	return (count);

}




/* turns out escape chars are part of shell, do not need to build them into
   printf. defualt putchar handles them.

 and also test for the escape character, \. here is it necessary to do an
 array of structs, or can we just do a 2D array, given that we are just
 swapping char for char? maybe offboard it entirely to a helper function?

		if (format[i] == '\\')
		{
 iterate through first column of escape_c, looking for match
			for (j = 0; escape_c[j][0]; j++)
			{
				if (format[i] == escape_c[j][0])
				{
 is so, print formatted char
					_putchar(escape_c[j][1]);
				}
			}
 again, what to print if second char doesn't match? look to behavior of
 stock printf?
		}

 char replacement array for escape characters. see below.
 chars limited to examples from task reading.
	char escape_c[9][] = {
		{'a', '\a'},
		{'b', '\b'},
		{'f', '\f'},
		{'n', '\n'},
		{'r', '\r'},
		{'t', '\t'},
		{'v', '\v'},
		{'%', '\%'},
		{NULL, NULL}
	};
*/
