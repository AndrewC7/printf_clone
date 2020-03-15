#include "printf.h"
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










	va_end(args);

	return (count)

}
