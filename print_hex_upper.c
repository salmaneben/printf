#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void print_hex_upper(va_list args)
{
	unsigned long num = va_arg(args, unsigned long);
	char *str = convert_upper(num, 16);
	write(1, str, my_strlen(str));
}
