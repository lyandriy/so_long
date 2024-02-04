/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:37:19 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/02 14:41:40 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	i = 0;
	s_cpy = (unsigned char *) s;
	while (i != n)
	{
		if (s_cpy[i] == (unsigned char) c)
			return ((unsigned char *) &s_cpy[i]);
		i++;
	}
	return (NULL);
}
