/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:02:44 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 11:35:40 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_top_bot_wall(char *border)
{
	int	i;

	i = 0;
	while (border[i] == '1' && border[i])
		i++;
	if (border[i] == '\0')
		return (1);
	return (0);
}

static int	is_border_valid(char *border)
{
	int	i;

	i = 0;
	while (border[i])
		i++;
	if (border[i - 1] != '1' || border[0] != '1')
		return (0);
	return (1);
}

int	is_wall_valid(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (!is_top_bot_wall(map[i - 1]) || !is_top_bot_wall(map[0]))
		return (0);
	i = 1;
	while (map[i + 1])
	{
		if (!is_border_valid(map[i]) || map[i][0] != '1'
			|| map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
