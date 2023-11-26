/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:18:56 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/26 14:51:45 by cedmulle         ###   ########.fr       */
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
# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define BOARD 200

typedef struct s_game
{
	int		fd; // file descriptor
	char	**map; // map originale
	char	**map_copy; // pour trouver path valide
	char	*name_map; // nom du fichier
	int		x; // largeur de la map
	int		y; // hauteur de la map
	int		pl_x; // position du joueur
	int		pl_y; // position du joueur
	int		exit_x; // position de la sortie
	int		exit_y; // position de la sortie
	int		path_start[2]; 
	int		path_end[2];
	int		max_coin; // nombre d'items
	int		coin; // nombre d'items pour check
	int		coin_collected; // nombre d'items collectés
	int		started; // 0 si le jeu n'a pas commencé, 1 sinon
	void	*mlx; // mlx: pointeur sur la connexion avec le serveur graphique
	void	*win; // fenetre
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
	int		x_offset; // pour trouver le centre de l'image
	int		y_offset; // pour trouver le centre de l'image
	int		moves;
	int		finished;
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