/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaderboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:26:07 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/26 14:56:46 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_final_score(t_game *game)
{
	char	*moves;
	char	*coins;
	int		offset[2];

	offset[0] = game->x_offset + game->image_width - 250;
	offset[1] = game->y_offset + game->image_height - 77;
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, offset[0], offset[1],
		0x00FFFF00, moves);
	free(moves);
	offset[0] = game->x_offset + game->image_width - 250;
	offset[1] = game->y_offset + game->image_height - 27;
	coins = ft_itoa(game->coin_collected);
	mlx_string_put(game->mlx, game->win, offset[0], offset[1],
		0x00FFFF00, coins);
	free(coins);
}

void	draw_move_board(t_game *game)
{
	char	*str;
	int		offset[2];

	if (game->moves < 10)
		offset[0] = (game->x * 100) + 93;
	else
		offset[0] = (game->x * 100) + 92;
	offset[1] = 110;
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, offset[0], offset[1], 0x00FFFF00, str);
	free(str);
}

void	draw_coin_board(t_game *game)
{
	char	*str;
	int		offset[2];

	if (game->coin_collected < 10)
		offset[0] = (game->x * 100) + 85;
	else
		offset[0] = (game->x * 100) + 80;
	offset[1] = 180;
	str = ft_itoa(game->coin_collected);
	mlx_string_put(game->mlx, game->win, offset[0], offset[1], 0x00FFFF00, str);
	free(str);
}

void	draw_coin_board_max(t_game *game)
{
	char	*str;
	int		offset[2];

	offset[0] = (game->x * 100) + 115;
	offset[1] = 180;
	str = ft_itoa(game->max_coin);
	mlx_string_put(game->mlx, game->win, offset[0] - 13,
		offset[1], 0x0000FFFF, "\\ ");
	mlx_string_put(game->mlx, game->win, offset[0], offset[1], 0x0000FFFF, str);
	free(str);
}
