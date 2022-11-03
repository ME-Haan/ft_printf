/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/03 17:38:57 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	"./libft/libft.h"

#include	<stdio.h>

static char	*convert (unsigned int num, int base)
{
	const char	*symbols = "0123456789ABCDEF";
	char	str[99];
	char	*ptr;

	ptr = &str[98];
	*ptr = '\0';
	while (num)
	{
		// printf("%i", num);
		*--ptr = symbols[num % base];
		// printf("%c", *ptr);
		num /= base;
	}
	printf("%s", ptr);
	return (ptr);
}

int	ft_printf(const char *fmt, ...) 
{
	va_list			arg;
	size_t			len;
	char			*s;
	// unsigned int	i;

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
			if (*fmt == 's')
			{
				s = va_arg(arg, char *);
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			// if (*fmt == 'p')
			// {
				
			// }
			if (*fmt == 'd' || *fmt == 'i')
			{
				s = ft_itoa(va_arg(arg, int));
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			if (*fmt == 'u')
			{
				s = ft_itoa(va_arg(arg, int));
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			if (*fmt == 'x')
			{
				s = convert(va_arg(arg, unsigned int), 16);
				printf("%s\n", s);
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
			}
			// if (*fmt == 'X')
			// {
				
			// }
			if (*fmt == '%')
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
	// ft_printf("this is a test string %% %c %s %d\n", c, str, num);
	ft_printf("%x\n", 1000);
	return (0);
}