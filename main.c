/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:16:01 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 21:32:22 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		tam_lines;
	t_lists	tam;
	char	**map;
	char	**map_copy;

	if (argc != 2)
		ft_error(1);
	if (!ft_check_ber(argv[1]))
		ft_error(2);
	tam_lines = ft_read_file(argv[1]);
	fd = open(argv[1], O_RDONLY);
	map = get_map(fd, &tam, tam_lines);
	map_copy = ft_map_copy(map, tam_lines);
	close(fd);
	if (!check_map(map_copy, &tam))
	{
		free_map(&tam, map);
		free_map(&tam, map_copy);
		ft_error(5);
	}
	ft_so_long(map, &tam);
	return (0);
}
