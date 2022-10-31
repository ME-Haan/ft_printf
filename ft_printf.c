/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/29 17:27:21 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	"libft.h"


// cspdiuxX%
int	ft_printf(const char *str, ...) // const char *?
{
	va_list	arg;
	va_start(arg, *);

	while (*str)
	{
		while (*str != '%')
		{
			ft_putchar_fd(1, &str);
			str++;
		}
		str++;
		

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