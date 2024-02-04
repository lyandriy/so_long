/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:58 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 22:18:52 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int error)
{
	write(1, "Error: ", 7);
	print_error(error);
	exit(0);
}

void	print_error(int error)
{
	if (error == 1)
		write (1, "Invalid arguments\n", 18);
	if (error == 2)
		write (1, "Invalid map extent\n", 19);
	if (error == 3)
		write (1, "Invalid archive\n", 16);
	if (error == 4)
		write (1, "Empty file\n", 10);
	if (error == 5)
		write (1, "Invalid map\n", 12);
	if (error == 6)
		write (1, "Invalid xpm\n", 12);
}

int	check_result_e(char **map, int row_tam, int column_tam)
{
	int		save_tam;
	char	*ret_strchr;

	save_tam = column_tam;
	while (row_tam != -1)
	{
		column_tam = save_tam;
		while (column_tam != -1)
		{
			ret_strchr = ft_strchr("CP.", map[row_tam][column_tam]);
			if (ret_strchr)
				return (0);
			column_tam--;
		}
		row_tam--;
	}
	return (1);
}
