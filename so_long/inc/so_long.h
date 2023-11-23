/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:18:56 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/23 14:19:09 by cedmulle         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
//# include "../inc/MLX42/include/MLX42/MLX42.h"

typedef struct	s_game
{
	int		fd;
	char	**map;
	char	**map_copy;
	char	*name_map;
	int		x;
	int		y;
	int		pl_x;
	int		pl_y;
	int		path_start[2];
	int		path_end[2];
	int		max_coin;
	int		coin;
}				t_game;

int		parse_map(t_game *info);
int		ft_error(int error);
int		ft_free_info(t_game *info);

#endif

/* Ft autorisees 
open
close
read
write,
malloc
free
perror,
strerror
exit
math.h (TOUTES)
Fonctions de la MiniLibX
ft_printf
*/