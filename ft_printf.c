#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if(nbr < -1)
		nbr = ft_putnbr()
}
int	check_format(char indice, va_list ap)
{
	int	count;

	count = 0;
	if (indice == NULL)
		return (0);
	else if (indice == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (indice == 'd' || indice == 'i'|| indice == 'u')
		ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (indice == 'x' || indice == 'X')
		ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (indice == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
//	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	ap;
	va_start(ap, format);

	i = 0;
	count = 0;
//	if (format[i] == NULL)
//		return (count);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_type(format[i], ap);
		}
		ft_putchar_fd(format[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	main()
{
	printf("%x\n",ft_printf("%d aywa %d ds\n", 42, 24));
}
