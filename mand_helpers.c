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
	count++;
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
			count++;
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
	int pow_10 = 10;
	int n = va_arg(args, int);

	if (n < 0)
	{
		putchar('-');
		count++;
		n = -n;
	}

	while (n / pow_10 > 9)
	{
		pow_10 *= 10;
	}
	putchar(n / pow_10 + '0');
	count++;

	if (n > 0)
	{
		while (pow_10 > 1)
		{
			pow_10 /= 10;
			putchar((n / pow_10) % 10 + '0');
			count++;
		}
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
	count++;
	return (count);
}
