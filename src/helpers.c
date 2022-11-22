/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:38:30 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/22 13:53:09 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	put_uns_base(size_t n, int base, char fmt)
{
	const char	*symbols = "0123456789ABCDEF";
	char		tmp;
	int			len;

	len = 0;
	if (fmt == 'p')
	{
		if (++len && ++len && write(1, "0x", 2) == -1)
			return (-1);
		fmt = 'x';
	}
	if ((n / base) != 0)
	{
		len += put_uns_base(n / base, base, fmt);
		if (len == -1)
			return (-1);
	}
	if (fmt == 'x')
		tmp = ft_tolower(symbols[n % base]);
	else
		tmp = symbols[n % base];
	if (++len && write(1, &tmp, 1) == -1)
		return (-1);
	return (len);
}

int	put_sign_dec(int n, char fmt)
{
	size_t	num;
	int		len;
	int		tmp;

	len = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		num = n * -1;
		if (++len && write(1, "-", 1) == -1)
			return (-1);
	}
	else
		num = n;
	tmp = len;
	len += put_uns_base(num, 10, fmt);
	if (tmp > len)
		return (-1);
	return (len);
}

int	put_str_printf(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	put_chr_printf(char c)
{
	return (write(1, &c, 1));
}
