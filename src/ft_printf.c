/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:08:40 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/28 12:15:16 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	fmt_switch(char fmt, va_list arg, int *len)
{
	if (fmt == 'c')
		*len += put_chr_printf(va_arg(arg, int));
	else if (fmt == 's')
		*len += put_str_printf(va_arg(arg, char *));
	else if (fmt == 'd' || fmt == 'i')
		*len += put_sign_dec(va_arg(arg, int), fmt);
	else if (fmt == 'u')
		*len += put_uns_base(va_arg(arg, unsigned int), 10, fmt);
	else if (fmt == 'p')
		*len += put_uns_base(va_arg(arg, uintptr_t), 16, fmt);
	else if (fmt == 'x' || fmt == 'X')
		*len += put_uns_base(va_arg(arg, unsigned int), 16, fmt);
	else if (fmt == '%')
		*len += write(1, "%", 1);
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, str);
	len = 0;
	while (*str)
	{
		if (*str != '%')
		{
			if (++len && write(1, str, 1) == -1)
				return (-1);
		}
		else if (*str == '%' && ft_strchr("cspdiuxX%", *(str + 1)))
		{
			if (len > fmt_switch(*(str + 1), arg, &len))
				return (-1);
			if (*(str + 1))
				str++;
		}
		str++;
	}
	va_end(arg);
	return (len);
}

/*#include	<stdio.h>
int main(void)
{
	int printed_chars = 0;
	int my_printed_chars = 0;
	printed_chars = printf("OG: Hello %" );
	my_printed_chars = ft_printf("Me: Hello %");
	printf("\n(no. printed chars with printf: %i)\n", printed_chars);
	printf("(no. printed chars with ft_printf:  %i)\n", my_printed_chars);
	// ft_printf("%");
	return (0);
}*/