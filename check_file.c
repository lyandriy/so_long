/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:55:21 by lyandriy          #+#    #+#             */
/*   Updated: 2023/02/18 21:24:08 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *file)
{
	int	count;
	int	count_chars;

	count = 0;
	count_chars = 0;
	if (ft_strlen(file) < 5)
		return (0);
	while (file[count + 4] != '\0')
		count++;
	if (strncmp(&file[count], ".ber", 4) != 0)
		return (0);
	return (1);
}

int	ft_read_file(char *file)
{
	int		fd;
	int		lineas;
	char	*chars;

	chars = malloc(sizeof(char *) * 1);
	if (!chars)
		ft_error(0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(chars);
		ft_error(3);
	}
	lineas = count_line_feed(chars, fd);
	close(fd);
	free(chars);
	return (lineas + 1);
}

int	count_line_feed(char *chars, int fd)
{
	int	pos;
	int	lineas;

	pos = 1;
	lineas = 0;
	while (pos != 0)
	{
		pos = read(fd, chars, 1);
		if (pos == -1)
		{
			free(chars);
			ft_error(3);
		}
		if (chars[0] == '\n')
			lineas++;
	}
	return (lineas);
}
