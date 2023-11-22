/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:45 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 12:14:17 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**parse_map(int fd)
{
	char	**map;
	char	*line;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * 1);
	if (!map)
		check_and_exit(map, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map = (char **)ft_realloc(map, sizeof(char *) * (i + 2));
		if (!map)
			check_and_exit(map, 1);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	check_and_exit(char **map, int flag)
{
	if (flag == 1)
		perror("Error:\nAllocation mémoire (map) échouée.\n");
	else
	{
		free(map);
		perror("Error:\nMap invalide.\n");
	}
	exit(1);
}

char	**get_map(char *filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error:\nOuverture de fichier.\n");
		exit(1);
	}
	map = parse_map(fd);
	if (!is_valid_map(map))
		check_and_exit(map, 0);
	close(fd);
	return (map);
}
