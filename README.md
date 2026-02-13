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
- [Understanding variadic functions in C](https://www.cprogramming.com/tutorial/c/lesson17.html)

### AI Usage

I used Claude (AI assistant) as a learning mentor throughout this project:

**Concepts I learned with AI guidance:**
- Understanding signed vs unsigned integers and how casting works
- How bits are interpreted differently (two's complement)
- Makefile structure and syntax (variables, pattern rules, special symbols like `$@` and `$<`)
- Variadic functions and the va_list API

**How I used AI:**
- Asked for explanations and hints, NOT direct code solutions
- Requested step-by-step breakdowns of complex concepts
- Got debugging hints (e.g., "check if your negative handling works for unsigned types")
- Learned through questions and practical examples

**What I coded myself:**
- All function implementations (ft_printf, ft_putnbr, ft_putstr, ft_putnbr_base, etc.)
- Handling of all format specifiers (%c, %s, %p, %d, %i, %u, %x, %X, %%)
- Edge cases (NULL pointers, INT_MIN, NULL strings)
- The complete Makefile based on understanding the concepts

I followed 42's AI guidelines by using AI for learning and understanding, not for copying solutions. All code was written by me after grasping the underlying concepts.
