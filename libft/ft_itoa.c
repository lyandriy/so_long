/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:01:41 by lyandriy          #+#    #+#             */
/*   Updated: 2022/10/02 14:53:40 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cero(void)
{
	int		i;
	char	*ptr;

	i = 2;
	ptr = malloc (i * sizeof (char));
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

static int	ft_tam(int *neg, long int j)
{
	int	i;

	i = 0;
	if (j < 0)
	{
		*neg = -1;
		j *= -1;
		i++;
	}
	while (j > 0)
	{
		i++;
		j /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	long int	j;
	int			neg;

	neg = 1;
	i = 0;
	j = (long int) n;
	if (n == 0)
		return (ft_cero());
	i = ft_tam(&neg, j);
	ptr = malloc ((i + 1) * sizeof (char));
	if (!ptr)
		return (NULL);
	if (neg < 0)
		ptr[0] = '-';
	ptr[i] = '\0';
	j = (long int) n * neg;
	while (j > 0)
	{
		i--;
		ptr[i] = (j % 10) + 48;
		j = j / 10;
	}
	return (ptr);
}
