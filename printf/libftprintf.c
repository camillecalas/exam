
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_nb_lenght(long long n)
{
	long long	len;

	len = 0;
	if (n == 0)
		return (len = 1);
	while (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(long long nb)
{
	long long	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = (nb * -1);
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	ft_putchar(n + '0');
	return (ft_nb_lenght(nb));
}

int	ft_nb_lenght_hex(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_put_hex(unsigned int num, const char format)
{	
	if (num == 0)
		return (write(1, "0", 1));
	else if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
	return (ft_nb_lenght_hex(num));
}

int	ft_convertion(va_list ap, char c)
{
	int	len;

	len = 0;

	 if (c == 's')
		len = len + ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		len = len + ft_putnbr(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		len += ft_put_hex(va_arg(ap, unsigned int), c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_convertion(ap, format[i]);
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
