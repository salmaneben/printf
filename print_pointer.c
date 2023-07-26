#include "main.h"
#include <stdlib.h> /* for malloc */
#include <stdio.h> /* for sprintf */

void print_pointer(va_list args)
{
void *addr = va_arg(args, void *);
char *str = malloc(20); /* adjust size as necessary */
sprintf(str, "%p", addr);
write(1, str, my_strlen(str));
free(str);
}
