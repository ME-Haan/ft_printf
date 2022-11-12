/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   switch.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 17:25:59 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/12 15:00:39 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	fmt_switch(char fmt, va_list arg)
{
	int	len;

	len = 0;
	if (fmt == 'c')
		len += put_chr_printf(arg);
	else if (fmt == 's')
		len += put_str_printf(arg);
	else if (fmt == 'd' || fmt == 'i')
		len += put_sign_dec(va_arg(arg, int), fmt);
	else if (fmt == 'u')
		len += put_uns_base(va_arg(arg, size_t), 10, fmt);
	else if (fmt == 'p')
		len += put_uns_base((size_t)va_arg(arg, void *), 16, fmt);
	else if (fmt == 'x' || fmt == 'X')
		len += put_uns_base(va_arg(arg, size_t), 16, fmt);
	else if (fmt == '%')
		len += write(1, "%", 1);
	return (len);
}
