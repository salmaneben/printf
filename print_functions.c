#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_string - printing a string
 * @args: Thelength of argument list
 * Return: void
*/

void print_string(va_list args)
{
	char *s = va_arg(args, char *);  /* get the string to print*/

	write(1, s, strlen(s));
}

/**
 * print_int - function that printing an integer
 * @args: The length argument list
 *
 * Return: void
 */

void print_int(va_list args)
{
	int num = va_arg(args, int);

	char str[50];  /* buffer to hold the string representation of the number*/

	sprintf(str, "%d", num);  /* convert the number to a string*/
	write(1, str, strlen(str));
}
