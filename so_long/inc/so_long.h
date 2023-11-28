/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:18:56 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/28 10:05:33 by cedmulle         ###   ########.fr       */
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
# define EXIT_OK 'Z'
# define TRUE 1
# define FALSE 0
# define RATIO 1
# define KEY_ENTER 36
# define KEY_ESCAPE 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_S 1
# define KEY_W 13
# define KEY_A 0
# define KEY_D 2
# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define BOARD 200

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
	int		exit_x;
	int		exit_y;
	int		path_start[2];
	int		path_end[2];
	int		max_coin;
	int		coin;
	int		coin_collected;
	int		started;
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
	int		moves;
	int		finished;
	int		nb_killers;
	int		**tab_killers;
	void	*img_plup;
	void	*img_pldo;
	void	*img_plri;
	void	*img_plle;
	void	*img_kil1;
	void	*img_kil2;
	void	*img_kil3;
	void	*img_floo;
	void	*img_wall;
	void	*img_item;
	void	*img_exop;
	void	*img_excl;
	void	*img_boar;
	void	*img_swin;
	void	*img_lose;
	void	*img_load;
}				t_game;

int		parse_map(t_game *info);
int		ft_error(int error);
int		ft_free_info(t_game *info);
int		handle_keypress(int keycode, t_game *game);
void	launch_screen(t_game *game);
void	draw_map(t_game *game, char direction);
void	move_player(int keycode, t_game *game);
void	finish_game(t_game *game, int result);
char	*ft_itoa(int nb);
void	draw_move_board(t_game *game);
void	draw_coin_board(t_game *game);
void	draw_coin_board_max(t_game *game);
void	print_final_score(t_game *game);
void	create_tab_killers(t_game *game);
void	move_all_killers(t_game *game);
void	images_cleaner(t_game *game);
void	set_images(t_game *game);

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