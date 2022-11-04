/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/04 12:00:58 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	"libft.h"

#include	<stdio.h>

// static int	print_convert(unsigned int num, int base)
// {
// 	const char	*symbols = "0123456789ABCDEF";
// 	size_t		len;

// 	len = 0;
// 	while (num != 0)
// 	{
// 		ft_putchar_fd(symbols[num % base], 1);
// 		len++;
// 		num /= base;
// 	}
// 	return (len);
// }

static int	ft_putnbr_base(unsigned int n, int base, size_t len)
{
	const char	*symbols = "0123456789ABCDEF";
	long long	tmp;
	
	tmp = n;
	if (tmp / base != 0)
	{
		ft_putnbr_base(tmp / base, 16, len);
	}
	len++;
	ft_putchar_fd(symbols[tmp % base], 1);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			arg;
	size_t			len;
	char			*s;

	va_start(arg, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			len++;
		}
		else
		{
			fmt++;
			if (*fmt == 'c')
			{
				ft_putchar_fd(va_arg(arg, int), 1);
				len++;
			}
			else if (*fmt == 's')
			{
				s = va_arg(arg, char *);
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			//else if (*fmt == 'p')
			// {
				
			// }
			else if (*fmt == 'd' || *fmt == 'i')
			{
				s = ft_itoa(va_arg(arg, int));
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			else if (*fmt == 'u')
			{
				s = ft_itoa(va_arg(arg, int));
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			else if (*fmt == 'x')
			{
				len += ft_putnbr_base(va_arg(arg, unsigned int), 16, 0);
			}
			//else if (*fmt == 'X')
			// {
				
			// }
			else if (*fmt == '%')
			{
				ft_putchar_fd('%', 1);
				len++;
			}
		}
		fmt++;
	}
	va_end(arg);
	return (len);
}

int	main (void)
{
	// char str[99] = "to test ft_printf!";
	// int num = 12345;
	// char c = 'X';
	size_t len;

	// len = ft_printf("this is a test string %% %c %s %d\n", c, str, num);
	len = ft_printf("%x\n", 1000);
	printf("%lu\n", len);
	return (0);
}
