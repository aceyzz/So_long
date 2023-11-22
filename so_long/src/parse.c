/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:45 by cedmulle          #+#    #+#             */
/*   Updated: 2023/11/22 17:07:56 by cedmulle         ###   ########.fr       */
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
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map = (char **)realloc(map, sizeof(char *) * (i + 2));
		if (!map)
		{
			free(line);
			exit(1);
		}
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_tabdup(char **tab)
{
	char	**dest;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	dest = (char **)malloc(sizeof(char *) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		dest[i] = ft_strdup(tab[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**get_map(char *filename)
{
	int		fd;
	char	**map;
	t_info	info;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Ouverture de fichier.\n");
		exit(1);
	}
	map = parse_map(fd);
	(&info)->map_copy = ft_tabdup(map);
	if (!is_valid_map(&info))
	{
		perror("Erreur dans la map\n");
		exit(1);
	}
	close(fd);
	return ((&info)->map_copy);
}
