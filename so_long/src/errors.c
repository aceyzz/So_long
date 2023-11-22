/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:05 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 17:51:01 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_valid_charac(char c)
{
	if (c == 'P' || c == 'C' || c == '1' || c == '0' || c == 'x' || c == '\n')
		return (1);
	return (0);
}

static int	is_valid_string(t_info *info)
{
	int	i;
	int	k;

	i = 0;
	while (info->map_copy[i])
	{
		k = 0;
		while (info->map_copy[i][k] && is_valid_charac(info->map_copy[i][k]))
		{
			if (info->map_copy[i][k] == 'P')
			{
				info->pl_x = k;
				info->pl_y = i;
			}
			k++;
		}
		i++;
	}
	if (!info->map_copy[i])
		return (1);
	return (0);
}

static int	is_size_ok(t_info *info)
{
	int		i;

	i = 0;
	if (!info->map_copy[i])
		return (0);
	while (info->map_copy[i + 1])
	{
		if (ft_strlen(info->map_copy[i]) != ft_strlen(info->map_copy[i + 1]))
			return (0);
		i++;
	}
	info->size_x = ft_strlen(info->map_copy[i]);
	info->size_y = i - 1;
	if ((i < 3 || ft_strlen(info->map_copy[i - 1]) < 3)
		|| ((i == 3 && ft_strlen(info->map_copy[i - 1]) == 3)))
		return (0);
	else
		return (1);
}

int	is_valid_map(t_info *info)
{
	if (!is_size_ok(info)|| !is_valid_string(info)
		|| !is_wall_valid(info) || !is_item_exit(info))
	{
		//ft_printf("1: %d\n2: %d\n3: %d\n4: %d\n", is_size_ok(info), is_valid_string(info), is_wall_valid(info), is_item_exit(info));
		return (0);
	}
	return (1);
}
