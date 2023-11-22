/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:05 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 12:14:15 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_valid_charac(char c)
{
	if (c == 'P' || c == 'C' || c == '1' || c == '0' || c == 'x' || c == '\n')
		return (1);
	return (0);
}

static int	is_valid_string(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k] && is_valid_charac(map[i][k]))
			k++;
		i++;
	}
	if (!map[i])
		return (1);
	return (0);
}

static int	is_size_ok(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i - 1]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	if ((i < 3 || ft_strlen(map[i - 1]) < 3)
		|| ((i == 3 && ft_strlen(map[i] == 3))))
		return (0);
	else
		return (1);
}

int	is_valid_map(char **map)
{
	if (!is_size_ok(map)|| !is_valid_string(map) || !is_wall_valid(map)
		|| !is_item_exit(map))
		return (0);
	if (!is_finishable(map))
		return (0);
	return (1);
}
