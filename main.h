#ifndef _PRIMARY_H_
#define _PRIMARY_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED_VAR(x) (void)(x)
#define BUFFER_CAPACITY 1024

/* FLAG SET */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* LENGTHS */
#define LENGTH_LONG 2
#define LENGTH_SHORT 1

typedef struct formatting formatting_t;

/**
 * struct formatting - Struct op
 *
 * @format: The format.
 * @func: The function associated.
 */
struct formatting
{
char format;
int (*func)(va_list, char[], int, int, int, int);
};

int custom_printf(const char *format, ...);
int manage_print(const char *format, int *index,
va_list args, char buffer[], int flags, int width, int precision, int length);

/****************** FUNCTION DEFINITIONS ******************/

/* Funtions to print chars and strings */
int output_char(va_list args, char buffer[],
int flags, int width, int precision, int length);
int output_string(va_list args, char buffer[],
int flags, int width, int precision, int length);
int output_percent(va_list args, char buffer[],
int flags, int width, int precision, int length);

/* Functions to print numbers */
int output_int(va_list args, char buffer[],
int flags, int width, int precision, int length);
int output_binary(va_list args, char buffer[],
int flags, int width, int precision, int length);
int output_unsigned(va_list args, char buffer[],
int flags, int width, int precision, int length);
int output_octal(va_list args, char buffer[],
int flags, int width, int precision, int length);
int output_hexadecimal(va_list args, char buffer[],
int flags, int width, int precision, int length);
int output_hexa_upper(va_list args, char buffer[],
int flags, int width, int precision, int length);

int output_hexa(va_list args, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int length);

/* Function to print non printable characters */
int output_non_printable(va_list args, char buffer[],
int flags, int width, int precision, int length);

/* Function to print memory address */
int output_pointer(va_list args, char buffer[],
int flags, int width, int precision, int length);

/* Functions to handle other specifiers */
int extract_flags(const char *format, int *index);
int extract_width(const char *format, int *index, va_list args);
int extract_precision(const char *format, int *index, va_list args);
int extract_length(const char *format, int *index);

/*Function to print string in reverse*/
int output_reverse(va_list args, char buffer[],
int flags, int width, int precision, int length);

/*Function to print a string in rot 13*/
int output_rot13(va_list args, char buffer[],
int flags, int width, int precision, int length);

/* width handler */
int manage_write_char(char c, char buffer[],
int flags, int width, int precision, int length);
int write_number(int is_positive, int index, char buffer[],
int flags, int width, int precision, int length);
int write_num(int index, char bff[], int flags, int width, int precision,
int length, char padding, char extra_char);
int write_pointer(char buffer[], int index, int length,
int width, int flags, char padding, char extra_char, int padding_start);

int write_unsigned(int is_negative, int index,
char buffer[],
int flags, int width, int precision, int length);

/****************** UTILITIES ******************/
int is_printable_char(char);
int append_hexa(char, char[], int);
int is_number(char);

long int adjust_size_number(long int num, int length);
long int adjust_size_unsigned(unsigned long int num, int length);

#endif /* _PRIMARY_H_ */
