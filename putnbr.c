/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidi <akhalidi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:10:09 by akhalidi          #+#    #+#             */
/*   Updated: 2026/01/31 19:16:49 by akhalidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
