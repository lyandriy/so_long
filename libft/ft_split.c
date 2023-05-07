/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:04:18 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/02 14:41:23 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	if (src == 0 || dst == 0)
		return (0);
	while (i < n)
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_count(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void	**ft_free(char **ptr, int j)
{
	if (j == 0)
	{
		free(ptr);
		return (NULL);
	}
	while (j > -1)
	{
		free(ptr[j]);
		j--;
	}
	free(ptr);
	return (NULL);
}

static char	**ft_split_0(char **ptr, const char *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count = ft_count(&s[i], c);
			ptr[j] = malloc ((count + 1) * sizeof (char));
			if (!ptr[j])
				return ((char **)ft_free(ptr, j - 1));
			ptr[j] = ft_cpy(ptr[j], &s[i], count);
			i = i + count;
			j++;
		}
	}
	ptr[j] = (NULL);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		count;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count = ft_count(&s[i], c);
			i = i + count;
			k++;
		}
	}
	ptr = (char **) malloc((k + 1) * sizeof (char *));
	if (!ptr)
		return (NULL);
	ft_split_0(ptr, s, c);
	return (ptr);
}
