/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:51:53 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 21:46:14 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_ptr *vars)
{
	clean_memory(vars);
	exit(0);
}

void	move_sprites(t_ptr *vars, t_lists *tam, char **map, int keycode)
{
	char	*ptr_itoa;

	map[tam->p_row][tam->p_column] = '0';
	if (check_keycode(keycode, vars) == 1)
	{
		tam->count_game.count_moves += 1;
		ptr_itoa = ft_itoa(tam->count_game.count_moves);
		mlx_put_image_to_window(vars->ptr, vars->win, vars->fptr[1], 0, 0);
		mlx_string_put(vars->ptr, vars->win, 25, 25, 0x00FF0066, ptr_itoa);
		free(ptr_itoa);
		if (map[tam->p_row][tam->p_column] == 'C')
			vars->tam.count_game.count_collectable += 1;
		if (map[tam->p_row][tam->p_column] == 'E' &&
			tam->count_game.count_collectable == tam->char_c)
		{
			clean_memory(vars);
			exit(0);
		}
		if (map[tam->p_row][tam->p_column] == 'X')
			game_over(vars);
		map[tam->p_row][tam->p_column] = 'P';
		mlx_put_image_to_window(vars->ptr, vars->win,
			vars->fptr[4], vars->tam.p_column * 75, vars->tam.p_row * 75);
	}
}

int	check_keycode(int keycode, t_ptr *vars)
{
	int	row;
	int	column;

	row = vars->tam.p_row;
	column = vars->tam.p_column;
	if (keycode == A || keycode == LEFT)
		column -= 1;
	if (keycode == D || keycode == RIGHT)
		column += 1;
	if (keycode == S || keycode == DOWN)
		row += 1;
	if (keycode == W || keycode == UP)
		row -= 1;
	if (vars->map.map[row][column] == 'E' &&
		vars->tam.count_game.count_collectable != vars->tam.char_c)
		return (0);
	if (vars->map.map[row][column] != '1')
	{
		mlx_put_image_to_window(vars->ptr, vars->win, vars->fptr[0],
			vars->tam.p_column * 75, vars->tam.p_row * 75);
		vars->tam.p_row = row;
		vars->tam.p_column = column;
		return (1);
	}
	return (0);
}

int	render_next_frame(t_ptr *vars)
{
	int			i;
	int			j;
	static int	estatica = 5000;

	if (estatica == 14000)
		estatica = 5000;
	i = vars->tam.p_column;
	j = vars->tam.p_row;
	if (estatica == 5000)
		mlx_put_image_to_window(vars->ptr, vars->win,
			vars->fptr[4], i * 75, j * 75);
	else if (estatica == 8000)
		mlx_put_image_to_window(vars->ptr, vars->win,
			vars->fptr[5], i * 75, j * 75);
	else if (estatica == 11000)
		mlx_put_image_to_window(vars->ptr, vars->win,
			vars->fptr[6], i * 75, j * 75);
	else if (estatica == 14000)
		mlx_put_image_to_window(vars->ptr, vars->win,
			vars->fptr[7], i * 75, j * 75);
	estatica++;
	return (1);
}
