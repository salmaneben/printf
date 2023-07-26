#include "main.h"

/* A helper function to calculate string length */
int my_strlen(char *str)
{
int len = 0;
while (*str)
{
        len++;
        str++;
}

        return (len);
}

char *convert_upper(unsigned long num, int base)
{
static const char Representation[] = "0123456789ABCDEF";
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
