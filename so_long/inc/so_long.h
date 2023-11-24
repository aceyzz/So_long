/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:18:56 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/24 17:56:51 by cedmulle         ###   ########.fr       */
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
# include "../inc/mlx/mlx.h"

/* ------------------------------------------------------- Variables globales */
# define PLAYER 'P'
# define ITEM 'C'
# define KILLER 'x'
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define TRUE 1
# define FALSE 0
# define RATIO 1
# define KEY_ENTER 36
# define KEY_ESCAPE 53
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3

typedef struct s_game
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
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		size;
	int		window_width;
	int		window_height;
	int		image_width;
	int		image_height;
	int		x_offset;
	int		y_offset;
	void	*player_img;
	void	*floor_img;
	void	*wall_img;
	void	*enemy_img;
	void	*exit_img;
	void	*collectible_img;
}				t_game;


int		parse_map(t_game *info);
int		ft_error(int error);
int		ft_free_info(t_game *info);
void	loading_screen(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	launch_screen(t_game *game);

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