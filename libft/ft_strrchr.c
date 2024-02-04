/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:29:47 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/01 20:14:09 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	*i;

	i = (char *)s;
	j = ft_strlen(s);
	while (j >= 0)
	{
		if (i[j] == (unsigned char) c)
			return (&i[j]);
		j--;
	}
	return (NULL);
}
