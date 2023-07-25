#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Function to print unsigned integers*/
void print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char str[50];
	sprintf(str, "%u", num);
	write(1, str, strlen(str));
}

/* Function to print octal numbers*/
void print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char str[50];
	sprintf(str, "%o", num);
	write(1, str, strlen(str));
}
