#include "_primary.h"
#include <stdarg.h>

void output_to_buffer(char buffer[], int *buffer_index);

int custom_printf(const char *format, ...)
{
int i, output = 0, output_chars = 0;
int flags, width, precision, length, buffer_index = 0;
va_list args;
char buffer[BUFFER_CAPACITY];

if (format == NULL)
	return (-1);

va_start(args, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
	buffer[buffer_index++] = format[i];
if (buffer_index == BUFFER_CAPACITY)
	output_to_buffer(buffer, &buffer_index);
	output_chars++;
}
else
{
output_to_buffer(buffer, &buffer_index);
flags = extract_flags(format, &i);
width = extract_width(format, &i, args);
precision = extract_precision(format, &i, args);
length = extract_length(format, &i);
++i;
output = manage_print(format, &i, args, buffer,
flags, width, precision, length);
if (output == -1)
	return (-1);
output_chars += output;
}
}

output_to_buffer(buffer, &buffer_index);

va_end(args);

	return (output_chars);
}

void output_to_buffer(char buffer[], int *buffer_index)
{
if (*buffer_index > 0)
	write(1, &buffer[0], *buffer_index);

*buffer_index = 0;
}
