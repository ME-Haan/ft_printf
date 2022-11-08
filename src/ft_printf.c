/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/08 11:38:08 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		arg;
	size_t		len;
	char		c;
	char		*s;

	va_start(arg, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			len += write(1, fmt, 1);
		else
		{
			fmt++;
			if (*fmt == 'c')
			{
				c = va_arg(arg, int);
				len += write(1, &c, 1);
			}
			else if (*fmt == 's')
			{
				s = va_arg(arg, char *);
				len += write(1, s, ft_strlen(s));
			}
			else if (*fmt == 'd' || *fmt == 'i')
			{
				// s = ft_itoa(va_arg(arg, int));
				// len += write(1, s, ft_strlen(s));
				len += ft_putnbr_base(va_arg(arg, int), 10, *fmt);
			}
			else if (*fmt == 'u')
			{
				// s = ft_itoa(va_arg(arg, unsigned int));
				// len += write(1, s, ft_strlen(s));
				len += ft_putnbr_base(va_arg(arg, unsigned int), 10, *fmt);
			}
			else if (*fmt == 'p')
				len += ft_putnbr_base(va_arg(arg, unsigned long), 16, *fmt);
			else if (*fmt == 'x' || *fmt == 'X')
				len += ft_putnbr_base(va_arg(arg, unsigned long), 16, *fmt);
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
// 	char str[99] = "to test ft_printf!";
// 	int num = -47574924;
// 	char c = 'X';
// 	// int len;

// 	ft_printf("\n%i\n", ft_printf("this is a test string %% %c %s %u", c, str, num));
// 	printf("\n%i\n", printf("this is a test string %% %c %s %u", c, str, num));
// 	// char	*ptr = "sns";
// 	// ft_printf("\n%d\n", len);
// 	// ft_printf("%i\n",  ft_printf("ft: %p\n", ptr));
// 	// printf("%i\n", printf("lb: %p\n", ptr));
// }
