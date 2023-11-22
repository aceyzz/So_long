/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_item_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:30:35 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 18:06:36 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_valid_ways(int y, int x, t_info *info)
{
	int	res;

	res = 0;
	if (y >= info->size_y || x >= info->size_x || y <= 0 || x <= 0
		|| info->map_copy[y][x] == '1' || info->map_copy[y][x] == '2')
		return (0);
	else if (info->map_copy[y][x] == 'E')
		return (1);
	else if (info->map_copy[y][x] == 'C')
	{
		info->map_copy[y][x] = '0';
		x = info->pl_x;
		y = info->pl_y;
		info->nb_coin--;
	}
	info->map_copy[y][x] = '2';
	res += is_valid_ways(y, x + 1, info);
	res += is_valid_ways(y, x - 1, info);
	res += is_valid_ways(y + 1, x, info);
	res += is_valid_ways(y - 1, x, info);
	return (res);
}
/*
static int	is_way(int y, int x, int *coin, t_game *info)
{
	int	res;

	res = 0;
	if (y >= info->y || x >= info->x || y < 0 || x < 0
		|| info->map_copy[y][x] == '1' || info->map_copy[y][x] == '2')
		return (0);
	else if (info->map_copy[y][x] == 'E')
		return (1);
	else if (info->map_copy[y][x] == 'C')
		*coin += 1;
	info->map_copy[y][x] = '2';
	res += is_way(y + 1, x, coin, info);
	res += is_way(y - 1, x, coin, info);
	res += is_way(y, x + 1, coin, info);
	res += is_way(y, x - 1, coin, info);
	return (res);
}
*/
int	is_item_exit(t_info *info)
{
	int	i;
	int	k;

	i = 0;
	info->nb_exit = 0;
	info->nb_coin = 0;
	while (info->map_copy[i])
	{
		k = 0;
		while (info->map_copy[i][k])
		{
			if (info->map_copy[i][k] == 'C')
				(info)->nb_coin++;
			if (info->map_copy[i][k] == 'E')
				(info)->nb_exit++;
			k++;
		}
		i++;
	}
	if (info->nb_coin > 0 && info->nb_exit == 1)
	{
		info->copy_coin = info->nb_coin;
		ft_printf("coin : %d\n", info->nb_coin);
		ft_printf("copy : %d\n", info->copy_coin);
		if (is_valid_ways(info->pl_y, info->pl_x, info))
		{
			ft_printf("Oui\n");
			return (1);
		}
		ft_printf("coin : %d\n", info->nb_coin);
		ft_printf("copy : %d\n", info->copy_coin);
	}
	ft_printf("Non\n");
	return (0);
}
