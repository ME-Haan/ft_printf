/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:43:13 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/24 15:19:33 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1 = s1;
	const unsigned char	*src2 = s2;
	size_t				i;

	i = 0;
	while (i++ < n)
	{
		if (src1[i - 1] != src2[i - 1])
			return (src1[i - 1] - src2[i - 1]);
	}
	return (0);
}
