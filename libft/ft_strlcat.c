/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 10:26:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/24 15:20:18 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	srclen = ft_strlen(src);
	const size_t	dstlen = ft_strlen(dst);
	size_t			i;

	if (dstlen >= dstsize)
		return (dstsize + srclen);
	i = 0;
	while (i < srclen && i < (dstsize - dstlen - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	return (dst[dstlen + i] = '\0', dstlen + srclen);
}
