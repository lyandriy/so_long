/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:05:10 by lyandriy          #+#    #+#             */
/*   Updated: 2023/01/15 18:48:54 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	f_strlen(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return (0);
	while (s[j] != '\0')
		j++;
	return (j);
}

char	*f_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = f_strlen(s1) + f_strlen(s2);
	ptr = malloc ((i + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	if (s1)
	{
		while (s1[j] != '\0')
		{
			ptr[j] = s1[j];
			j++;
		}
	}
	i = 0;
	while (s2[i] != '\0')
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	free(s1);
	return (ptr);
}

int	f_strchr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
