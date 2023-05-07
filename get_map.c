/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:18:33 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 21:26:22 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(int fd, t_lists *tam, int tam_line)
{
	char	**map;
	int		count;

	count = 0;
	map = malloc(sizeof(char *) * tam_line);
	if (!map)
		ft_error(0);
	map[count] = get_next_line(fd);
	if (map[count] == NULL)
	{
		close(fd);
		free(map);
		ft_error(4);
	}
	while (count < tam_line - 1)
	{
		count++;
		map[count] = get_next_line(fd);
		if (map[count] == NULL)
			free_map_2(tam_line, map, fd);
	}
	tam->row_tam = count;
	return (map);
}

void	free_map_2(int tam_line, char **map, int fd)
{
	int	row;

	row = 0;
	close(fd);
	while (row != tam_line - 2)
	{
		free(map[row]);
		row++;
	}
	free(map);
	ft_error(5);
}

char	**ft_map_copy(char **map, int tam_lines)
{
	char	**map_copy;
	int		count;

	count = 0;
	map_copy = malloc(sizeof(char *) * tam_lines);
	if (!map_copy)
		ft_error(0);
	while (tam_lines > count)
	{
		map_copy[count] = ft_strdup(map[count]);
		count++;
	}
	return (map_copy);
}
