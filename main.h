#ifndef MAIN_H
#define MAIN_H

/* Variable arguments, NULL, system calls */
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/* Prototypes from utils.h */
int my_strlen(char *str);
char *convert(unsigned int num, int base);
char *convert_upper(unsigned long num, int base);

/* Structure for type information */
typedef struct type_s
{
char specifier;
void (*printer)(va_list);
} type_t;

/* Custom printf prototype */
int _printf(const char *format, ...);

/* Print function prototypes */
void print_char(va_list args);
void print_string(va_list args);
void print_int(va_list args);
void print_unsigned(va_list args);
void print_octal(va_list args);
void print_hex(va_list args);
void print_hex_upper(va_list args);
void print_pointer(va_list args);

/* Additional prototypes as needed */

#endif /* MAIN_H */
