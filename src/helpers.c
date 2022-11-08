/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:38:30 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/08 11:38:52 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	<stdio.h>

size_t	ft_putnbr_base(long long n, int base, char fmt)
{
	const char	*symbols = "0123456789ABCDEF";
	size_t		len;
	char		tmp;

	len = 0;
	if (fmt == 'p')
	{
		len += write(1, "0x", 2);
		fmt = 'x';
	}
	if ((n / base) != 0)
		len += ft_putnbr_base(n / base, base, fmt);
	if (fmt == 'x')
	{
		tmp = ft_tolower(symbols[n % base]);
		len += write(1, &tmp, 1);
	}
	else if (fmt == 'X')
		len += write(1, &symbols[n % base], 1);
	else
		len += write(1, &symbols[n % base], 1);
	return (len);
}
