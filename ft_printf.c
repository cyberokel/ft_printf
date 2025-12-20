void	check_type(char c, ...)
{
	if (c == s)
		while(srt[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	else if(c == d)
		ft_putnbr();
	else if (c == c)
		write(1, &c, 1);
	return i;
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
	while (*format)
	{
		if (format[i] == '%')
		i++;
	}
	return (count);
}
