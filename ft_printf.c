#include "libft.h"
#include <stdarg.h>
void	check_type(char indice, va_list ap)
{
	if (indice == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (indice == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (indice == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
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
			i++;
		}
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return (count);
}

int	main()
{
	ft_printf("aywa %d ds", 42);
}
