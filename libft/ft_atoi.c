/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 17:15:05 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/24 09:33:38 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_atoi(const char *str)
{
	int		val;
	int		sign;

	val = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && *str > 47 && *str < 58)
	{
		val = val * 10 + (*str - 48);
		str++;
	}
	return (val * sign);
}

// #include	<stdio.h>
// int	main (void)
// {
// 	char *str = 0;
// 	// printf("%i", ft_atoi(str));
// 	printf("%i", atoi(str));
// }