/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:54:38 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/27 14:49:35 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	free_killers(t_game *game)
{
	int	i;

	i = 0;
	while (game->tab_killers[i])
	{
		free(game->tab_killers[i]);
		i++;
	}
	free(game->tab_killers);
}

int	ft_free_info(t_game *info)
{
	if (info->map)
		free_tab(info->map);
	if (info->map_copy)
		free_tab(info->map_copy);
	if (info->tab_killers)
		free_killers(info);
	if (info->mlx)
	{
		if (info->win)
			mlx_destroy_window(info->mlx, info->win);
		free(info->mlx);
	}
	close(info->fd);
	return (0);
}
