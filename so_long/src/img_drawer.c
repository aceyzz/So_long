/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:33:38 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/28 11:44:03 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	draw_board(t_game *game)
{
	draw_move_board(game);
	draw_coin_board(game);
	draw_coin_board_max(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_boar,
		(game->x * 100), 0);
}

static void	draw_killer(t_game *game, int i, int j, int color)
{
	if (color == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img_kil1,
			(j * 100), (i * 100));
	else if (color == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img_kil2,
			(j * 100), (i * 100));
	else if (color == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->img_kil3,
			(j * 100), (i * 100));
}

static void	draw_else(t_game *game, int i, int j)
{
	if (game->map[i][j] == ITEM)
		mlx_put_image_to_window(game->mlx, game->win, game->img_item,
			(j * 100), (i * 100));
	if (game->map[i][j] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->img_floo,
			(j * 100), (i * 100));
	if (game->map[i][j] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			(j * 100), (i * 100));
	if (game->map[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->img_excl,
			(j * 100), (i * 100));
	if (game->map[i][j] == EXIT_OK)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exop,
			(j * 100), (i * 100));
	return ;
}

static void	draw_player(t_game *game, int i, int j, char direction)
{
	if (direction == 'U')
		mlx_put_image_to_window(game->mlx, game->win, game->img_plup,
			(j * 100), (i * 100));
	else if (direction == 'L')
		mlx_put_image_to_window(game->mlx, game->win, game->img_plle,
			(j * 100), (i * 100));
	else if (direction == 'D')
		mlx_put_image_to_window(game->mlx, game->win, game->img_pldo,
			(j * 100), (i * 100));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_plri,
			(j * 100), (i * 100));
}

void	draw_map(t_game *game, char direction)
{
	int	i;
	int	j;

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
				draw_killer(game, i, j, (i + j) % 3);
			else if (game->map[i][j] == PLAYER)
				draw_player(game, i, j, direction);
			j++;
		}
		i++;
	}
}
