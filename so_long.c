/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:59:24 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 20:49:49 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_so_long(char **map, t_lists *tam)
{
	ft_create_map(map, tam);
}

int	key_hook(int keycode, t_ptr *vars)
{
	if (keycode == ESC)
	{
		clean_memory(vars);
		exit(0);
	}
	move_sprites(vars, &(vars->tam), vars->map.map, keycode);
	return (0);
}

void	ft_create_map(char **map, t_lists *tam)
{
	t_ptr	str;
	int		t_c;
	int		t_r;

	str.tam = *tam;
	str.map.map = map;
	str.tam.count_game.count_collectable = 0;
	str.tam.count_game.count_moves = 0;
	t_c = tam->column_tam + 1;
	t_r = tam->row_tam + 1;
	str.ptr = mlx_init();
	str.win = mlx_new_window(str.ptr, (t_c * 75), (t_r * 75), "./so_long");
	ft_new_image(str.ptr, &str);
	ft_put_imagen(map, tam, &str);
	mlx_key_hook(str.win, key_hook, &str);
	mlx_hook(str.win, 17, 0L, red_cross, &str);
	mlx_loop(str.ptr);
}
