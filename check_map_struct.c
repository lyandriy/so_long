/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:25:23 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 16:24:17 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_struct(char **map, t_lists *tam)
{
	int	p_row;
	int	p_column;

	p_row = tam->p_row;
	p_column = tam->p_column;
	if (!check_walls(map, tam))
		return (0);
	check_exit(map, p_row, p_column);
	if (!check_result(map, tam->row_tam, tam->column_tam))
		return (0);
	map[tam->e_row][tam->e_column] = 'E';
	check_exit_is_valid(map, p_row, p_column);
	if (!check_result_e(map, tam->row_tam, tam->column_tam))
		return (0);
	return (1);
}

void	check_exit_is_valid(char **map, int p_row, int p_column)
{
	if (map[p_row][p_column] == '1' || map[p_row][p_column] == 'X'
		|| map[p_row][p_column] == 'E' || map[p_row][p_column] == '-')
		return ;
	map[p_row][p_column] = '-';
	check_exit_is_valid(map, p_row + 1, p_column);
	check_exit_is_valid(map, p_row - 1, p_column);
	check_exit_is_valid(map, p_row, p_column + 1);
	check_exit_is_valid(map, p_row, p_column - 1);
}

void	check_exit(char **map, int p_row, int p_column)
{
	if (map[p_row][p_column] == '1' || map[p_row][p_column] == '.'
		|| map[p_row][p_column] == 'X')
		return ;
	map[p_row][p_column] = '.';
	check_exit(map, p_row + 1, p_column);
	check_exit(map, p_row - 1, p_column);
	check_exit(map, p_row, p_column + 1);
	check_exit(map, p_row, p_column - 1);
}

int	check_walls(char **map, t_lists *tam)
{
	int	tam_row;
	int	tam_column;

	tam_row = tam->row_tam;
	tam_column = tam->column_tam;
	while (tam_column > -1)
	{
		if (map[0][tam_column] != '1' || map[tam_row][tam_column] != '1')
			return (0);
		tam_column--;
	}
	tam_column = tam->column_tam;
	while (tam_row > -1)
	{
		if (map[tam_row][0] != '1' || map[tam_row][tam_column] != '1')
			return (0);
		tam_row--;
	}
	return (1);
}

int	check_result(char **map, int row_tam, int column_tam)
{
	int		save_tam;
	char	*ret_strchr;

	save_tam = column_tam;
	while (row_tam != -1)
	{
		column_tam = save_tam;
		while (column_tam != -1)
		{
			ret_strchr = ft_strchr("CPE", map[row_tam][column_tam]);
			if (ret_strchr)
				return (0);
			column_tam--;
		}
		row_tam--;
	}
	return (1);
}
