/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:07 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/27 14:21:52 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ENTER && game->started == 0 && game->finished == 0)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_clear_window(game->mlx, game->win);
		game->started = 1;
		draw_map(game, 'Q');
	}
	if (keycode == KEY_ESCAPE)
	{
		ft_free_info(game);
		exit(0);
	}
	if (game->started == 1 && game->finished == 0)
	{
		if (keycode == KEY_RIGHT || keycode == KEY_LEFT
			|| keycode == KEY_UP || keycode == KEY_DOWN)
			move_player(keycode, game);
	}
	return (0);
}
