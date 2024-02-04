/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:17:52 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 20:38:19 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_memory(t_ptr *vars)
{
	free_img(vars);
	free_map(&vars->tam, vars->map.map);
	mlx_destroy_window(vars->ptr, vars->win);
}

void	free_map(t_lists *tam, char **map)
{
	int	row;

	row = 0;
	while (row != tam->row_tam + 1)
	{
		free(map[row]);
		row++;
	}
	free(map);
}

void	free_img(t_ptr *vars)
{
	int	count;

	count = 0;
	while (count < 9)
	{
		if (vars->fptr[count] != NULL)
			mlx_destroy_image(vars->ptr, vars->fptr[count]);
		count++;
	}
	free(vars->fptr);
}

int	red_cross(t_ptr *vars)
{
	clean_memory(vars);
	exit(0);
	return (0);
}
