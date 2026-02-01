/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidi <akhalidi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:10:09 by akhalidi          #+#    #+#             */
/*   Updated: 2026/02/01 20:21:34 by akhalidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long n, char *base)
{
	int	len;
	int	count;

	len = ft_strlen(base);
	count = 0;
	if (n >= len)
		count += ft_putnbr_base(n / len, base);
	count += ft_putchar(base[n % len]);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			count += ft_putchar('-');
		}
		if (n >= 10)
			count += ft_putnbr(n / 10);
		count += ft_putchar(((n % 10) + '0'));
	}
	return (count);
}

int	ft_putchar(char c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
	return (count);
}

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char	*str)
{
	int	i;
	int	count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
