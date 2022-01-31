#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* LIBFTPRINTF */
int		ft_convertion(va_list ap, char c);
int		ft_printf(const char *format, ...);
/* UTILS */
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_nb_lenght(long long n);
int		ft_putnbr(long long nb);
/* CONVRTION HEXA */
size_t	ft_strlen(char *s);
int		ft_same_char(char *base);
int		ft_is_base(char *base);
int		ft_nb_lenght_hex(unsigned int n);
int		ft_putnbr_base(unsigned int nb, char *base);
/* CONVERTION U */
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_nb_lenght_unsigned(unsigned int n);
/* CONVERTION P */
int		ft_nb_lenght_p(uintptr_t n);
void	ft_putnbr_p(uintptr_t nb);
int		ft_putstr_p(uintptr_t p);

#endif