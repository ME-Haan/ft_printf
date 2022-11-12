/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/12 14:25:43 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt != '%')
			len += write(1, fmt, 1);
		else if (++fmt)
		{
			if (!(ft_strchr("cspdiuxX%", *fmt)))
				return (len);
			else
				len += fmt_switch(*fmt, arg);
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
// 	int num = -1234;
// 	char c = 'X';
// 	// int len;

// 	ft_printf("\n%i\n", ft_printf("this is a str %% %c %s %i", c, str, num));
// 	printf("\n%i\n", printf("this is a str %% %c %s %i", c, str, num));

// 	// ft_printf("\n%i\n", ft_printf("%i", -2147483648));
// 	// printf("\n%i\n", printf("%li", -2147483648));

// 	// ft_printf("\n%i\n", ft_printf("%s", (char *)NULL));
// 	// printf("\n%i\n", printf("%s", (char *)NULL));

// 	// void *ptr = (void *)-14523;
// 	// ft_printf("\n%i\n", ft_printf("ft: %p", (void *)-14523));
// 	// printf("\n%i\n", printf("lb: %p", (void *)-14523));

// 	// printf("lib: %");
// 	// ft_printf("mine: %");

// }
