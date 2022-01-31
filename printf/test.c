#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putstr(char *str)
{
	int	 i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_len_nb(long long nb)
{
	long long len;

	len = 0;

	if (nb == 0)
		return (1);
	while (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);

}

int ft_putnbr(long long nb)
{
	long long n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	else
	n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	ft_putchar(n + '0');
	return (ft_len_nb(nb));
}

int	ft_len_hex(unsigned int nb)
{
	int len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_put_hex(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb >= 16)
	{
		ft_put_hex(nb/16, format);
		ft_put_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
		{
			if (format == 'x')
				ft_putchar(nb - 10 + 'a');
			else if (format == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
	return (ft_len_hex(nb));
}

int	ft_convertion(va_list ap, char c)
{
	int	len;

	len = 0;

	if (c == 's')
		len = len + ft_putstr(va_arg(ap, char *));
	if (c == 'd')
		len = len + ft_putnbr(va_arg(ap, int));
	if (c == 'x' || c == 'X')
		len = len + ft_put_hex(va_arg(ap, unsigned int), c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	va_list ap;

	va_start (ap, format);
	i = 0;
	len = 0;
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