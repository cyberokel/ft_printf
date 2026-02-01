*This project has been created as part of the 42 curriculum by akhalidi.*

## Description

ft_printf is a recreation of the standard C library function `printf()`. This project teaches about variadic functions in C and requires handling multiple format specifiers while maintaining accurate character counting.

The function handles the following conversions:
- `%c` - Single character
- `%s` - String
- `%p` - Pointer address in hexadecimal
- `%d` / `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Hexadecimal lowercase
- `%X` - Hexadecimal uppercase
- `%%` - Percent sign

## Instructions

### Compilation
```bash
make        # Compiles the library
make clean  # Removes object files
make fclean # Removes object files and library
make re     # Recompiles everything from scratch
```

### Usage

Include the header in your C file:
```c
#include "ft_printf.h"
```

Compile your program with the library:
```bash
cc your_program.c libftprintf.a
```

Example:
```c
ft_printf("Hello %s, you have %d points\n", "World", 42);
```

## Resources

### Documentation and Learning Materials
- [Linux man pages for printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [stdarg.h documentation](https://en.cppreference.com/w/c/variadic)
- [Understanding variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
