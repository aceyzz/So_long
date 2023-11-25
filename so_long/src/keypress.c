/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:05:07 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/25 16:12:27 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ENTER && game->started == 0)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_clear_window(game->mlx, game->win);
		game->started = 1;
		draw_map(game);
	}
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_free_info(game);
		exit(0);
	}
	return (0);
}
