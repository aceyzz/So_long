/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:18:56 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 12:09:02 by cedmulle         ###   ########.fr       */
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
/* ************************************************************************** */
/*                          Gestion d'erreurs                                 */
/* ************************************************************************** */
/* -------------------------------------------------------- Errors (errors.c) */
int		is_valid_map(char **map);
/* ------------------------------------------ Errors (error_map_finishable.c) */
void	set_tab_direction(int tab[4][2]);
int		is_chemin_exit(char **map, int x, int y, t_player *pl);
int		find_player(char **map, int x, int y, t_player *pl);
int		is_finishable(char **map);
/* --------------------------------------------- Errors (error_map_borders.c) */
int		is_wall_valid(char **map);
/* ----------------------------------------------- Errors (error_item_exit.c) */
int		is_chemin_item(char **map, int x, int y, t_player *pl);
int		is_path_items(char **map, int nb_item);
int		is_item_exit(char **map);
/* ************************************************************************** */
/*                                 Utils                                      */
/* ************************************************************************** */
void	*ft_realloc(void *ptr, size_t size);

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