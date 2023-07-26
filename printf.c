#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/* Definition of the type_t structure array */
static type_t types[] = {
        { 'c', print_char },
        { 's', print_string },
        { 'd', print_int },
        { 'i', print_int },
        { 'u', print_unsigned },
        { 'o', print_octal },
        { 'x', print_hex },
        { 'X', print_hex_upper },
        { 'p', print_pointer },
        { '\0', NULL }
};

static void handle_format(char format_char, va_list args, int *len)
{
        int j;

        for (j = 0; types[j].specifier != '\0'; ++j)
        {
                if (format_char == types[j].specifier)
                {
                        types[j].printer(args);
                        if (format_char != 'l')
                        {
                                (*len)++;
                        }
                        break;
                }
        }

        if (types[j].specifier == '\0')
        {
                write(1, &format_char, 1);
                (*len)++;
        }
}

int _printf(const char *format, ...)
{
        va_list args;
        int i, len = 0;

        va_start(args, format);

        for (i = 0; format[i] != '\0'; ++i)
        {
                if (format[i] == '%')
                {
                        if (format[i + 1] == '%')
                        {
                                write(1, &format[i], 1);
                                len++;
                                i++;
                        }
                        else
                        {
                                handle_format(format[i + 1], &args, &len);
                                i++;
                        }
                }
                else
                {
                        write(1, &format[i], 1);
                        len++;
                }
        }

        va_end(args);

        return (len);
}
