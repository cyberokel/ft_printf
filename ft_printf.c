/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidi <akhalidi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:10:09 by akhalidi          #+#    #+#             */
/*   Updated: 2026/02/01 19:48:37 by akhalidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	if (format == NULL)
	{
		va_end(ap);
		return (count);
	}
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += check_format(format[i], ap);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
