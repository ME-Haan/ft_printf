/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/07 17:21:22 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	"../libft/libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list			arg;
	size_t			len;
	char			*s;
	unsigned long	n;

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
			else if (*fmt == 'p')
				len += ft_putnbr_base(va_arg(arg, unsigned long), 16, *fmt);
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
			else if (*fmt == 'x' || *fmt == 'X')
			{
				n = va_arg(arg, unsigned int);
				ft_putnbr_base(n, 16, *fmt);
				len += num_len_base(n, 16);
			}
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

#include	<stdio.h>
int	main (void)
{
	// char str[99] = "to test ft_printf!";
	// int num = 47574924;
	// char c = 'X';
	// int len;
	char	*ptr = "sns";

	// len = ft_printf("this is a test string %% %c %s %d\n", c, str, num);
	// len = ft_printf("%p", ptr);
	// ft_printf("\n%d\n", len);
	ft_printf("%i\n",  ft_printf("ft: %p\n", ptr));
	printf("%i\n", printf("lb: %p\n", ptr));
}
