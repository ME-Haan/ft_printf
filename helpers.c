/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:38:30 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/05 14:46:59y mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"printf.h"
#include	<stdio.h>

void	ft_putnbr_base(unsigned int n, int base, char fmt)
{
	const char	*symbols = "0123456789ABCDEF";

	if (fmt == 'p')
	{
		ft_putstr_fd("0x", 1);
		fmt = 'x';
	}
	if ((n / base) != 0)
	{
		printf("\n%u", n);
		ft_putnbr_base(n / base, base, fmt);
	}
	if (fmt == 'x')
		ft_putchar_fd(ft_tolower(symbols[n % base]), 1);
	else if (fmt == 'X')
		ft_putchar_fd(symbols[n % base], 1);
}

int	num_len_base(unsigned int n, int base)
{
	size_t			numlen;

	numlen = 1;
	while (n / base)
	{
		numlen++;
		n /= base;
	}
	return (numlen);
}
