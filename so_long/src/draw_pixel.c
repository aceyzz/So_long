/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:26:07 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/26 13:45:43 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_move_board(t_game *game)
{
	char	*str;
	int		offset[2];

	if (game->moves < 100)
		offset[0] = (game->x * 100) + 96;
	else
		offset[0] = (game->x * 100) + 95;
	offset[1] = 110;
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, offset[0], offset[1], 0x00FFFF00, str);
	free(str);
}

void	draw_coin_board(t_game *game)
{
	char	*str;
	int		offset[2];

	if (game->coin_collected < 100)
		offset[0] = (game->x * 100) + 96;
	else
		offset[0] = (game->x * 100) + 95;
	offset[1] = 180;
	str = ft_itoa(game->coin_collected);
	mlx_string_put(game->mlx, game->win, offset[0], offset[1], 0x00FFFF00, str);
	free(str);
}
