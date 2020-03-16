#include "printf.h"

/**
 * _printchar - prints char when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */
int _printchar(va_list args)
{
	int count = 0;
	_putchar(va_arg(args, int));
	count += 1;
	return (count);
}

/**
 * _printstr - prints string when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */
int _printstr(va_list args)
{
	int count = 0;
	int i;

	if (va_arg(args, char *))
	{
		for (i = 0; va_arg(args, char *); i++)
		{
			_putchar(va_arg(args, char *)[i]);
			count += 1;
		}
	}
	return (count);
}

/**
 * _printnum - prints signed int as string when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */
int _printnum(va_list args)
{
	int count = 0;
	int n = va_arg(args, int);

	if (n > 0)
	{
		_putchar('-');
		count += 1;
		n = -n;
	}
/* recursion draft:
	if (n / 10)
	{
		_printnum(n / 10);
	}
	_putchar(n % 10); */
	while (n % 10)
	{
		_putchar(n % 10);
		count += 1;
		n /= 10;
	}
	return (count);
}

/**
 * _printp - prints percent sign when called by format tag in printf
 * Return: output length in bytes/chars
 */
int _printp(va_list args)
{
	int count = 0;
	(void)args;

	_putchar('%');
	count += 1;
	return (count);
}
