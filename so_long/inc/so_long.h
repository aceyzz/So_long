/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:18:56 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/21 18:39:18 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ------------------------------------------------------ Libraires standards */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../inc/get_next_line/get_next_line.h"
# include "../inc/ft_printf/ft_printf.h"
# include "../inc/MLX42/include/MLX42/MLX42.h"

typedef struct	s_player
{
	int	col;
	int	row;
}				t_player;

/* ------------------------------------------------------- Map prse (parse.c) */
char	**parse_map(int fd);
char	**get_map(char *filename);
/* -------------------------------------------------------- Errors (errors.c) */
int		is_valid_charac(char c);
int		is_valid_string(char **map);
int		is_size_ok(char **map);
int		is_valid_map(char **map);
int	is_chemin_exit(char **map, int x, int y, t_player *pl);
int	find_player(char **map, int x, int y, t_player *pl);
int		is_finishable(char **map);

#endif

// direction = {{1, 0}, {1, 0}, {0, -1}, {0, 1}};