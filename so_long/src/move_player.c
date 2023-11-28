/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:55:42 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/28 10:08:20 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_up(t_game *game)
{
	if (game->map[game->path_start[0] - 1][game->path_start[1]] != WALL
		&& game->map[game->path_start[0] - 1][game->path_start[1]] != EXIT)
	{
		if (game->map[game->path_start[0] - 1][game->path_start[1]] == ITEM)
			game->coin_collected++;
		if (game->coin_collected == game->max_coin)
			game->map[game->path_end[0]][game->path_end[1]] = EXIT_OK;
		if (game->map[game->path_start[0] - 1][game->path_start[1]] == EXIT_OK)
			finish_game(game, 0);
		if (game->map[game->path_start[0] - 1][game->path_start[1]] == KILLER)
			finish_game(game, 1);
		ft_printf("Moves:\t%d\n", ++game->moves);
		game->map[game->path_start[0] - 1][game->path_start[1]] = PLAYER;
		game->map[game->path_start[0]][game->path_start[1]] = FLOOR;
		game->path_start[0]--;
	}
	move_all_killers(game);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game, 'U');
}

static void	move_down(t_game *game)
{
	if (game->map[game->path_start[0] + 1][game->path_start[1]] != WALL
		&& game->map[game->path_start[0] + 1][game->path_start[1]] != EXIT)
	{
		if (game->map[game->path_start[0] + 1][game->path_start[1]] == ITEM)
			game->coin_collected++;
		if (game->coin_collected == game->max_coin)
			game->map[game->path_end[0]][game->path_end[1]] = EXIT_OK;
		if (game->map[game->path_start[0] + 1][game->path_start[1]] == EXIT_OK)
			finish_game(game, 0);
		if (game->map[game->path_start[0] + 1][game->path_start[1]] == KILLER)
			finish_game(game, 1);
		ft_printf("Moves:\t%d\n", ++game->moves);
		game->map[game->path_start[0] + 1][game->path_start[1]] = PLAYER;
		game->map[game->path_start[0]][game->path_start[1]] = FLOOR;
		game->path_start[0]++;
	}
	move_all_killers(game);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game, 'D');
}

static void	move_right(t_game *game)
{
	if (game->map[game->path_start[0]][game->path_start[1] + 1] != WALL
		&& game->map[game->path_start[0]][game->path_start[1] + 1] != EXIT)
	{
		if (game->map[game->path_start[0]][game->path_start[1] + 1] == ITEM)
			game->coin_collected++;
		if (game->coin_collected == game->max_coin)
			game->map[game->path_end[0]][game->path_end[1]] = EXIT_OK;
		if (game->map[game->path_start[0]][game->path_start[1] + 1] == EXIT_OK)
			finish_game(game, 0);
		if (game->map[game->path_start[0]][game->path_start[1] + 1] == KILLER)
			finish_game(game, 1);
		ft_printf("Moves:\t%d\n", ++game->moves);
		game->map[game->path_start[0]][game->path_start[1] + 1] = PLAYER;
		game->map[game->path_start[0]][game->path_start[1]] = FLOOR;
		game->path_start[1]++;
	}
	move_all_killers(game);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game, 'R');
}

static void	move_left(t_game *game)
{
	if (game->map[game->path_start[0]][game->path_start[1] - 1] != WALL
		&& game->map[game->path_start[0]][game->path_start[1] - 1] != EXIT)
	{
		if (game->map[game->path_start[0]][game->path_start[1] - 1] == ITEM)
			game->coin_collected++;
		if (game->coin_collected == game->max_coin)
			game->map[game->path_end[0]][game->path_end[1]] = EXIT_OK;
		if (game->map[game->path_start[0]][game->path_start[1] - 1] == EXIT_OK)
			finish_game(game, 0);
		if (game->map[game->path_start[0]][game->path_start[1] - 1] == KILLER)
			finish_game(game, 1);
		ft_printf("Moves:\t%d\n", ++game->moves);
		game->map[game->path_start[0]][game->path_start[1] - 1] = PLAYER;
		game->map[game->path_start[0]][game->path_start[1]] = FLOOR;
		game->path_start[1]--;
	}
	move_all_killers(game);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game, 'L');
}

void	move_player(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_right(game);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move_left(game);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_up(game);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(game);
}
