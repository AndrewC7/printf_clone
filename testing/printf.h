#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
  * struct datatype - datatype struct
  * @f_ptr: function pointer
  * @type: data type to match
  */

typedef struct datatype
{
	char *type;
	int (*f_ptr)(va_list args);
} data_t;


int _printf(const char *format, ...);
int _putchar(char c);
int _printchar(va_list args);
int _printstr(va_list args);
int _printnum(va_list args);

#endif
