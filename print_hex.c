#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/* Added to have access to my_strlen and va_list */

/**
 * *convert - function for converting an unsigned integer
 * @num: represents the unsigned integer value that you want to convert
 * @base: specifies the base to which you want to convert the number.
 * Return: Always 0
 */

char *convert(unsigned int num, int base)
{
	static const char Representation[] = "0123456789abcdef";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 * print_hex - printing an integer as a hexadecimal value
 * @args: The length argument list
 * Return: void
*/

void print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert(num, 16);

	write(1, str, my_strlen(str));
}
