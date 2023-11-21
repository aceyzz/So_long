/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_finishable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:17:48 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/21 18:39:16 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_chemin_exit(char **map, int x, int y, t_player *pl)
{
	int	i;
	int	direction[4][2];

	direction = {{1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (pl->row >= 0 && pl->col >= 0 && pl->row < x && pl->col < y)
	{
		if (map[pl->row][pl->col] == 'V' || map[pl->row][pl->col])
			return (0);
		map[pl->row][pl->col] = 'V';
		if (map[pl->row][pl->col] == 'E')
			return (1);
		i = 0;
		while (i < 4)
		{
			pl->row = pl->row + direction[i][0];
			pl->col = pl->col + direction[i][1];
			if (is_chemin_exit(map, x, y, pl))
				return (1);
			i++;
		}
		return (0);
	}
}

int	find_player(char **map, int x, int y, t_player *pl)
{
	int	current_row;
	int	current_col;

	current_row = 0;
	while (current_row < x)
	{
		current_col = 0;
		while (current_col < y)
		{
			if (map[current_row][current_col] == 'P')
			{
				pl->row = current_row;
				pl->col = current_col;
				return (1);
			}
			current_col++;
		}
		current_row++;
	}
	return (0);
}

int	is_finishable(char **map)
{
	int			row;
	int			col;
	t_player	*pl;

	pl = malloc(sizeof(t_player));
	if (!pl)
		return (0);
	row = ft_strlen(map[0]);
	col = 0;
	pl->row = 0;
	pl->col = 0;
	while (map[col])
		col++;
	find_player(map, row, col, pl);
	return (is_chemin_exit(map, row, col, pl));
}
