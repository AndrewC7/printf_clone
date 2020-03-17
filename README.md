# 0x11. C - printf

## Description
* _printf() produces output according to a format and writes output to stdout, the standard output stream. 
* Upon successful return, _printf() returns the number of characters printed (excluding the null byte used to end output to strings).
  * If an output error is encountered, a negative value is returned.
* The format string is a character string and is composed of zero or more directives:
  * ordinary characters (not %), which are copied unchanged to the output stream
  * conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the character %

## Flag Characters / Conversion Specifiers
The character % is followed by zero or more of the following flags:
#### d, i
* The int argument is converted to signed decimal notation. The default precision is 1.
#### c
* The int argument is converted to an unsigned char, and the resulting character is written.
#### s
*The const char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating null byte ('\0')

---

## Files:
### [_printf.c](./_printf.c)
* This file contains the meat of our printf() function. We initialize our data type struct, check to edge cases, and loop trough the format string returning the corresponding result.
### [mand_helpers.c](./mand_helpers.c)
* This file contains our helper functions basic printf() functionality. Helpers include: _printchar, _printstr, _printnum, and _printp
### [holberton.h](./holberton.h)
* This file contains all our function prototypes, a declaration of our data type struct, and some standard libraries
---

## Authors
* **Andrew Cox** - [AndrewC7](https://github.com/AndrewC7)
* **Samuel Pomeroy** - [allelomorph](https://github.com/allelomorph)
* **Sam Messenger** - [SamMessenger](https://github.com/sammessenger)
