/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:33:38 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/26 13:49:37 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	draw_board(t_game *game)
{
	draw_move_board(game);
	draw_coin_board(game);
	game->img = mlx_xpm_file_to_image(game->mlx, "./img/board.xpm",
			&(game->size), &(game->size));
	mlx_put_image_to_window(game->mlx, game->win, game->img,
			(game->x * 100), 0);
}

static void	draw_killer(t_game *game, int i, int j, int color)
{
	if (color == 0)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/killer1.xpm",
			&game->size, &game->size);
	else if (color == 1)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/killer2.xpm",
			&game->size, &game->size);
	else if (color == 2)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/killer3.xpm",
			&game->size, &game->size);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(j * 100), (i * 100));
}

static void	draw_else(t_game *game, int i, int j)
{
	if (game->map[i][j] == ITEM)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm",
				&game->size, &game->size);
	if (game->map[i][j] == FLOOR)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm",
			&game->size, &game->size);
	if (game->map[i][j] == WALL)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm",
			&game->size, &game->size);
	if (game->map[i][j] == EXIT)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/exit_closed.xpm",
			&game->size, &game->size);
	if (game->map[i][j] == EXIT_OK)
		game->img = mlx_xpm_file_to_image(game->mlx, "./img/exit_open.xpm",
			&game->size, &game->size);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(j * 100), (i * 100));
}

static void	draw_player(t_game *game, int i, int j, char direction)
{
	char *player_image;

	if (direction == 'U')
		player_image = "img/pl_up.xpm";
	else if (direction == 'L')
		player_image = "img/pl_left.xpm";
	else if (direction == 'D')
		player_image = "img/pl_down.xpm";
	else
		player_image = "img/pl_right.xpm";
	game->img = mlx_xpm_file_to_image(game->mlx, player_image,
			&game->size, &game->size);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		(j * 100), (i * 100));
}

void	draw_map(t_game *game, char direction)
{
	int i;
	int j;

	i = 0;
	draw_board(game);
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == WALL || game->map[i][j] == FLOOR ||
					game->map[i][j] == ITEM || game->map[i][j] == EXIT
					|| game->map[i][j] == EXIT_OK)
				draw_else(game, i, j);
			else if (game->map[i][j] == KILLER)
				draw_killer(game, i, j , (i + j) % 3);
			else if (game->map[i][j] == PLAYER)
				draw_player(game, i, j, direction);
			j++;
		}
		i++;
	}
}
