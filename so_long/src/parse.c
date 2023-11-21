/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:45 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/21 15:24:41 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**parse_map(int fd)
{
	char	**map;
	int		i;

	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	if (!is_valid_map(map))
	{
		perror("Error:\nMap invalide.\n");
		exit(1);
	}
	return (map);
}

char	**get_map(char *filename)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error:\nOuverture de fichier.\n");
		exit(1);
	}
	map = (char**)malloc(sizeof(char*) + 1);
	if (!map)
	{
		perror("Error:\nAllocation mémoire (map) échouée.\n");
		exit(1);
	}
	return (parse_map(fd));
}
