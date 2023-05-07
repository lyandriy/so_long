/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:30:53 by lyandriy          #+#    #+#             */
/*   Updated: 2023/01/22 16:41:13 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*f_memcpy(char *txt);
char	*f_cpy(char *txt);
char	*get_txt(int fd, char *txt);
char	*get_next_line(int fd);
int		f_strlen(char *s);
int		f_strchr(char *s);
int		f_strlen(char *s);
char	*f_strjoin(char *s1, char *s2);

#endif