/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:27:48 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/25 16:02:53 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	get_size(t_game *info)
{
	char	*line;
	int		i;

	line = get_next_line(info->fd);
	while (line)
	{
		i = 0;
		while (line[i])
			i++;
		if (info->x != i && info->y != 0)
			return (ft_error(4));
		info->x = i;
		info->y++;
		line = get_next_line(info->fd);
	}
	if ((info->x < 3 || info->y < 3) || (info->x + info->y) < 7)
		return (ft_error(5));
	if (info->x == info->y)
		return (ft_error(4));
	close(info->fd);
	info->fd = open(info->name_map, O_RDONLY);
	return (1);
}

static int	is_valid_charac(t_game *info, int i, int j)
{
	if ((i == 0 || i == info->y - 1 || j == 0 || j == info->x - 1)
		&& info->map[i][j] != '1')
		return (ft_error(6));
	else if (i != 0 && i != info->y - 1 && j != 0 && j != info->x - 1
		&& info->map[i][j] != '1' && info->map[i][j] != '0'
		&& info->map[i][j] != 'E' && info->map[i][j] != 'P'
		&& info->map[i][j] != 'C' && info->map[i][j] != 'x')
		return (ft_error(7));
	if (info->map[i][j] == 'P')
	{
		info->path_start[0] = i;
		info->path_start[1] = j;
	}
	else if (info->map[i][j] == 'E')
	{
		info->path_end[0] = i;
		info->path_end[1] = j;
	}
	return (1);
}

static int	is_valid_map(t_game *info, int p, int c, int e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->y)
	{
		j = -1;
		while (++j < info->x)
		{
			if (!is_valid_charac(info, i, j))
				return (0);
			if (info->map[i][j] == 'E')
				e++;
			else if (info->map[i][j] == 'C')
				c++;
			else if (info->map[i][j] == 'P')
				p++;
		}
	}
	if (e != 1 || p != 1 || c < 1)
		return (ft_error(8));
	info->max_coin = c;
	return (1);
}

static int	path_ok(int y, int x, int *coin, t_game *info)
{
	int	res;

	res = 0;
	if (y >= info->y || x >= info->x || y < 0 || x < 0
		|| info->map_copy[y][x] == '1' || info->map_copy[y][x] == '2')
		return (0);
	else if (info->map_copy[y][x] == 'E')
		return (1);
	else if (info->map_copy[y][x] == 'C')
		(*coin)++;
	info->map_copy[y][x] = '2';
	res += path_ok(y + 1, x, coin, info);
	res += path_ok(y - 1, x, coin, info);
	res += path_ok(y, x + 1, coin, info);
	res += path_ok(y, x - 1, coin, info);
	return (res);
}

int	parse_map(t_game *info)
{
	int	i;

	i = -1;
	if (!get_size(info))
		return (0);
	info->map = malloc(sizeof(char *) * (info->y + 1));
	info->map_copy = malloc(sizeof(char *) * (info->y + 1));
	if (!info->map || !info->map_copy)
		return (ft_error(9));
	info->map[info->y] = NULL;
	info->map_copy[info->y] = NULL;
	while (++i < info->y)
		info->map[i] = get_next_line(info->fd);
	i = -1;
	close(info->fd);
	info->fd = open(info->name_map, O_RDONLY);
	while (++i < info->y)
		info->map_copy[i] = get_next_line(info->fd);
	if (!is_valid_map(info, 0, 0, 0))
		return (ft_free_info(info));
	if (!path_ok(info->path_start[0], info->path_start[1], &info->coin, info))
		return (ft_error(3) + ft_free_info(info));
	if (info->coin != info->max_coin)
		return (ft_error(10) + ft_free_info(info));
	return (1);
}
