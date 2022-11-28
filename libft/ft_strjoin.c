/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 11:18:01 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/24 15:20:12 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1len = ft_strlen(s1);
	const size_t	s2len = ft_strlen(s2);
	char			*mem;

	mem = (char *)malloc(s1len + s2len + 1 * sizeof(char));
	if (!mem)
		return (0);
	ft_memcpy(mem, s1, s1len);
	ft_memcpy(mem + s1len, s2, s2len + 1);
	return (mem);
}
