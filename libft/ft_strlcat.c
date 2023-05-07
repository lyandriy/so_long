/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:26:04 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/22 16:07:07 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c_d;
	size_t	c_s;
	size_t	k;

	if (!dst && !dstsize)
		return (0);
	k = 0;
	c_d = ft_strlen(dst);
	c_s = ft_strlen(src);
	while (src[k] && (c_d + k) < dstsize - 1 && (dstsize != 0))
	{
		dst[c_d + k] = src[k];
		k++;
	}
	dst[c_d + k] = '\0';
	if (dstsize < c_d)
		return (dstsize + c_s);
	return (c_d + c_s);
}
