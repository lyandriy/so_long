/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:00:32 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/01 16:26:37 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	int				result;

	i = 0;
	s1_cpy = (unsigned char *) s1;
	s2_cpy = (unsigned char *) s2;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
		{
			result = s1_cpy[i] - s2_cpy[i];
			return (result);
		}
		i++;
	}
	return (0);
}
