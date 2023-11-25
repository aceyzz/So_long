/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:39:38 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/25 15:58:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_player(t_game *game, int i, int j)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./img/pl_right.xpm",
			&game->size, &game->size);
	game->addr = (int *)mlx_get_data_addr(game->img, &game->bpp, \
			&game->line_len, &game->endian);
	game->window_width = game->x * 100;
	game->window_height = game->y * 100;
	game->image_width = game->size;
	game->image_height = game->size;
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(j * 100), (i * 100));
}
