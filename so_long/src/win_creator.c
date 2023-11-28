/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:25:09 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/28 11:44:19 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ending_screen(t_game *game, int result)
{
	if (result == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img_swin,
			game->x_offset, game->y_offset);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_lose,
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
	game->window_width = game->x * 100 + BOARD;
	game->window_height = game->y * 100;
	game->image_width = 500;
	game->image_height = 500;
	game->x_offset = (game->window_width - game->image_width) / 2;
	game->y_offset = (game->window_height - game->image_height) / 2;
	mlx_put_image_to_window(game->mlx, game->win, game->img_load,
		game->x_offset, game->y_offset);
}

void	finish_game(t_game *game, int result)
{
	game->finished = 1;
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
	set_images(game);
	loading_screen(game);
	mlx_hook(game->win, KEY_PRESS_EVENT, 0, handle_keypress, game);
	mlx_mouse_hide();
	mlx_loop(game->mlx);
}
