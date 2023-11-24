/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:25:09 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/24 17:56:52 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* 
in the ./img/ directory :
P characters has the following images : p_up.xpm, p_down.xpm, p_left.xpm, p_right.xpm
C characters has the following images : coin.xpm
1 characters has the following images : wall.xpm
x characters has the following images : enemy.xpm
0 characters has the following images : floor.xpm
E characters has the following images : exit_open.xpm exit_closed.xpm
*/

int	handle_keypress(int keycode, t_game *game)
{
	/*if (keycode == KEY_ENTER)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_clear_window(game->mlx, game->win);
		// LA ON LANCE LE JEU 
	}*/
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_window(game->mlx, game->win);
		ft_free_info(game);
		exit(0);
	}
	return (0);
}

void	loading_screen(t_game *game)
{
	game->size = 100;
	if (game->x < game->y && game->x > 100)
		game->size = game->x;
	else if (game->y < game->x && game->y > 100)
		game->size = game->y;
	game->img = mlx_xpm_file_to_image(game->mlx, "./img/loading.xpm",
			&game->size, &game->size);
	game->addr = (int *)mlx_get_data_addr(game->img, &game->bpp, \
			&game->line_len, &game->endian);
	game->window_width = game->x * 100;
	game->window_height = game->y * 100;
	game->image_width = game->size;
	game->image_height = game->size;
	game->x_offset = (game->window_width - game->image_width) / 2;
	game->y_offset = (game->window_height - game->image_height) / 2;
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_offset, game->y_offset);
}

void	launch_screen(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->x * 100, game->y * 100,
			"SO_LONG - PACMAN");
	loading_screen(game);
	mlx_hook(game->win, KEY_PRESS_EVENT, 0, handle_keypress, game);
	mlx_loop(game->mlx);
}
