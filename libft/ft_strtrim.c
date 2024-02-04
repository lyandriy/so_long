/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:04:47 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/01 16:43:26 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	k = ft_strlen(s1);
	if (!set)
		return ((char *) s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (k > i && ft_strchr(set, s1[k]))
		k--;
	ptr = malloc ((k - i) + 2 * sizeof (char));
	if (!ptr)
		return (NULL);
	while (i <= k)
		ptr[j++] = s1[i++];
	ptr[j] = '\0';
	return (ptr);
}
