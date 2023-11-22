/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:02:44 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 17:10:50 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_top_bot_wall(char *border)
{
	int	i;

	i = 0;
	while (border[i] == '1' && border[i])
		i++;
	if (border[i] == '\0' || border[i] == '\n')
		return (1);
	return (0);
}

static int	is_border_valid(char *border)
{
	int	i;

	i = 0;
	while (border[i])
		i++;
	if (border[0] != '1' && border[i] != '\n' && border[i] != '\0')
		return (0);
	return (1);
}

int	is_wall_valid(t_info *info)
{
	int	i;

	i = 0;
	while (info->map_copy[i])
		i++;
	if (!is_top_bot_wall(info->map_copy[i - 1])
		|| !is_top_bot_wall(info->map_copy[0]))
		return (0);
	i = 1;
	while (info->map_copy[i + 1])
	{
		if (!is_border_valid(info->map_copy[i]))
			return (0);
		i++;
	}
	return (1);
}
