/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:34:17 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 21:32:25 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_image(void *mlx, t_ptr *str)
{
	int	width;
	int	heigh;
	int	count;

	count = 0;
	str->fptr = malloc (sizeof(void *) * 9);
	str->fptr[0] = mlx_xpm_file_to_image (mlx, "./xpm/0.xpm", &width, &heigh);
	str->fptr[1] = mlx_xpm_file_to_image (mlx, "./xpm/1.xpm", &width, &heigh);
	str->fptr[2] = mlx_xpm_file_to_image (mlx, "./xpm/C.xpm", &width, &heigh);
	str->fptr[3] = mlx_xpm_file_to_image (mlx, "./xpm/E.xpm", &width, &heigh);
	str->fptr[4] = mlx_xpm_file_to_image (mlx, "./xpm/P.xpm", &width, &heigh);
	str->fptr[5] = mlx_xpm_file_to_image (mlx, "./xpm/P1.xpm", &width, &heigh);
	str->fptr[6] = mlx_xpm_file_to_image (mlx, "./xpm/P2.xpm", &width, &heigh);
	str->fptr[7] = mlx_xpm_file_to_image (mlx, "./xpm/P3.xpm", &width, &heigh);
	str->fptr[8] = mlx_xpm_file_to_image (mlx, "./xpm/X.xpm", &width, &heigh);
	while (count < 9)
	{
		if (str->fptr[count] == NULL)
		{
			clean_memory(str);
			ft_error(6);
		}
		count++;
	}
}

void	ft_put_imagen(char **map, t_lists *tam, t_ptr *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= tam->row_tam)
	{
		while (i <= tam->column_tam)
		{
			put_imgs(str, i, j, map);
			i++;
		}
		i = 0;
		j++;
	}
}

void	put_imgs(t_ptr *s, int i, int j, char **map)
{
	if (map[j][i] == '0')
		mlx_put_image_to_window(s->ptr, s->win, s->fptr[0], i * 75, j * 75);
	if (map[j][i] == '1')
		mlx_put_image_to_window(s->ptr, s->win, s->fptr[1], i * 75, j * 75);
	if (map[j][i] == 'C')
		mlx_put_image_to_window(s->ptr, s->win, s->fptr[2], i * 75, j * 75);
	if (map[j][i] == 'E')
		mlx_put_image_to_window(s->ptr, s->win, s->fptr[3], i * 75, j * 75);
	if (map[j][i] == 'P')
	{
		mlx_put_image_to_window(s->ptr, s->win, s->fptr[4], i * 75, j * 75);
		mlx_loop_hook(s->ptr, render_next_frame, s);
	}
	if (map[j][i] == 'X')
		mlx_put_image_to_window(s->ptr, s->win, s->fptr[8], i * 75, j * 75);
}
