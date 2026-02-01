#include <stdio.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count;

	count	= 1;
	write(1, &c, 1);
	return (count);
}

int	ft_strlen(char *s)
{
	if (s == NULL)
		return (0);
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int	ft_putstr(char	*str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	check_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base(ptr, "0123456789abcdef");
	}
	return (count);
}

int	check_format(char indice, va_list ap)
{
	int	count;

	count = 0;
	if (indice == '\0')
		return (0);
	else if (indice == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (indice == '%')
		count += ft_putchar('%');
	else if (indice == 'd' || indice == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (indice == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (indice == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (indice == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (indice == 'p')
		count += check_ptr(va_arg(ap, unsigned long));
	else if (indice == 's')
		count += ft_putstr(va_arg(ap, char *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	ap;
	va_start(ap, format);

	i = 0;
	count = 0;
	if (format == NULL)
		return (count);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += check_format(format[i], ap);
		}
		else 
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}
int	main()
{
ft_printf("%d", 0);
ft_printf("%d", -2147483648);
ft_printf("%s", NULL);
ft_printf("%p", NULL);
ft_printf("%%");
ft_printf("%x", 0);
}
