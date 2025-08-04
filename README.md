# 0x11. C - printf

## Description

This project is a custom implementation of the `printf` function in C, created as part of the ALX Software Engineering program. The project aims to recreate the functionality of the standard library `printf` function, handling various format specifiers and modifiers.

## Project Overview

The `_printf` function produces output according to a format string and prints data to the standard output stream. This implementation supports multiple conversion specifiers, flags, field width, precision, and length modifiers.

## Features

### Supported Format Specifiers
- `%c` - Character
- `%s` - String
- `%d`, `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%o` - Unsigned octal
- `%x` - Unsigned hexadecimal (lowercase)
- `%X` - Unsigned hexadecimal (uppercase)
- `%p` - Pointer address
- `%b` - Binary (custom specifier)
- `%S` - String with non-printable characters
- `%r` - Reversed string
- `%R` - ROT13 encoded string
- `%%` - Literal percent sign

### Supported Flags
- `-` : Left-justify the output
- `+` : Prefix positive numbers with a plus sign
- ` ` : Prefix positive numbers with a space
- `#` : Use alternative form for o, x, X
- `0` : Pad with zeros instead of spaces

### Field Width and Precision
- Field width: Minimum number of characters to output
- Precision: Maximum number of characters for strings, decimal places for numbers

### Length Modifiers
- `l` : Long modifier
- `h` : Short modifier

## Files

| File | Description |
|------|-------------|
| `main.h` | Header file containing function prototypes, macros, and struct definitions |
| `printf.c` | Main implementation of the `custom_printf` function |
| `print_char.c` | Functions to handle character and string printing |
| `print_functions.c` | Basic printing functions for integers and numbers |
| `print_functions1.c` | Additional printing functions |
| `print_hex.c` | Functions to handle hexadecimal (lowercase) conversion |
| `print_hex_upper.c` | Functions to handle hexadecimal (uppercase) conversion |
| `print_pointer.c` | Functions to handle pointer address printing |
| `utils.c` | Utility functions for string manipulation and number conversion |

## Function Prototypes

### Main Function
```c
int custom_printf(const char *format, ...);
```

### Output Functions
```c
int output_char(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_string(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_int(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_binary(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_unsigned(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_octal(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_hexadecimal(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_hexa_upper(va_list args, char buffer[], int flags, int width, int precision, int length);
int output_pointer(va_list args, char buffer[], int flags, int width, int precision, int length);
```

### Parsing Functions
```c
int extract_flags(const char *format, int *index);
int extract_width(const char *format, int *index, va_list args);
int extract_precision(const char *format, int *index, va_list args);
int extract_length(const char *format, int *index);
```

## Compilation

To compile the project, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

## Usage

### Basic Examples

```c
#include "main.h"

int main(void)
{
    custom_printf("Hello, World!\n");
    custom_printf("Character: %c\n", 'A');
    custom_printf("String: %s\n", "Hello");
    custom_printf("Integer: %d\n", 123);
    custom_printf("Hex: %x\n", 255);
    custom_printf("Binary: %b\n", 8);
    
    return (0);
}
```

### Advanced Examples

```c
#include "main.h"

int main(void)
{
    custom_printf("Left-aligned: %-10s|\n", "Hello");
    custom_printf("Right-aligned: %10s|\n", "Hello");
    custom_printf("Zero-padded: %05d\n", 42);
    custom_printf("Positive with sign: %+d\n", 42);
    custom_printf("Pointer: %p\n", (void *)&main);
    
    return (0);
}
```

## Testing

To test the function, create a test file and compare the output with the standard `printf`:

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;
    
    len1 = custom_printf("Custom: %d\n", 42);
    len2 = printf("Standard: %d\n", 42);
    
    custom_printf("Custom length: %d\n", len1);
    printf("Standard length: %d\n", len2);
    
    return (0);
}
```

## Implementation Details

### Buffer Management
The implementation uses a buffer system with a capacity of 1024 characters to optimize output operations. The buffer is flushed when full or when the function completes.

### Flag Processing
Flags are processed using bitwise operations for efficient flag checking:
- `FLAG_MINUS` (1) - Left alignment
- `FLAG_PLUS` (2) - Show sign for positive numbers
- `FLAG_ZERO` (4) - Zero padding
- `FLAG_HASH` (8) - Alternative form
- `FLAG_SPACE` (16) - Space for positive numbers

### Memory Management
The function manages memory carefully to avoid buffer overflows and ensures proper cleanup of variable argument lists.

## Return Value

The function returns the number of characters printed (excluding the null byte used to end output to strings). If an error occurs, a negative value is returned.

## Requirements

- Ubuntu 20.04 LTS
- gcc 4.8.4 or later
- Compilation with `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows Betty style guidelines

## Author

Created as part of the ALX Software Engineering program.

## License

This project is for educational purposes as part of the ALX curriculum.

---

**Note**: This is a learning project and should not be used as a replacement for the standard library `printf` function in production code. 
