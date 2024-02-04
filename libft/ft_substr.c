/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:04:50 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/02 16:37:21 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
	{
		ptr = ft_calloc(1, 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (len > j)
		len = j - start;
	ptr = ft_calloc (sizeof (char), len + 1);
	if (!ptr)
		return (NULL);
	if (len == 0)
		return (ptr);
	ptr = ft_memcpy(ptr, &s[start], len);
	return (ptr);
}
