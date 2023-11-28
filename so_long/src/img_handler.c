/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:07:45 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/28 11:44:59 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	set_small_img(t_game *game)
{
	game->img_plup = mlx_xpm_file_to_image(game->mlx, "./img/pl_up.xpm",
			&(game->size), &(game->size));
	game->img_pldo = mlx_xpm_file_to_image(game->mlx, "./img/pl_down.xpm",
			&(game->size), &(game->size));
	game->img_plri = mlx_xpm_file_to_image(game->mlx, "./img/pl_right.xpm",
			&(game->size), &(game->size));
	game->img_plle = mlx_xpm_file_to_image(game->mlx, "./img/pl_left.xpm",
			&game->size, &game->size);
	game->img_kil1 = mlx_xpm_file_to_image(game->mlx, "./img/killer1.xpm",
			&game->size, &game->size);
	game->img_kil2 = mlx_xpm_file_to_image(game->mlx, "./img/killer2.xpm",
			&game->size, &game->size);
	game->img_kil3 = mlx_xpm_file_to_image(game->mlx, "./img/killer3.xpm",
			&game->size, &game->size);
	game->img_floo = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm",
			&game->size, &game->size);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm",
			&game->size, &game->size);
	game->img_item = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm",
			&game->size, &game->size);
	game->img_exop = mlx_xpm_file_to_image(game->mlx, "./img/exit_open.xpm",
			&game->size, &game->size);
	game->img_excl = mlx_xpm_file_to_image(game->mlx, "./img/exit_closed.xpm",
			&game->size, &game->size);
}

void	set_images(t_game *game)
{
	game->img_boar = mlx_xpm_file_to_image(game->mlx, "./img/board.xpm",
			&(game->size), &(game->size));
	game->img_swin = mlx_xpm_file_to_image(game->mlx, "./img/win.xpm",
			&(game->size), &(game->size));
	game->img_lose = mlx_xpm_file_to_image(game->mlx, "./img/lose.xpm",
			&(game->size), &(game->size));
	game->img_load = mlx_xpm_file_to_image(game->mlx, "./img/loading.xpm",
			&(game->size), &(game->size));
	set_small_img(game);
}

void	images_cleaner(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_plup);
	mlx_destroy_image(game->mlx, game->img_pldo);
	mlx_destroy_image(game->mlx, game->img_plle);
	mlx_destroy_image(game->mlx, game->img_plri);
	mlx_destroy_image(game->mlx, game->img_kil1);
	mlx_destroy_image(game->mlx, game->img_kil2);
	mlx_destroy_image(game->mlx, game->img_kil3);
	mlx_destroy_image(game->mlx, game->img_floo);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_item);
	mlx_destroy_image(game->mlx, game->img_excl);
	mlx_destroy_image(game->mlx, game->img_exop);
	mlx_destroy_image(game->mlx, game->img_boar);
	mlx_destroy_image(game->mlx, game->img_swin);
	mlx_destroy_image(game->mlx, game->img_lose);
	mlx_destroy_image(game->mlx, game->img_load);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
}
