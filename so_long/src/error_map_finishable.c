/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_finishable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:17:48 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 11:34:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_tab_direction(int tab[4][2])
{
	tab[0][0] = 1;
	tab[0][1] = 0;
	tab[1][0] = -1;
	tab[1][1] = 0;
	tab[2][0] = 0;
	tab[2][1] = -1;
	tab[3][0] = 0;
	tab[3][1] = 1;
}

int	is_chemin_exit(char **map, int x, int y, t_player *pl)
{
	int	i;
	int	direction[4][2];
	int	new_row;
	int	new_col;

	set_tab_direction(direction);
	while (pl->row >= 0 && pl->col >= 0 && pl->row < x && pl->col < y)
	{
		if (map[pl->row][pl->col] == 'V' || map[pl->row][pl->col] == '1')
			return (0);
		map[pl->row][pl->col] = 'V';
		if (map[pl->row][pl->col] == 'E')
			return (1);
		i = 0;
		while (i < 4)
		{
			new_row = pl->row + direction[i][0];
			new_col = pl->col + direction[i][1];
			if (is_chemin_exit(map, x, y, &(t_player){new_row, new_col}))
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
	col = 0;
	row = ft_strlen(map[0]);
	if (!pl)
		return (0);
	pl->row = 0;
	pl->col = 0;
	while (map[col])
		col++;
	find_player(map, row, col, pl);
	if (!is_item_exit(map) || !is_chemin_exit(map, row, col, pl))
	{
		free(pl);
		return (0);
	}
	free(pl);
	return (1);
}
