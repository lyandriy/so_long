/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:06:49 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/02 15:42:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*a;

	if (src == 0 && dst == 0)
		return (0);
	a = (char *)dst;
	i = 0;
	while (i < n)
	{
		a[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
