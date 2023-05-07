/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:24:27 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 21:32:53 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <unistd.h>
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

# define W	13
# define S	1
# define A	0
# define D	2
# define ESC	53
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP	126
# define ESC	53

typedef struct s_moves
{
	int	count_moves;
	int	count_collectable;
}		t_moves;

typedef struct s_lists
{
	int			char_c;
	int			char_e;
	int			char_p;
	int			char_x;
	int			column_tam;
	int			row_tam;
	int			p_row;
	int			p_column;
	int			e_row;
	int			e_column;
	t_moves		count_game;
}		t_lists;

typedef struct s_mapa
{
	char	**map;
}			t_mapa;

typedef struct s_ptr
{
	void	**fptr;
	void	*ptr;
	void	*win;
	t_lists	tam;
	t_mapa	map;
}			t_ptr;

int		main(int argc, char **argv);
void	ft_error(int error);
int		ft_check_ber(char *file);
int		ft_read_file(char *file);
char	**get_map(int fd, t_lists *tam, int tam_line);
char	**ft_map_copy(char **map, int tam_lines);
int		check_map(char **map, t_lists *tam);
int		check_length_lines(char **map, t_lists *tam);
int		check_stranger_char(char **map, int row_tam, int col_tam);
int		check_c_e_p(char **map, t_lists *tam);
void	count_chars(char map, int row_tam, int col_tam, t_lists *tam);
int		check_map_struct(char **map, t_lists *tam);
int		check_walls(char **map, t_lists *tam);
void	check_exit(char **map, int p_row, int p_column);
int		check_result(char **map, int row_tam, int column_tam);
void	ft_so_long(char **map, t_lists *tam);
void	ft_create_map(char **map, t_lists *tam);
void	ft_new_image(void *mlx, t_ptr	*str);
void	ft_put_imagen(char **map, t_lists *tam, t_ptr *str);
void	put_imgs(t_ptr *s, int i, int j, char **map);
int		key_hook(int keycode, t_ptr *vars);
void	move_sprites(t_ptr *vars, t_lists *tam, char **map, int keycode);
void	game_over(t_ptr *vars);
int		render_next_frame(t_ptr *vars);
void	clean_memory(t_ptr *vars);
int		check_keycode(int keycode, t_ptr *vars);
int		red_cross(t_ptr *vars);
int		check_result_e(char **map, int row_tam, int column_tam);
void	check_exit_is_valid(char **map, int p_row, int p_column);
void	free_map(t_lists *tam, char **map);
void	free_img(t_ptr *vars);
int		count_line_feed(char *chars, int fd);
void	free_map_2(int tam_line, char **map, int fd);
void	print_error(int error);

#endif