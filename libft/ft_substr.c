/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 14:06:04 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/24 15:20:42 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	mem = (char *)malloc((len + 1) * sizeof(char));
	if (!mem)
		return (0);
	ft_strlcpy(mem, s + start, len + 1);
	return (mem);
}
