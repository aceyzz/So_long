/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:25:09 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/26 19:52:11 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ending_screen(t_game *game, int result)
{
	game->size = 100;
	if (game->x < game->y && game->x > 100)
		game->size = game->x;
	else if (game->y < game->x && game->y > 100)
		game->size = game->y;
	if (result == 0)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/win.xpm",
				&game->size, &game->size);
	else
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/lose.xpm",
				&game->size, &game->size);
	game->window_width = game->x * 100;
	game->window_height = game->y * 100;
	game->image_width = game->size;
	game->image_height = game->size;
	game->x_offset = ((game->window_width + BOARD) - game->image_width) / 2;
	game->y_offset = (game->window_height - game->image_height) / 2;
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_offset, game->y_offset);
	print_final_score(game);
}

static void	loading_screen(t_game *game)
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
	game->x_offset = ((game->window_width + BOARD) - game->image_width) / 2;
	game->y_offset = (game->window_height - game->image_height) / 2;
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_offset, game->y_offset);
}

void	finish_game(t_game *game, int result)
{
	game->finished = 1;
	mlx_destroy_image(game->mlx, game->img);
	mlx_clear_window(game->mlx, game->win);
	ending_screen(game, result);
	mlx_hook(game->win, KEY_PRESS_EVENT, 0, handle_keypress, game);
	mlx_loop(game->mlx);
}

void	launch_screen(t_game *game)
{
	game->started = 0;
	game->finished = 0;
	game->moves = 0;
	game->coin_collected = 0;
	create_tab_killers(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->x * 100) + BOARD,
			game->y * 100, "SO_LONG - PACMAN by cedmulle");
	loading_screen(game);
	mlx_hook(game->win, KEY_PRESS_EVENT, 0, handle_keypress, game);
	mlx_mouse_hide();
	mlx_loop(game->mlx);
}
