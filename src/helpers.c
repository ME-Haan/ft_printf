/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:38:30 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/12 14:25:32 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	put_uns_base(size_t n, int base, char fmt)
{
	const char	*symbols = "0123456789ABCDEF";
	int			len;
	char		tmp;

	len = 0;
	if (fmt == 'p')
	{
		len += write(1, "0x", 2);
		fmt = 'x';
	}
	if ((n / base) != 0)
		len += put_uns_base(n / base, base, fmt);
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

int	put_sign_dec(int n, char fmt)
{
	size_t	num;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		num = n * -1;
		len += write(1, "-", 1);
	}
	else
		num = n;
	len += put_uns_base(num, 10, fmt);
	return (len);
}

int	put_str_printf(va_list arg)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(arg, char *);
	if (!str)
		len += write(1, "(null)", 6);
	else
		len += write(1, str, ft_strlen(str));
	return (len);
}

int	put_chr_printf(va_list arg)
{
	int		len;
	char	c;

	len = 0;
	c = va_arg(arg, int);
	len += write(1, &c, 1);
	return (len);
}
