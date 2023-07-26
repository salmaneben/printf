#include "main.h"

void print_char(va_list args)
{
char c = va_arg(args, int); /* char is promoted to int when passed through ... */
write(1, &c, 1);
}
