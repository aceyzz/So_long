/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:33:37 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/25 16:11:12 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	draw_exit(t_game *game, int i, int j)
{
	if (game->coin_collected == game->max_coin)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/exit_open.xpm",
			&game->size, &game->size);
	else
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/exit_closed.xpm",
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

static void	draw_item(t_game *game, int i, int j)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm",
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

static void	draw_floor(t_game *game, int i, int j)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm",
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

static void	draw_wall(t_game *game, int i, int j)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm",
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

void	draw_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == WALL)
				draw_wall(game, i, j);
			else if (game->map[i][j] == FLOOR)
				draw_floor(game, i, j);
			else if (game->map[i][j] == KILLER)
				draw_killer(game, i, j , (i + j) % 3);
			else if (game->map[i][j] == EXIT)
				draw_exit(game, i, j);
			else if (game->map[i][j] == ITEM)
				draw_item(game, i, j);
			else if (game->map[i][j] == PLAYER)
				draw_player(game, i, j);
			j++;
		}
		i++;
	}
}
