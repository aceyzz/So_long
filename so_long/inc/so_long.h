/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:18:56 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 18:00:23 by cedmulle         ###   ########.fr       */
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

typedef struct	s_info
{
	int		size_x;
	int		size_y;
	int		pl_x;
	int		pl_y;
	int		nb_coin;
	int		copy_coin;
	int		nb_exit;
	char	**map_copy;
}				t_info;

/* ------------------------------------------------------- Map prse (parse.c) */
char	**parse_map(int fd);
char	**get_map(char *filename);
/* ************************************************************************** */
/*                          Gestion d'erreurs                                 */
/* ************************************************************************** */
/* -------------------------------------------------------- Errors (errors.c) */
int		is_valid_map(t_info *info);
/* --------------------------------------------- Errors (error_map_borders.c) */
int		is_wall_valid(t_info *info);
/* ----------------------------------------------- Errors (error_item_exit.c) */
int		is_item_exit(t_info *info);
/* ************************************************************************** */
/*                                 Utils                                      */
/* ************************************************************************** */
void	*ft_realloc(void *ptr, size_t size);
char	*ft_strdup(const char *s1);

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