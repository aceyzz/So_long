/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_item_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:30:35 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 11:35:33 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int is_chemin_item(char **map, int x, int y, t_player *pl)
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
		if (map[pl->row][pl->col] == 'C')
			return (1);
		i = 0;
		while (i < 4)
		{
			new_row = pl->row + direction[i][0];
			new_col = pl->col + direction[i][1];
			if (is_chemin_item(map, x, y, &(t_player){new_row, new_col}))
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_path_items(char **map, int nb_item)
{
	t_player	*pl;
	int			s_x;
	int			s_y;

	s_x = 0;
	s_y = ft_strlen(map[s_x]);
	while (map[s_x])
		s_x++;
	pl = malloc(sizeof(t_player));
	if (!pl)
		return (0);
	pl->row = 0;
	pl->col = 0;
	while (nb_item > 0)
	{
		if (!is_chemin_item(map, s_x, s_y, pl))
		{
			free(pl);
			return (0);
		}
		nb_item--;
	}
	free(pl);
	return (1);
}

int	is_item_exit(char **map)
{
	int	i;
	int	k;
	int	flag_c;
	int	flag_e;

	i = 0;
	flag_e = 0;
	flag_c = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'C')
				flag_c++;
			if (map[i][k] == 'E')
				flag_e++;
			k++;
		}
		i++;
	}
	if (flag_c > 0 && flag_e == 1 && is_path_items(map, flag_c))
		return (1);
	return (0);
}
