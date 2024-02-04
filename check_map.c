/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:23:21 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 20:51:01 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map, t_lists *tam)
{
	tam->column_tam = check_length_lines(map, tam);
	if (tam->column_tam < 0)
		return (0);
	if (!check_stranger_char(map, tam->column_tam, tam->row_tam))
		return (0);
	if (!check_c_e_p(map, tam))
		return (0);
	if (!check_map_struct(map, tam))
		return (0);
	return (1);
}

int	check_length_lines(char **map, t_lists *tam)
{
	int	row_tam;
	int	column_tam;
	int	column_tam_compare;

	row_tam = tam->row_tam;
	column_tam_compare = ft_strlen(map[row_tam]) + 1;
	while (row_tam != 0)
	{
		row_tam--;
		column_tam = ft_strlen(map[row_tam]);
		if (column_tam_compare != column_tam)
			return (0);
	}
	return (column_tam - 2);
}

int	check_stranger_char(char **map, int col_tam, int row_tam)
{
	int		save_tam;
	char	*ret_strchr;

	save_tam = col_tam;
	while (row_tam != -1)
	{
		col_tam = save_tam;
		while (col_tam != -1)
		{
			ret_strchr = ft_strchr("01CPE\n", map[row_tam][col_tam]);
			if (map[row_tam][col_tam] == 'X')
				ret_strchr = "X";
			if (ret_strchr == NULL)
				return (0);
			col_tam--;
		}
		row_tam--;
	}
	return (1);
}

int	check_c_e_p(char **map, t_lists *tam)
{
	int	row_tam;
	int	col_tam;

	tam->char_c = 0;
	tam->char_e = 0;
	tam->char_p = 0;
	tam->char_x = 0;
	tam->e_row = 0;
	tam->e_column = 0;
	row_tam = tam->row_tam;
	while (row_tam != -1)
	{
		col_tam = tam->column_tam;
		while (col_tam != -1)
		{
			count_chars(map[row_tam][col_tam], row_tam, col_tam, tam);
			col_tam--;
		}
		row_tam--;
	}
	if (tam->char_p != 1 || tam->char_c < 1 || tam->char_e != 1)
		return (0);
	return (1);
}

void	count_chars(char map, int row_tam, int col_tam, t_lists *tam)
{
	if (map == 'X')
		tam->char_x++;
	if (map == 'C')
		tam->char_c++;
	if (map == 'E')
	{
		tam->e_row = row_tam;
		tam->e_column = col_tam;
		tam->char_e++;
	}
	if (map == 'P')
	{
		tam->p_row = row_tam;
		tam->p_column = col_tam;
		tam->char_p++;
	}
}
