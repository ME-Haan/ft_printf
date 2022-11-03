/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/01 12:19:38 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	"libft.h"


// cspdiuxX%
int	ft_printf(const char *fmt, ...) 
{
	va_list	arg;
	va_start(arg, fmt);

	while (*fmt)
	{
		while (*fmt != '%')
		{
			ft_putchar_fd(1, &fmt);
			fmt++;
		}
		fmt++;
		

	}
	va_end(arg);
	return (0);
}

int	main (void)
{
	char str[99] = "to test ft_printf!";
	ft_printf("this is a test string %s", str);
	return (0);
}