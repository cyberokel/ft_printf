#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	int	count;

	count	= 1;
	write(1, &c, 1);
	return (count);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int	ft_checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	long	n;
	int	count;

	n = nbr;
	len = ft_strlen(base);
	count = 0;
	if (n < -1)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= len)
		count += ft_putnbr_base(n / len, base);
	ft_putchar(base[n % len]);
	return (count);
}

int	ft_putstr(char	*str)
{
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

int	check_format(char indice, va_list ap)
{
	int	count;

	count = 0;
	if (indice == '\0')
		return (0);
	else if (indice == 'c')
	{
		ft_putchar(va_arg(ap, int));
		count++;
	}
	else if (indice == 'd' || indice == 'i'|| indice == 'u')
		count += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (indice == 'x' || indice == 'X')
		count += ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (indice == 's')
		count = ft_putstr(va_arg(ap, char *));
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
		if (format[i] == '%')
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
	ft_printf("%s", "123");
}	
