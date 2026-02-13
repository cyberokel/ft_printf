/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidi <akhalidi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:48:30 by akhalidi          #+#    #+#             */
/*   Updated: 2026/02/13 18:18:45 by akhalidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_strlen(char	*s);
int	ft_printf(const char *format, ...);
int	ft_putnbr_base(unsigned long n, char *base);
int	ft_putstr(char *str);
int	ft_putnbr(int n);

#endif
