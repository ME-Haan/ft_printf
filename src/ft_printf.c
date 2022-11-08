/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/08 16:43:43 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	int		len;
	char	c;
	char	*s;

	va_start(arg, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			len += write(1, fmt, 1);
		else if (++fmt)
		{
			if (*fmt == 'c')
			{
				c = va_arg(arg, int);
				len += write(1, &c, 1);
			}
			else if (*fmt == 's')
			{
				s = va_arg(arg, char *);
				if (!s)
					len += write(1, "(null)", 6);
				else
					len += write(1, s, ft_strlen(s));
			}
			else if (*fmt == 'd' || *fmt == 'i')
				len += put_sign_dec(va_arg(arg, int), *fmt);
			else if (*fmt == 'u')
				len += put_uns_base(va_arg(arg, size_t), 10, *fmt);
			else if (*fmt == 'p')
				len += put_uns_base((size_t)va_arg(arg, void *), 16, *fmt);
			else if (*fmt == 'x' || *fmt == 'X')
				len += put_uns_base(va_arg(arg, size_t), 16, *fmt);
			else if (*fmt == '%')
				len += write(1, "%", 1);
		}
		fmt++;
	}
	va_end(arg);
	return (len);
}

// #include	<stdio.h>
// int	main (void)
// {
// 	// char str[99] = "to test ft_printf!";
// 	// int num = -47574924;
// 	// char c = 'X';
// 	// int len;

// 	// ft_printf("\n%i\n", ft_printf("this is a test string %% %c %s %u", c, str, num));
// 	// printf("\n%i\n", printf("this is a test string %% %c %s %u", c, str, num));

// 	// ft_printf("\n%i\n", ft_printf("%i", -2147483648));
// 	// printf("\n%i\n", printf("%li", -2147483648));

// 	ft_printf("\n%i\n", ft_printf("%s", (char *)NULL));
// 	printf("\n%i\n", printf("%s", (char *)NULL));

// 	// void *ptr = (void *)-14523;
// 	// ft_printf("\n%i\n", ft_printf("ft: %p", (void *)-14523));
// 	// printf("\n%i\n", printf("lb: %p", (void *)-14523));
// }
